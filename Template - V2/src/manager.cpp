// #include <iostream>
#include <gtk/gtk.h>
#include "manager.h"
#include "createWindow.h"

#define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
#define FILENAME "template" // glade file name
#define STRUCT_SIZE 1


// typedef struct {
//     GtkWidget *window;
// } Layout;

// typedef union {
//     struct {
//         Layout window;
//     };
//     int widget[STRUCT_SIZE];
// } Widgets;

// glade
const char *WidgetNames[STRUCT_SIZE] = {
    FILENAME
};



/**
 * Exit button action.
 * - Exit's the App.
 */
extern "C"void on_optManage_destroy(void)
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


// /**
//  * Free all memory used.
//  * @param char *fileG - Glade file freed.
//  * @param Layout *_window - Glade _window that are stored 
//  *        in a struct.
//  */
// static void freeMem(char *fileG, Layout *_window)
// {
//     free(fileG);
//     free(_window);
// }


// void builderGetObject(GtkBuilder *builder, Widgets *widgets)
// {
//     for (int i = 1; i < STRUCT_SIZE; i++)
//         widgets->widget[i] =  GTK_WIDGET(gtk_builder_get_object(builder, WidgetNames[i]));
// }


// char *fileLocation(char *findLoc) 
// {
//     return realpath(findLoc, NULL);  // Find the absolute path
// }


// void createWindow(const char *title, Widgets *widgets)
// {
//     char *loc = fileLocation("../glade/main.glade");

//     // Link the Glade GUI builder
//     // char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(WidgetNames[0]));
//     // sprintf(fileG, "glade/%s.glade", WidgetNames[0]);
//     // puts(loc);
//     GtkBuilder *builder = gtk_builder_new_from_file(loc);

//     // Create the default Window
//     GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, WidgetNames[0]));

//     widgets->widget[0] = window;
//     if (STRUCT_SIZE > 1) builderGetObject(builder, widgets);
    
//     gtk_window_set_title(GTK_WINDOW(window), title);
//     gtk_builder_connect_signals(builder, widgets);
    
//     g_object_unref(builder);  // Reference builder 

//     // Execute window
//     gtk_widget_show(window);                
//     gtk_main();
// }


/**
 * Runs the Managers GUI application
 */
void manager(void)
{
    Widget *_window = (Widget*)malloc(sizeof(Widget));

    printf("%s\n", WidgetNames[0]);
    createWindow(_window, WidgetNames, FILENAME, STRUCT_SIZE);
    // createWindow(PROJECT_NAME, _window);

    // Free memory
    // freeMem(fileG, _window);
}


// #include <gtk/gtk.h>
// #include "manager.h"
// // #include "createProject.h"

// #define LEN_OF_FILE(FILENAME) 18 + strlen(FILENAME)
// #define FILENAME "manager"
// #define STRUCT_SIZE 1


// typedef struct {
//     GtkWidget *window;
// } Layout;


// typedef union {
//     struct {
//         Layout window;
//     };
//     int widget[STRUCT_SIZE];
// } Widgets;


// const char *WidgetNames[STRUCT_SIZE] = {
//     FILENAME
// };



// /**
//  * Exit button action.
//  * - Exit's the App.
//  */
// void on_optManage_destroy(void)
// {
//     gtk_main_quit();
// }


// /**
//  * Create button action.
//  * - When pushed, go to the choose options window.
//  */
// void on_btnFile_clicked(GtkButton *button, Layout *_window)
// {
//     DESTROY_WIDGET(_window->window);
//     // createProject();
// }


// /**
//  * Free all memory used.
//  * @param char *fileG - Glade file freed.
//  * @param Layout *_window - Glade _window that are stored 
//  *        in a struct.
//  */
// static void freeMem(char *fileG, Layout *_window)
// {
//     free(fileG);
//     free(_window);
// }


// void builderGetObject(GtkBuilder *builder, Widgets *widgets)
// {
//     for (int i = 1; i < STRUCT_SIZE; i++)
//         widgets->widget[i] =  GTK_WIDGET(gtk_builder_get_object(builder, WidgetNames[i]));
// }


// char *fileLocation(char *findLoc) 
// {
//     return realpath(findLoc, NULL);  // Find the absolute path
// }


// void createWindow(const char *title, Widgets *widgets)
// {
//     char *loc = fileLocation("../glade/main.glade");

//     // Link the Glade GUI builder
//     // char *fileG = (char*)malloc(sizeof(char) * LEN_OF_FILE(WidgetNames[0]));
//     // sprintf(fileG, "glade/%s.glade", WidgetNames[0]);
//     // puts(loc);
//     GtkBuilder *builder = gtk_builder_new_from_file(loc);

//     // Create the default Window
//     GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, WidgetNames[0]));

//     widgets->widget[0] = window;
//     if (STRUCT_SIZE > 1) builderGetObject(builder, widgets);
    
//     gtk_window_set_title(GTK_WINDOW(window), title);
//     gtk_builder_connect_signals(builder, widgets);
    
//     g_object_unref(builder);  // Reference builder 

//     // Execute window
//     gtk_widget_show(window);                
//     gtk_main();
// }


// /**
//  * Runs the Managers GUI application
//  */
// void manager(void)
// {
//     Widgets *_window = (Widgets*)malloc(sizeof(Widgets));

//     createWindow(PROJECT_NAME, _window);

//     // Free memory
//     // freeMem(fileG, _window);
// }