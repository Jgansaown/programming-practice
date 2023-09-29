// // Object Oriented Programming in C - Polymorphic Types

// #include <stdlib.h>

#include "shape.h"

void Shape__print(struct Shape *self) { self->vtable->print(self); }
int Shape__sides(Shape *self) { return self->sides; }

// typedef struct Shape Shape;
// typedef struct ShapeType ShapeType;

// struct ShapeType {
//   const char *(*name)(Shape *);
//   int (*sides)(Shape *);
//   void (*free)(Shape *);
// };

// struct Shape {
//   ShapeType *type;
// };

// ShapeType *ShapeType__new(const char *(*name)(Shape *), int (*sides)(Shape
// *),
//                           void (*free)(Shape *)) {
//   ShapeType *ret = malloc(sizeof(*ret));
//   if (ret == NULL)
//     return NULL;
//   ret->name = name;
//   ret->sides = sides;
//   ret->free = free;
//   return ret;
// }

// Shape *Shape__new(ShapeType *type) {
//   Shape *ret = malloc(sizeof(*ret));
//   ret->type = type;
//   return ret;
// }

// const char *Shape__name(Shape *self) { return self->type->name(self); }
// int Shape__sides(Shape *self) { return self->type->sides(self); }
// void Shape__free(Shape *self) { return self->type->free(self); }
