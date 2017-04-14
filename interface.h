#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

GtkBuilder *builder;
GtkWidget *MainWindow;
GtkEntry *entry;
GtkLabel *out;


void on_apply_clicked();
