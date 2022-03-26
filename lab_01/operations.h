#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "points.h"

typedef struct
{
    int dx;
    int dy;
    int dz;
}
move_t;

typedef struct
{
    point_t center;
    double kx;
    double ky;
    double kz;
}
scale_t;

typedef struct
{
    point_t center;
    int ox;
    int oy;
    int oz;
}
turn_t;

point_t get_scale_center(scale_t& coef);

void move_point(point_t& point, move_t coef);
errors move_points(points_t& pts, move_t coef);

void scale_point(point_t& point, scale_t coef, const point_t& center);
errors scale_points(points_t& pts, scale_t coef);

double d_cos(double angle);
double d_sin(double angle);

void x_turn_point(point_t& point, double angle);
void y_turn_point(point_t& point, double angle);
void z_turn_point(point_t& point, double angle);
errors turn_points(points_t& pts, turn_t coef);

#endif // OPERATIONS_H
