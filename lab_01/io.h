#ifndef IO_H
#define IO_H

#include <cstdio>

#include "error_handler.h"

errors read_amount(size_t *n, FILE *f);

#endif // IO_H
