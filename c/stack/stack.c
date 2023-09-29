#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* struct node */
struct stack_node {
  void *val;
  struct stack_node *next;
};

struct stack_node *stack_node_new(void *val, struct stack_node *next) {
  struct stack_node *n = NULL;
  n = (struct stack_node *)malloc(sizeof(*n));
  n->val = val;
  n->next = next;
  return n;
}
/* memory leak if user dont free val*/
void stack_node_free(struct stack_node *node) { free(node); }

/* struct */
struct stack {
  uint8_t len;

  struct stack_node *head;
};

struct stack *stack_new() {
  struct stack *s = NULL;
  s = (struct stack *)calloc(1, sizeof(*s));
  return s;
}

void stack_push(struct stack *self, void *val) {
  struct stack_node *n = NULL;
  n = stack_node_new(val, self->head);

  self->head = n;
  self->len += 1;
}

void *stack_pop(struct stack *self) {
  void *val = NULL;
  struct stack_node *n = NULL;

  if (self->head != NULL) {
    n = self->head;
    self->head = self->head->next;

    val = n->val;

    stack_node_free(n);
    self->len -= 1;
  }
  return val;
}

void *stack_peak(struct stack *self) {
  if (self->head != NULL) {
    return self->head->val;
  }
  return NULL;
}

void stack_free(struct stack *self) {
  while (self->head != NULL) {
    stack_pop(self);
  }
  free(self);
}

void stack_print_int(struct stack *self) {
  struct stack_node *n = self->head;

  printf("[");
  while (n != NULL && n->next != NULL) {
    printf("%d, ", *(int *)(n->val));
    n = n->next;
  }
  printf("%d]\n", *(int *)(n->val));
}