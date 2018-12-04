#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "offre.h"


void
on_button7_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button2_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
	
	window2=create_window2();
	gtk_widget_show (window2);
	

}


void
on_button3_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button8_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *button8;
GtkWidget *label6;
char nom1[10];
offre offre1;
char str[100];


combobox1=lookup_widget(objet_graphique,"combobox1");
strcpy(nom1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
offre1=getoffre(nom1);
label6=lookup_widget(objet_graphique,"label6");
strcpy(str,"Déscription : ");
strcat(str,offre1.description);
strcat(str,"\nPrix :");
strcat(str,offre1.prix);
gtk_label_set_text(GTK_LABEL(label6),str);

}

