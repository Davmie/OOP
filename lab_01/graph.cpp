#include "graph.h"
#include "error_handler.h"

errors init_graph(graphics_t &a, canvas_t& canvas)
{
    a.scene = new QGraphicsScene(canvas.gV);
    if (!a.scene)
        return ERROR_PTR_ALL;

    a.pen = QPen(Qt::black);

    return NONE;
}

void del_graph(graphics_t &a)
{
    delete a.scene;
}

void set_graph(canvas_t& canvas, graphics_t& a)
{
    a.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(canvas.w, canvas.h)));

    QGraphicsScene *prev = canvas.gV->scene();
    delete prev;
    canvas.gV->setScene(a.scene);
}
