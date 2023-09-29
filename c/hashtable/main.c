#include "lib/hash.h"
#include <stdio.h>

int main() {
  struct ht *table = ht_new(1);

  const char *v;

  v = ht_get(table, "a");
  printf("key: a, value: %s, %d\n", v, table->size);

  ht_set(table, "a", "1");

  v = ht_get(table, "a");
  printf("key: a, value: %s, %d\n", v, table->size);

  
  ht_set(table, "a", "2");
  ht_set(table, "b", "2");
  ht_set(table, "c", "2");
  ht_set(table, "d", "2");
  ht_set(table, "e", "2");
  ht_set(table, "f", "2");
  ht_set(table, "g", "2");

  v = ht_get(table, "a");
  printf("key: a, value: %s, %d\n", v, table->size);

  ht_del(table, "a");

  v = ht_get(table, "a");
  printf("key: a, value: %s, %d\n", v, table->size);

  ht_free(table);

  return 0;
}