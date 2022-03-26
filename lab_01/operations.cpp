#include <cmath>

#include "operations.h"
#include "error_handler.h"

void move_to_origin(point_t& point, const point_t& center)
{
    move_t coords;

    coords.dx = -center.x;
    coords.dy = -center.y;
    coords.dz = -center.z;

    move_point(point, coords);
}

void move_to_center(point_t& point, const point_t& center)
{
    move_t coords;

    coords.dx = center.x;
    coords.dy = center.y;
    coords.dz = center.z;

    move_point(point, coords);
}

void move_point(point_t& point, move_t coef)
{
    point.x += coef.dx;
    point.y += coef.dy;
    point.z += coef.dz;
}

errors move_points(points_t& pts, move_t coef)
{
    if (!pts.arr)
        return ERROR_NO_DOTS;

    errors err = NONE;

    for (size_t i = 0; i < pts.n; i++)
        move_point(pts.arr[i], coef);

    return err;
}

void scale_point(point_t& point, scale_t coef, const point_t& center)
{
    point.x *= coef.kx + (1 - coef.kx) * center.x;
    point.y *= coef.ky + (1 - coef.ky) * center.y;
    point.z *= coef.kz + (1 - coef.kz) * center.z;
}

point_t get_scale_center(scale_t& coef)
{
    return coef.center;
}

errors scale_points(points_t& pts, scale_t coef)
{
    if (!pts.arr)
        return ERROR_NO_DOTS;

    errors err = NONE;

    for (size_t i = 0; i < pts.n; i++)
        scale_point(pts.arr[i], coef, get_scale_center(coef));

    return err;
}

double d_cos(double angle)
{
    return cos(angle * 3.1415 / 180);
}

double d_sin(double angle)
{
    return sin(angle * 3.1415 / 180);
}

void x_turn_point(point_t& point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    point.y = point.y + cos_ang + point.z * sin_ang;
    point.z = -point.y * sin_ang + point.z * cos_ang;
}

void y_turn_point(point_t& point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    point.x = point.x * cos_ang + point.z * sin_ang;
    point.z = -point.x * sin_ang + point.z * cos_ang;
}

void z_turn_point(point_t& point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    point.x = point.x * cos_ang + point.y * sin_ang;
    point.y = -point.x * sin_ang + point.y * cos_ang;
}

errors turn_points(points_t& pts, turn_t coef)
{
    if (!pts.arr)
        return ERROR_NO_DOTS;

    errors err = NONE;

    for (size_t i = 0; i < pts.n; i++)
    {
        move_to_origin(pts.arr[i], coef.center);

        x_turn_point(pts.arr[i], coef.ox);
        y_turn_point(pts.arr[i], coef.oy);
        z_turn_point(pts.arr[i], coef.oz);

        move_to_center(pts.arr[i], coef.center);
    }

    return err;
}
