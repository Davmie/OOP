#include <cstdio>

#include "point.h"
#include "error_handler.h"

errors read_point(point_t* dot, FILE *f)
{
    if (fscanf(f, "%lf%lf%lf", &dot->x, &dot->y, &dot->z) != 3)
        return ERROR_FILE_FORMAT;

    return NONE;
}
