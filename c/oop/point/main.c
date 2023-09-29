#import <stdio.h>
#import <stdlib.h>

#import "point.h"

// #import "shape.h"
// #import "triangle.h"

void print_point(int x, int y) {
  Point *p = Point__new(x, y);
  Point__print(p);
  Point__free(p);
}

int main() {
  print_point(10, 11);

  // struct Shape triangle = {TRIANGLE};
  // const char *name = Shape__name(&triangle);
  // printf("shape name: %s\n", name);

  // struct Triangle *tri = Triangle__new();

  // Shape__print((Shape *)tri);

  // printf("Sides: %d\n", Shape__sides((Shape *)tri));
  // free(tri);

  return 0;
}