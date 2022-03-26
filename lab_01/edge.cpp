#include "edge.h"

errors read_edge(edge_t *edge, FILE *f)
{
    if (fscanf(f, "%zd%zd", &edge->p1, &edge->p2) != 2)
        return ERROR_FILE_FORMAT;

    return NONE;
}
