#include <stdio.h>
#include <gtk/gtk.h>
#include "optManage.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)


/**
 * Exit button action.
 */
void on_optManage_destroy(void)
{
    gtk_main_quit();
}


/**
 * Free all memory used.
 */
void freeMem(char *file)
{
    free(file);
}


int main(int argc, char **argv)
{
    // Initialize gtk
    gtk_init(&argc, &argv);

    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(FILENAME_1));
    sprintf(fileG, "../glade/%s.glade", FILENAME_1);
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);

    // Create the default Window
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, FILENAME_1));
    gtk_window_set_title(GTK_WINDOW(window), PROJECT_NAME);
    gtk_builder_connect_signals(builder, NULL);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();

    // Free memory
    freeMem(fileG);

    return EXIT_SUCCESS;
}
