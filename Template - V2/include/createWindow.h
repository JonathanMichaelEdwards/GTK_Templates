#ifndef CREATE_WINDOW_H
#define CREATE_WINDOW_H


#define DEFAULT_SIZE                1
#define PROJECT_NAME                "Template"
#define DESTROY_WIDGET(WINDOW)      gtk_widget_destroy(WINDOW); // Destroy's GtkWidget



typedef struct {
    GtkWidget *window;
} Layout;

typedef union {
    struct {
        Layout window;
    };
    GtkWidget *widget[DEFAULT_SIZE];
} Window;


class BuildWindow
{
    private:
        /* data */
    public:
        BuildWindow(char *path, Window *widgets, const char *names[], const char *title, int size);
        ~BuildWindow();
};




#endif // CREATE_WINDOW_H
