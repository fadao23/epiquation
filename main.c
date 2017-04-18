# include "tree.h"
# include "build.h"
# include "solveur.h"
# include "parsing.h"
# include "erreur.h"
# include <stdio.h>
# include <err.h>


#include "interface.h"

//void on_quit_clicked();

void sol(char *arg);

int main(int argc,char **argv)
{
  /* Déclaration du widget */
  gtk_init(&argc,&argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "interface.glade", NULL);

  MainWindow = GTK_WIDGET(gtk_builder_get_object(builder,"MainWindow"));

  gtk_builder_connect_signals(builder,NULL);

  entry = GTK_ENTRY(gtk_builder_get_object(builder,"text_in"));
  g_signal_connect(entry,"activate",G_CALLBACK(on_apply_clicked),entry);
  out = GTK_LABEL(gtk_builder_get_object(builder,"text_out"));
  g_object_unref (G_OBJECT (builder));
  gtk_widget_show(MainWindow);
  gtk_main();

  return 0;
}

void on_quit1_clicked()
{
  gtk_main_quit();
}

void on_apply_clicked()
{
  const gchar *str = gtk_entry_get_text(entry);
  gtk_label_set_text(out,str);
  char *c = (char*)str;
  printf("%s\n",c);
  char *copie = c;
  printf("%p\n",copie);
  sol(copie);
}

void sol(char *arg) {
  char *equation = clean_string(arg);
  printf("%p\n",equation);
  printf("Equation nettoyee :\n%s\n", equation);
  printf("%p\n",equation);
  struct s_tree *node = parse(equation);

  if (*get_erreur())
  {
    print_erreur();
    free_erreur();
    //return -1;
  }

  simplify_minus(&node, 1);
  float coef = 1;

  simplify_mult(&node, NULL, &coef, 0);

  simplify_plus(&node, NULL, &coef, 0);

  float res = solveur(node, 0, 1);

  /*if (*get_erreur())
  {
    print_erreur();
    free_tree(node);
    free_erreur();
    return -1;
  }*/
	printf("x = %f\n", res);
  //const gchar *r = *res;

  //gtk_label_set_text(out,r);
  free_tree(node);
  free_erreur();
}
