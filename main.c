# include "ihm.h"

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


  /* Setting entry text zone for Polynome and out text zone*/
  pol_a = GTK_ENTRY(gtk_builder_get_object(builder,"coef_x2"));
  pol_b = GTK_ENTRY(gtk_builder_get_object(builder,"coef_x"));
  pol_c = GTK_ENTRY(gtk_builder_get_object(builder,"coef"));
  pol_d = GTK_ENTRY(gtk_builder_get_object(builder,"pol_res"));
  out_pol = GTK_LABEL(gtk_builder_get_object(builder,"res_pol"));

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



/* --------------------------- AFFINE ---------------------------*/
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
  char *copie = calloc(200,sizeof(char));
  strcpy(copie,str);
  char *res = solve_equation(copie);
  gtk_label_set_text(out2, res);
  gtk_entry_set_text(entry,"");
  free(copie);
  free(res);
}
/* --------------------------- POLYNOME -------------------------*/
void on_cancel_p_clicked()
{
  gtk_entry_set_text(pol_a,"");
  gtk_entry_set_text(pol_b,"");
  gtk_entry_set_text(pol_c,"");
  gtk_entry_set_text(pol_d,"");
  gtk_label_set_text(out_pol, "");
}

void on_apply_p_clicked()
{
  const char **param = malloc(4 * sizeof (char*));
  *param = gtk_entry_get_text(pol_a);
  *(param + 1) = gtk_entry_get_text(pol_b);
  *(param + 2) = gtk_entry_get_text(pol_c);
  *(param + 3) = gtk_entry_get_text(pol_d);
  char *res = solve_polynome(param);
  free(param);
  gtk_label_set_text(out_pol, res);
  free(res);
}

