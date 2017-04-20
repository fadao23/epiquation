# include "tree.h"
# include "build.h"
# include "solveur.h"
# include "erreur.h"
# include <stdio.h>
# include <err.h>
# include "interface.h"
# include "parsing.h"


int main(int argc,char **argv)
{
  /* Iniliasition of widget */
  gtk_init(&argc,&argv);

  /* Initiatlisation */
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "interface.glade", NULL);

  /* Initialisation of Mainwindow and stack */
  MainWindow = GTK_WIDGET(gtk_builder_get_object(builder,"MainWindow"));
  stack = GTK_WIDGET(gtk_builder_get_object(builder,"stack"));

  /* Setting signals */
  gtk_builder_connect_signals(builder,NULL);

  /* Setting entry text zone for Affine and out text zone*/
  entry = GTK_ENTRY(gtk_builder_get_object(builder,"text_in"));
  out = GTK_LABEL(gtk_builder_get_object(builder,"text_out"));
  out2 = GTK_LABEL(gtk_builder_get_object(builder,"text_out2"));


  /* Build and set window*/
  g_object_unref (G_OBJECT (builder));
  gtk_widget_show(MainWindow);
  gtk_main();

  return 0;
}

/* ---------------------- QUIT && RETURN BUTTONS ---------------- */
void on_quit1_clicked()
{
  gtk_main_quit();
}
void on_quit2_clicked()
{
  gtk_main_quit();
}
void on_quit3_clicked()
{
  gtk_main_quit();
}

void on_return1_clicked()
{
  gtk_stack_set_visible_child_name(GTK_STACK(stack),"page1");
}

void on_return2_clicked()
{
  gtk_stack_set_visible_child_name(GTK_STACK(stack),"page1");
}
/* --------------------------------------------------------------*/


/* ------------------------ BUTTONS MENU ------------------------*/
void on_Baffine_clicked()
{
  gtk_stack_set_visible_child_name(GTK_STACK(stack),"page0");
}

void on_polynomes_clicked()
{
  gtk_stack_set_visible_child_name(GTK_STACK(stack),"page2");
}
/* --------------------------------------------------------------*/



/* --------------------------- AFFINE ----------------------------*/
void on_cancel_clicked()
{
  const gchar *dtr = "";
  gtk_entry_set_text(entry,"");
  gtk_label_set_text(out,dtr);
  gtk_label_set_text(out2,dtr);
  return;
}

void on_apply_clicked()
{
  const gchar *str = gtk_entry_get_text(entry);
  gtk_label_set_text(out,str);
  char *c = (char*)str;
  char *copie = calloc(200,sizeof(char));
  strcpy(copie,c);
  sol(copie);
  gtk_entry_set_text(entry,"");
  free(copie);
}

void sol(char *arg) {
  char *equation = clean_string(arg);
  printf("Equation nettoyee :\n%s\n", equation);
  struct s_tree *node = parse(equation);

  if (*get_erreur())
  {
    print_erreur();
    set_erreur(0);
    return;
  }

  simplify_minus(&node, 1);
  float coef = 1;

  simplify_mult(&node, NULL, &coef, 0);

  simplify_plus(&node, NULL, &coef, 0);

  float res = solveur(node, 0, 1);

  if (*get_erreur())
  {
    print_erreur();
    free_tree(node);
    set_erreur(0);
    return;
  }
	printf("x = %f\n", res);
  char *r = calloc(200,sizeof(char));
  char *re = calloc(100,sizeof(char));
  char *test = "x =";
  strcat(r,test);
  sprintf(re,"%f",res);
  strcat(r,re);
  gtk_label_set_text(out2,r);
  free_tree(node);
  free(r);
  free(re);
  set_erreur(0);
}
/* --------------------------------------------------------------*/
