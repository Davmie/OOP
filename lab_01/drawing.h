#ifndef DRAWING_H
#define DRAWING_H

#include <QGraphicsView>

#include "graph.h"
#include "points.h"
#include "edges.h"

typedef struct
{
    int x;
    int y;
}
coord_point_t;

coord_point_t get_coord_point(point_t *begin_point, size_t n);
coord_point_t transform_coord_point(coord_point_t p, canvas_t canvas);
void draw_edges(points_t pts, edges_t edges, canvas_t canvas, graphics_t a);
void draw_line(coord_point_t p1, coord_point_t p2, graphics_t a, canvas_t canvas);
void my_addLine(graphics_t a, int x1, int x2, int y1, int y2);

#endif // DRAWING_H
