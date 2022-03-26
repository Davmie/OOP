#include "drawing.h"
#include "graph.h"

coord_point_t get_coord_point(point_t *begin_point, size_t n)
{
    coord_point_t dot = {static_cast<int>(begin_point[n].x), static_cast<int>(begin_point[n].y)};
    return dot;
}

coord_point_t transform_coord_point(coord_point_t p, canvas_t canvas)
{
    coord_point_t tmp;

    tmp.x = p.x + canvas.w/2;
    tmp.y = p.y + canvas.h/2;

    return tmp;
}

void draw_edges(points_t pts, edges_t edges, canvas_t canvas, graphics_t a)
{
    coord_point_t p1, p2;

    for (size_t i = 0; i < edges.n; i++)
    {
        p1 = get_coord_point(pts.arr, edges.arr[i].p1);
        p2 = get_coord_point(pts.arr, edges.arr[i].p2);
        draw_line(p1, p2, a, canvas);
    }
}

void draw_line(coord_point_t p1, coord_point_t p2, graphics_t a, canvas_t canvas)
{
    p1 = transform_coord_point(p1, canvas);
    p2 = transform_coord_point(p2, canvas);

    my_addLine(a, p1.x, p2.x, p1.y, p2.y);
}

void my_addLine(graphics_t a, int x1, int x2, int y1, int y2)
{
    a.scene->addLine(x1, y1, x2, y2, a.pen);
}

