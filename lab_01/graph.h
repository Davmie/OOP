#ifndef GRAPH_H
#define GRAPH_H

#include <QGraphicsView>
#include "error_handler.h"

typedef struct
{
    QGraphicsView *gV;
    int w;
    int h;
}
canvas_t;

typedef struct
{
    QGraphicsScene *scene;
    QPen pen;
}
graphics_t;

errors init_graph(graphics_t &a, canvas_t& canvas);
void del_graph(graphics_t &a);
void set_graph(canvas_t& canvas, graphics_t& a);

#endif // GRAPH_H
