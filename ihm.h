# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <gtk/gtk.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# include "controller/control.h"

/* Variables Objects */
GtkBuilder *builder;
GtkWidget *MainWindow,*stack, *stack2;
GtkEntry *entry, *pol_a, *pol_b, *pol_c, *pol_d, *sys_in, *D_entry;
GtkButton *quit2;
GtkLabel *out,*out2, *out_pol, *sys_recap, *sys_out, *out, *D_out;
char **sys;
int nb_sys, max_sys;


/* Functions */

/* QUIT FUNCTIONS */
void on_quit1_clicked();
void on_quit2_clicked();
void on_quit3_clicked();

/* RETURN FUNCTIONS */
void on_return1_clicked();
void on_return2_clicked();

/* AFFINE FUNCTIONS */
void on_apply_clicked();
void on_cancel_clicked();

/* DERIVES FUNCTIONS */
void on_Dapply_clicked();
void on_Dcancel_clicked();

/* MENU FUNCTIONS */
void on_Baffine_clicked();
void on_polynomes_clicked();
void on_deriv_clicked();
void on_primitive_clicked();
void sol(char *arg);
