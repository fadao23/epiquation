#include "interface.h"

//void on_quit_clicked();

int main(int argc,char **argv)
{
  /* Déclaration du widget */
  gtk_init(&argc,&argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "ihm.glade", NULL);

  MainWindow = GTK_WIDGET(gtk_builder_get_object(builder,"MainWindow"));

  gtk_builder_connect_signals(builder,NULL);

  entry = GTK_ENTRY(gtk_builder_get_object(builder,"text_in"));
  g_signal_connect(entry,"activated",G_CALLBACK(on_apply_clicked),entry);
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
}
