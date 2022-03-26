#include "points.h"
#include "io.h"

points_t& init_points()
{
    points_t *points = new points_t;

    points->n = 0;
    points->arr = nullptr;

    return *points;
}

errors alloc_points(points_t& pts, size_t len)
{
    if (!len)
        return ERROR_NO_EDGES;

    pts.n = len;

    pts.arr = new point_t[len];

    if (!pts.arr)
        return ERROR_PTR_ALL;

    return NONE;
}

void free_points(points_t& pts)
{
    delete[] pts.arr;

    delete &pts;
}

errors read_points(points_t &pts, FILE *f)
{
    errors err = NONE;

    for (size_t i = 0; !err && i < pts.n; i++)
        if (read_point(&pts.arr[i], f))
            err = ERROR_FILE_FORMAT;

    return err;
}

errors process_points(points_t& pts, FILE *f)
{
    size_t n;
    errors err = read_amount(&n, f);

    if (err)
        return err;

    err = alloc_points(pts, n);

    if (err == NONE)
    {
        if ((err = read_points(pts, f)) == ERROR_FILE_FORMAT)
            free_points(pts);
    }

    return err;
}
