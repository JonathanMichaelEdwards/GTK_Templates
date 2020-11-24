#include <stdio.h>
#include <gtk/gtk.h>
#include "demoWindow.h"



int main(int argc, char **argv)
{
    // Initialize gtk
    gtk_init(&argc, &argv);

    // run the program
    manager(argv[0]);


    return EXIT_SUCCESS;
}
