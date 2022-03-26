#include "edges.h"
#include "io.h"

edges_t& init_edges()
{
    edges_t *edges = new edges_t;

    edges->n = 0;
    edges->arr = nullptr;

    return *edges;
}

errors alloc_edges(edges_t &edges, size_t len)
{
    if (!len)
        return ERROR_NO_EDGES;

    edges.n = len;

    edges.arr = new edge_t[len];
    if (!edges.arr)
        return ERROR_PTR_ALL;

    return NONE;
}

void free_edges(edges_t &edges)
{
    delete[] edges.arr;

    delete &edges;
}

errors read_n_edges(edges_t& edges, FILE *f)
{
    errors err = NONE;

    for (size_t i = 0; !err && i < edges.n; i++)
        if (read_edge(&edges.arr[i], f))
            err = ERROR_FILE_FORMAT;

    return err;
}

errors process_edges(edges_t& edges, FILE *f)
{
    size_t n;
    errors err = read_amount(&n, f);

    if (err)
        return err;

    err = alloc_edges(edges, n);

    if (err == NONE)
    {
        if ((err = read_n_edges(edges, f)) == ERROR_FILE_FORMAT)
            free_edges(edges);
    }

    return err;
}
