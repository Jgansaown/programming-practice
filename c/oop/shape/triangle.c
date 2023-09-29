#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

struct Triangle {
  Shape super;
};

const char *Triangle__name(void) { return "Triangle"; }
// int Triangle__sides(Shape *self) { return 3; }
// void Triangle__free(Shape *self) { free(self); }

void Triangle__print(struct Shape *self) {
  struct Triangle *tri = (struct Triangle *)self;
  printf("Triangle{sides=%d}\n", self->sides);
}

const struct Shape_vtable TRIANGLE[] = {
    {.name = Triangle__name, .print = Triangle__print}};

struct Triangle *Triangle__new() {
  struct Triangle *ret = malloc(sizeof(*ret));
  Shape super = {.sides = 3, .vtable = TRIANGLE};
  ret->super = super;
  return ret;
}
