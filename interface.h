#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/* Vriables Objects */
GtkBuilder *builder;
GtkWidget *MainWindow,*stack;
GtkEntry *entry;
GtkButton *quit2;
GtkLabel *out,*out2;

/* Foncitons */

/* QUIT FONCTIONS */
void on_quit1_clicked();
void on_quit2_clicked();
void on_quit3_clicked();

/* RETURN FONCTIONS */
void on_return1_clicked();
void on_return2_clicked();

/* AFFINE FONCTIONS */
void on_apply_clicked();
void on_cancel_clicked();

/* MENU FONCTIONS */
void on_Baffine_clicked();
void on_polynomes_clicked();
void sol(char *arg);
