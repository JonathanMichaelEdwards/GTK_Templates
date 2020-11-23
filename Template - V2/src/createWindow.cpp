#include <stdio.h>
#include <gtk/gtk.h>
#include "createWindow.h"


#define LEN_OF_FILE(NAME) 19 + strlen(NAME)



Window *builderGetObject(GtkBuilder *builder, Window *widgets, const char *names[], int size)
{
    for (int i = DEFAULT_SIZE; i < size; i++) {
        widgets->widget[i] =  GTK_WIDGET(gtk_builder_get_object(builder, names[i]));
    }
    
    return widgets;
}


BuildWindow::BuildWindow(Window *widgets, const char *names[], const char *title, int size)
{
    widgets = (Window*)malloc(sizeof(Window));

    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(names[0]));
    sprintf(fileG, "../graphics/%s.glade", names[0]);
    GtkBuilder *builder = gtk_builder_new_from_file(fileG);

    // Create the default Window
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, names[0]));

    widgets->widget[0] = window;
    if (size > DEFAULT_SIZE) widgets = builderGetObject(builder, widgets, names, size);
    
    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_builder_connect_signals(builder, widgets);
    
    g_object_unref(builder);  // Reference builder 

    // Execute window
    gtk_widget_show(window);                
    gtk_main();
    
    // Free memory
    free(fileG);
    g_slice_free(Window, widgets);
}

BuildWindow::~BuildWindow()
{
}
