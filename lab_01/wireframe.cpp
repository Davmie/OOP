#include <cstdio>

#include "wireframe.h"
#include "error_handler.h"
#include "points.h"
#include "edges.h"
#include "drawing.h"
#include "graph.h"
#include "operations.h"

wireframe_t init_wireframe()
{
    wireframe_t *frame = new wireframe_t;

    frame->points = &init_points();
    frame->edges = &init_edges();

    return *frame;
}

void free_wireframe(wireframe_t& frame)
{
    free_points(*frame.points);

    free_edges(*frame.edges);

}

errors process_wireframe_elements(wireframe_t& frame, FILE *f)
{
    errors err = process_points(*frame.points, f);
    if (!err)
        if ((err = process_edges(*frame.edges, f)))
            free_points(*frame.points);

    return err;
}

errors fread_wireframe(wireframe_t& ob, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERROR_FILE_NOT_FOUND;

    wireframe_t tmp_frame = init_wireframe();

    errors err = process_wireframe_elements(tmp_frame, f);

    fclose(f);

    if (!err)
    {
        free_wireframe(ob);
        ob = tmp_frame;
    }

    return err;
}

errors draw_wireframe(wireframe_t frame, canvas_t canvas)
{
    graphics_t a;

    errors err = init_graph(a, canvas);
    if (err)
        return err;

    draw_edges(*frame.points, *frame.edges, canvas, a);

    set_graph(canvas, a);

    return err;
}

errors move_wireframe(wireframe_t& frame, move_t coef)
{
    return move_points(*frame.points, coef);
}

errors scale_wireframe(wireframe_t& frame, scale_t coef)
{
    return scale_points(*frame.points, coef);
}

errors turn_wireframe(wireframe_t& frame, turn_t coef)
{
    return turn_points(*frame.points, coef);
}

