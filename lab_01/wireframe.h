#ifndef WIREFRAME_H
#define WIREFRAME_H

#include "point.h"
#include "edges.h"
#include "drawing.h"
#include "operations.h"
#include "error_handler.h"

typedef struct
{
    points_t *points;
    edges_t *edges;
}
wireframe_t;

wireframe_t init_wireframe();

points_t& get_points(wireframe_t& frame);
edges_t& get_edges(wireframe_t& frame);

void free_wireframe(wireframe_t& frame);
void copy_wireframe(wireframe_t& frame, wireframe_t& tmp_frame);
errors fread_wireframe(wireframe_t& ob, const char *filename);

errors draw_wireframe(wireframe_t frame, canvas_t canvas);

errors move_wireframe(wireframe_t& frame, move_t coef);
errors scale_wireframe(wireframe_t& frame, scale_t coef);
errors turn_wireframe(wireframe_t& frame, turn_t coef);

#endif // WIREFRAME_H
