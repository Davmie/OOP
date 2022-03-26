#ifndef EDGE_H
#define EDGE_H

#include <cstdio>

#include "error_handler.h"

typedef struct
{
    size_t p1;
    size_t p2;
}
edge_t;

errors read_edge(edge_t *edge, FILE *f);

#endif // EDGE_H
