#ifndef ACTION_MANAGER_H
#define ACTION_MANAGER_H

#include "drawing.h"
#include "operations.h"

enum action
{
    INIT,
    LOAD_FILE,
    DRAW,
    MOVE,
    SCALE,
    TURN,
    QUIT
};

typedef struct
{
    action a;
    union
    {
        const char *load_f;
        canvas_t ca;
        move_t mo;
        scale_t sc;
        turn_t tu;
    };
}
request_t;

errors action_manager(request_t *args);

#endif // ACTION_MANAGER_H
