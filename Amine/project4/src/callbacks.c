#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "greeting.h"


void
on_button1_clicked     (GtkWidget   *objet_graphique,
                                        gpointer  user_data)
{
GtkWidget *Coach;
GtkWidget *Sport;
GtkWidget *treeview1;
Coach=lookup_widget(objet_graphique,"Coach");
Sport=create_Sport ();
gtk_widget_show(Sport);
gtk_widget_destroy(Coach);
treeview1=lookup_widget(Sport,"treeview1");

afficher_personne(treeview1); 
}

void
on_button6_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Coach;
GtkWidget *Sport;

Sport=lookup_widget(objet_graphique,"Sport");
Coach=create_Coach ();
gtk_widget_show(Coach);
gtk_widget_hide(Sport);
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
GtkWidget *Sport;
GtkWidget *treeview1;
Ajout=lookup_widget(objet_graphique,"Ajout");
Sport=create_Sport ();
gtk_widget_show(Sport);
gtk_widget_hide(Ajout);
treeview1=lookup_widget(Sport,"treeview1");

afficher_personne(treeview1);
}


void
on_button8_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
Personne p;

GtkWidget *input1, *input2,*input3,*input4;
GtkWidget *Ajout;

Ajout=lookup_widget(objet_graphique,"Ajout");

input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
input3=lookup_widget(objet_graphique,"entry3");
input4=lookup_widget(objet_graphique,"entry4");


strcpy(p.Cours,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.Date,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.Heure,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.Nombredeplace,gtk_entry_get_text(GTK_ENTRY(input4)));




ajouter_personne(p);



}


void
on_button4_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
GtkWidget *Sport;

Sport=lookup_widget(objet_graphique,"Sport");
Ajout=create_Ajout ();
gtk_widget_show(Ajout);
gtk_widget_hide(Sport);
}

