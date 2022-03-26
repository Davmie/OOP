#ifndef POINTS_H
#define POINTS_H

#include "point.h"

typedef struct
{
    size_t n;
    point_t *arr;
}
points_t;

points_t& init_points();

errors alloc_points(points_t& pts, size_t len);
void free_points(points_t& pts);

void copy_points(points_t&dst, points_t&src);

errors read_points(points_t &pts, FILE *f);
errors process_points(points_t &pts, FILE *f);

#endif //POINTS_H
