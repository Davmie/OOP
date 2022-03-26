#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

enum errors
{
    NONE,
    ERROR_FILE_NOT_FOUND,
    ERROR_FILE_FORMAT,
    ERROR_FILE_CONTENT,
    ERROR_PTR_ALL,
    ERROR_NO_DOTS,
    ERROR_NO_EDGES,
    ERROR_UNKNOWN_COMMAND
};

void error_message(errors err);

#endif // ERROR_HANDLER_H
