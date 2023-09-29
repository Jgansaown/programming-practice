// Object Oriented Programming in C - Non-Polymorphic Types

#import <stdio.h>
#import <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

Point *Point__new(int x, int y) {
  Point *p = malloc(sizeof(*p));
  p->x = x;
  p->y = y;
  return p;
}
void Point__free(Point *self) { free(self); }
int Point__x(Point *self) { return self->x; }
int Point__y(Point *self) { return self->y; }
void Point__print(Point *self) {
  printf("Point{x: %d, y: %d}\n", self->x, self->y);
}
