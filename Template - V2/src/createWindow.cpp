#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include <gtk/gtk.h>
#include "createWindow.h"



// /** -----------------------------------------------------------------------------
// //               Get the absolute path directory from the main file
// //  
// //  @param path    - absolute path directory	
// // 
// //  @param return  - directory of the absolute path from the main file
// //  -------------------------------------------------------------------------- */
// char *getPath(char *path) 
// { 
// 	char *dirPath = dirname(path);  // Retrieve path excluting file

// 	return dirPath;
// }


Window *builderGetObject(GtkBuilder *builder, Window *widgets, const char *names[], int size)
{
    for (int i = DEFAULT_SIZE; i < size; i++) {
        widgets->widget[i] =  GTK_WIDGET(gtk_builder_get_object(builder, names[i]));
    }
    
    return widgets;
}


BuildWindow::BuildWindow(char *path, Window *widgets, const char *names[], const char *title, int size)
{
    widgets = (Window*)malloc(sizeof(Window));
   
    // Link the Glade GUI builder
    char *fileG = (char*)malloc(sizeof(char) * 100);
    sprintf(fileG, "%s/../graphics/%s.glade", dirname(path), names[0]);

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
