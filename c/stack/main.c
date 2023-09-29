#include "stack.h"
#include <stdio.h>

int main() {
  struct stack *s = stack_new();

  int a = 10;
  stack_push(s, &a);
  printf("top: %d\n", *(int *)(stack_peak(s)));

  int b = 100;
  stack_push(s, &b);
  printf("top: %d\n", *(int *)(stack_peak(s)));

  void *ptr = NULL;

  // ptr = stack_pop(s);
  // printf("popped: %d\n", *(int *)(ptr));

  // ptr = stack_pop(s);
  // printf("popped: %d\n", *(int *)(ptr));
  stack_print_int(s);
  
  printf("hello world\n");

  stack_free(s);

  return 0;
}