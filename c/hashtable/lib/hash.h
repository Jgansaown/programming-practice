
struct ht {
  int base_size;
  int size;
  int count;
  struct ht_item **items;
};

struct ht *ht_new(int size);
void ht_free(struct ht *self);

const char *ht_get(struct ht *self, const char *key);
void ht_set(struct ht *self, const char *key, const char *value);
void ht_del(struct ht *self, const char *key);
