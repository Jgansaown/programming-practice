#ifndef _STACK_H
#define _STACK_H 1

struct stack;
struct stack *stack_new();
void stack_push(struct stack *self, void *val);
void *stack_pop(struct stack *self);
void *stack_peak(struct stack *self);
void stack_free(struct stack *self);

void stack_print_int(struct stack *self);

#endif