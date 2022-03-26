#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include "error_handler.h"

typedef struct
{
    double x;
    double y;
    double z;
}
point_t;

errors read_point(point_t *dot, FILE *f);

#endif // POINT_H
