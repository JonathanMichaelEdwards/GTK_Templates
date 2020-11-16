// #include <iostream>
#include <gtk/gtk.h>
#include "manager.h"
#include "createWindow.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
#define FILENAME "template" // glade file name
#define STRUCT_SIZE 1



// glade
const char *WidgetNames[STRUCT_SIZE] = {
    FILENAME
};



/**
 * Exit button action.
 * - Exit's the App.
 */
extern "C" void on_optManage_destroy(void)
{
    gtk_main_quit();
}


/**
 * Create button action.
 * - When pushed, go to the choose options window.
 */
extern "C" void on_btnFile_clicked(GtkButton *button, Layout *_window)
{
    DESTROY_WIDGET(_window->window);
    // createProject();
}


/**
 * Runs the Managers GUI application
 */
void manager(void)
{
    Widget *_window = (Widget*)malloc(sizeof(Widget));

    createWindow(_window, WidgetNames, FILENAME, STRUCT_SIZE);
}
