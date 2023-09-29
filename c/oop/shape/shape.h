#ifndef __SHAPE_H
#define __SHAPE_H 1

// Object Oriented Programming in C - Polymorphic Types

typedef struct Shape {
  const struct Shape_vtable *vtable;
  int sides;
} Shape;

struct Shape_vtable {
  const char *(*name)(void);
  void (*print)(struct Shape *self);
};

static inline const char *Shape__name(struct Shape *self) {
  return self->vtable->name();
}

void Shape__print(struct Shape *self);
int Shape__sides(Shape *self);


#endif