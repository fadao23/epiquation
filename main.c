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
 // stack2 = GTK_WIDGET(gtk_builder_get_object(builder,"stack2"));

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

  /* Setting entry text zone for System and out text zone*/
  sys_in = GTK_ENTRY(gtk_builder_get_object(builder,"sys_in"));
  sys_recap = GTK_LABEL(gtk_builder_get_object(builder,"sys_recap"));
  sys_out = GTK_LABEL(gtk_builder_get_object(builder,"sys_out"));
  max_sys = 10;
  nb_sys = 0;
  sys = malloc(max_sys * sizeof (char*));

  /* Setting entry text zone for Derivate and out text zone*/
  D_entry = GTK_ENTRY(gtk_builder_get_object(builder,"D_text_in"));
  D_out = GTK_LABEL(gtk_builder_get_object(builder,"D_text_out"));

  /* Build and set window*/
  g_object_unref (G_OBJECT (builder));
  gtk_widget_show(MainWindow);
  gtk_main();

  return 0;
}

/* ---------------------- QUIT && RETURN BUTTONS ---------------- */
void on_quit_clicked()
{
  gtk_main_quit();
}

void on_return_clicked()
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

void on_systeme_clicked()
{
  gtk_stack_set_visible_child_name(GTK_STACK(stack),"page3");
}

void on_deriv_clicked()
{
  gtk_stack_set_visible_child_name(GTK_STACK(stack),"page4");
}

void on_primitive_clicked()
{
  gtk_stack_set_visible_child_name(GTK_STACK(stack),"page5");
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

/* --------------------------- SYSTEM ----------------------------*/
void on_add_sys_clicked()
{
  if (nb_sys == max_sys) {
    max_sys *= 2;
    sys = realloc(sys, max_sys * sizeof (char*));
  }
  const char *tmp = gtk_entry_get_text(sys_in);
  *(sys + nb_sys) = malloc((strlen(tmp) + 10) * sizeof (char));
  strcpy(*(sys + nb_sys), tmp);
  char *s = calloc(500, sizeof (char));
  const char *lab = gtk_label_get_text(sys_recap);
  sprintf(s,"%s\n%s", lab, *(sys + nb_sys));
  nb_sys++;
  gtk_label_set_text(sys_recap,s);
  gtk_entry_set_text(sys_in, "");
}

void on_apply_sys_clicked()
{
  gtk_label_set_text(sys_out, solve_system(sys, nb_sys));
  for (int i = 0; i < nb_sys; ++i) {
    free(*(sys + i));
    *(sys + i) = NULL;
  }
  nb_sys = 0;
}

void on_cancel_sys_clicked()
{
  gtk_entry_set_text(sys_in, "");
  gtk_label_set_text(sys_recap, "");
  gtk_label_set_text(sys_out, "");
  for (int i = 0; i < nb_sys; ++i) {
    free(*(sys + i));
    *(sys + i) = NULL;
  }
  nb_sys = 0;
}


/* --------------------------- DER/PRI ----------------------------*/

void on_Dcancel_clicked()
{
  const gchar *ttr = "";
  gtk_entry_set_text(D_entry,"");
  gtk_label_set_text(D_out,ttr);
  return;
}

/*void on_Dapply_clicked()
{
  const gchar *str = gtk_entry_get_text(D_entry);
  gtk_label_set_text(D_out,str);
  char *copie = calloc(200,sizeof(char));
  strcpy(copie,str);
  char *res = //FUNC DERIVATE HERE
  gtk_label_set_text(out2, res);
  gtk_entry_set_text(entry,"");
  free(copie);
  free(res);
}*/
