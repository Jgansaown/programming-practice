#import <stdio.h>
#import <stdlib.h>

#import "shape.h"
#import "triangle.h"


int main() {
  struct Triangle *tri = Triangle__new();

  Shape__print((Shape *)tri);

  printf("Sides: %d\n", Shape__sides((Shape *)tri));
  free(tri);

  return 0;
}