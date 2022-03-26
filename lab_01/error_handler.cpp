#include "error_handler.h"
#include "QMessageBox"
#include <QObject>

void error_message(errors err)
{
    switch (err)
    {
        case ERROR_FILE_NOT_FOUND:
        {
            QMessageBox::critical(NULL, "ERROR", "File is broken, or doesn't exist");
        }
        case ERROR_FILE_FORMAT:
        {
            QMessageBox::critical(NULL, "ERROR", "File format error");
        }
        case ERROR_FILE_CONTENT:
        {
            QMessageBox::critical(NULL, "ERROR", "File has wrong content");
        }
        case ERROR_PTR_ALL:
        {
            QMessageBox::critical(NULL, "ERROR", "Error with memory allocation");
        }
        case ERROR_NO_DOTS:
        {
            QMessageBox::critical(NULL, "ERROR", "File is empty, or array is empty!");
        }
        case ERROR_NO_EDGES:
        {
            QMessageBox::critical(NULL, "ERROR", "Unknown command in enter point!");
        }
        default:
            QMessageBox::critical(NULL, "ERROR", "Unknown error");
    }
}
