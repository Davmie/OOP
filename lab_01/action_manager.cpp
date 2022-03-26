#include "action_manager.h"
#include "error_handler.h"
#include "wireframe.h"

errors action_manager(request_t *req)
{
    static wireframe_t frame = init_wireframe();
    errors err = NONE;

    switch (req->a)
    {
    case INIT:
        break;
    case LOAD_FILE:
        err = fread_wireframe(frame, req->load_f);
        break;
    case DRAW:
        err = draw_wireframe(frame, req->ca);
        break;
    case MOVE:
        err = move_wireframe(frame, req->mo);
        break;
    case SCALE:
        err = scale_wireframe(frame, req->sc);
        break;
    case TURN:
        err = turn_wireframe(frame, req->tu);
        break;
    case QUIT:
        free_wireframe(frame);
        break;
    default:
        err = ERROR_UNKNOWN_COMMAND;
    }

    return err;
}
