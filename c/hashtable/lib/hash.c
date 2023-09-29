#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "prime.h"

/* */

#define HT_PRIME1 10
#define HT_PRIME2 10

static size_t hash(const char *str, int prime, int num_buckets) {
  size_t hash = 0;
  size_t len = strlen(str);

  for (size_t i = 0; i < len; i++) {
    hash += (size_t)pow(prime, len - i + 1) * str[i];
    hash = hash % num_buckets;
  }
  return hash;
}

static int ht_get_hash(const char *str, const int num_buckets,
                       const int attempt) {
  const size_t hash_a = hash(str, HT_PRIME1, num_buckets);
  const size_t hash_b = hash(str, HT_PRIME2, num_buckets);
  return (hash_a + attempt * (hash_b + 1)) % num_buckets;
}

/* */

struct ht_item {
  char *key;
  char *value;
};

static struct ht_item *ht_item_new(const char *k, const char *v) {
  struct ht_item *item = malloc(sizeof(*item));
  item->key = strdup(k);
  item->value = strdup(v);
  return item;
}

static void ht_item_free(struct ht_item *item) {
  free(item->key);
  free(item->value);
  free(item);
}

/* */

// global sentinel item
static struct ht_item HT_DELETED_ITEM = {NULL, NULL};

static struct ht_item **ht_get_hash_item(struct ht *self, const char *key,
                                         int attempt) {
  size_t hash = ht_get_hash(key, self->size, attempt);
  return &self->items[hash];
}

struct ht *ht_new(int size) {
  struct ht *self = malloc(sizeof(*self));
  self->base_size = next_prime(size);
  self->size = self->base_size;
  self->count = 0;
  self->items = calloc(self->size, sizeof(struct ht_item *));
  return self;
}

static void ht_resize_if_needed(struct ht *self) {
  if (self->size <= self->base_size) {
    return;
  }

  int new_size;
  float ratio = (float)self->count / (float)self->size;
  if (ratio > 0.5) {
    // resize up
    new_size = next_prime(self->size * 2);
  } else if (ratio < 0.1) {
    // resize down
    new_size = next_prime(self->size * 2);
  } else {
    // dont need to resize
    return;
  }

  struct ht

  int old_size = self->size;
  struct ht_item **old_items = self->items;

  float ratio = (float)self->count / (float)self->size;

  if (ratio > 0.5) { // resize up
    self->size = next_prime(self->size * 2);
  } else if (ratio < 0.1) { // resize down
    self->size = next_prime(self->size * 2);
  } else { // dont need to resize
    return;
  }
  self->count = 0;
  self->items = calloc(self->size, sizeof(struct ht_item *));

  for (int i = 0; i < old_size; i++) {
    if (old_items[i] == NULL || old_items[i] == &HT_DELETED_ITEM) {
      continue;
    }
    // TODO: optimize so don't need to copy
    ht_set(self, old_items[i]->key, old_items[i]->value);
    ht_item_free(old_items[i]);
  }
}

void ht_free(struct ht *table) {
  for (int i = 0; i < table->size; i++) {
    if (table->items[i] != NULL && table->items[i] != &HT_DELETED_ITEM) {
      ht_item_free(table->items[i]);
    }
  }
  free(table->items);
  free(table);
}

const char *ht_get(struct ht *self, const char *key) {
  struct ht_item **item = ht_get_hash_item(self, key, 0);

  for (int i = 1; *item != NULL; i++) {
    if (*item != &HT_DELETED_ITEM) {
      if (strcmp((*item)->key, key) == 0) {
        return (*item)->value;
      }
    }
    item = ht_get_hash_item(self, key, i);
  }
  return NULL;
}

void ht_set(struct ht *self, const char *key, const char *value) {
  // look for empty bucket in table
  struct ht_item **item = ht_get_hash_item(self, key, 0);

  for (int i = 1; *item != NULL; i++) {
    if (*item == &HT_DELETED_ITEM) {
      break;
    }
    // handle updating value (same key)
    if (strcmp((*item)->key, key) == 0) {
      ht_item_free(*item);
      *item = ht_item_new(key, value);
      return;
    }
    item = ht_get_hash_item(self, key, i);
  }

  *item = ht_item_new(key, value);
  self->count++;

  ht_resize_if_needed(self);
}

void ht_del(struct ht *self, const char *key) {
  struct ht_item **item = ht_get_hash_item(self, key, 0);

  for (int i = 1; *item != NULL; i++) {
    if (*item != &HT_DELETED_ITEM) {
      if (strcmp((*item)->key, key) == 0) {
        ht_item_free(*item);
        *item = &HT_DELETED_ITEM;
        self->count--;
        break;
      }
    }
    item = ht_get_hash_item(self, key, i);
  }

  ht_resize_if_needed(self);
}
