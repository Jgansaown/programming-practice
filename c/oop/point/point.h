#ifndef __POINT_H
#define __POINT_H 1

typedef struct Point Point;

Point *Point__new(int x, int y);
void Point__free(Point *self);
int Point__x(Point *self);
int Point__y(Point *self);
void Point__print(Point *self);

#endif