#include <gtk/gtk.h>
#include "demoWindow.h"
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
extern "C" void destroy(void)
{
    gtk_main_quit();
}


/**
 * Create button action.
 * - When pushed, go to the choose options window.
 */
extern "C" void btnFile(GtkButton *button, Layout *_window)
{
    DESTROY_WIDGET(_window->window);
}


/**
 * Runs the Managers GUI application
 */
void manager(void)
{
    Window *_window = NULL;

    BuildWindow window(_window, WidgetNames, FILENAME, STRUCT_SIZE);
}
