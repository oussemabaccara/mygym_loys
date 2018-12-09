#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agenda.h"






void
on_button1_clicked                     (GtkWidget       *objet_graphique, //bouton ajout jour mois annee heure note dans agenda.txt
                                        gpointer         user_data)
{


agenda ag;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *window1;

window1=lookup_widget(objet_graphique,"window1");
input1=lookup_widget(objet_graphique,"entry1");
strcpy(ag.jour,gtk_entry_get_text(GTK_ENTRY (input1)));
input2=lookup_widget(objet_graphique,"entry2");
strcpy(ag.mois,gtk_entry_get_text(GTK_ENTRY (input2)));
input3=lookup_widget(objet_graphique,"entry3");
strcpy(ag.annee,gtk_entry_get_text(GTK_ENTRY (input3)));
input4=lookup_widget(objet_graphique,"entry4");
strcpy(ag.heure,gtk_entry_get_text(GTK_ENTRY (input4)));
input5=lookup_widget(objet_graphique,"entry5");
strcpy(ag.notes,gtk_entry_get_text(GTK_ENTRY (input5)));


ajouter_agenda(ag);
}




void
on_button3_clicked                     (GtkWidget       *objet_graphique,  //bouton afficher jour mois annee heure note dans treeview1
                                        gpointer         user_data)


{


GtkWidget *window1;
GtkWidget *window2;
GtkWidget *treeview1;

window1=lookup_widget(objet_graphique,"window1");
	gtk_widget_hide(window1);
window2=lookup_widget(objet_graphique,"window2");
window2=create_window2();
	gtk_widget_show(window2);


treeview1=lookup_widget(window2,"treeview1");
afficher_agenda(treeview1);
}



void
on_button5_clicked                     (GtkWidget       *objet_graphique,  //bouton retour 
                                        gpointer         user_data)

{
GtkWidget *window1;
GtkWidget *window2;
window2=lookup_widget(objet_graphique,"window2");
	window1=create_window1();
	gtk_widget_show(window1);

	gtk_widget_hide(window2);

}


void
on_button12_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button14_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}

