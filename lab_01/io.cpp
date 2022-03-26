#include <cstdio>
#include "error_handler.h"

errors read_amount(size_t *n, FILE *f)
{
    errors err = NONE;

    if (fscanf(f, "%zd", n) != 1)
        err = ERROR_FILE_FORMAT;

    if (*n <= 0)
        err = ERROR_FILE_CONTENT;

    return err;
}
