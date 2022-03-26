#ifndef EDGES_H
#define EDGES_H

#include "edge.h"

typedef struct
{
    size_t n;
    edge_t *arr;
}
edges_t;

edges_t& init_edges();

errors alloc_edges(edges_t& edges, size_t len);
void free_edges(edges_t& edges);

void copy_edges(edges_t&dst, edges_t&src);

errors read_n_edges(edges_t& edges, FILE *f);
errors process_edges(edges_t& edges, FILE *f);

#endif //EDGES_H
