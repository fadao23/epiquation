#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

GtkBuilder *builder;
GtkWidget *MainWindow,*stack;
GtkEntry *entry;
GtkButton *quit2;
GtkLabel *out,*out2;

void on_quit1_clicked();
void on_quit2_clicked();
void on_apply_clicked();
void on_cancel_clicked();
void on_Baffine_clicked();
