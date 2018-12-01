#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fiche.h"
#include "seances_cures.h" 





void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_clicked  (GtkWidget *objet_graphique, gpointer  user_data)
{
	GtkWidget *input ;
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *window1;
	GtkWidget *window2;
	
	char nom [50]; char ficha[1000];



input=lookup_widget(objet_graphique,"entry4");
output1=lookup_widget(objet_graphique,"label12");


strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));

if (verifier(nom)==-1)
	{ gtk_label_set_text(GTK_LABEL(output1),"Username incorrect !!! ");}
else 
{
	gtk_widget_hide(window1);
	window2=create_window2();
	gtk_widget_show(window2);
	output2=lookup_widget(window2,"label13");
	afficher(nom,ficha);
	gtk_widget_show(window2);
	gtk_label_set_text(GTK_LABEL(output2),ficha);
	
	
	
	
}
}


void
on_button7_clicked  (GtkWidget *objet_graphique, gpointer  user_data)
{
GtkWidget *combobox1; //comobox pour la période
GtkWidget *combobox2; //comobox pour le type
 GtkWidget *jour; //spinbuttun pour le choix du jour
 GtkWidget *mois; //spinbuttun pour le choix du mois 
GtkWidget *annee; //spinbuttun pour le choix de l’année
GtkWidget *output;
Seance s;
char TYPE[20];

combobox1=lookup_widget(objet_graphique, "combobox1"); jour=lookup_widget(objet_graphique, "spinbutton4"); mois=lookup_widget(objet_graphique, "spinbutton5"); annee=lookup_widget(objet_graphique, "spinbutton6"); combobox2=lookup_widget(objet_graphique, "combobox2");
output=lookup_widget(objet_graphique, "label17"); 

s.date_seance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.date_seance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.date_seance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

if(strcmp("9h-->10h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)  s.periode=1;
if(strcmp("10h-->11h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)  s.periode=2;
if(strcmp("11h-->12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)  s.periode=3;
if(strcmp("15h-->16h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)  s.periode=4;
if(strcmp("16h-->17h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)  s.periode=5;

strcpy(TYPE,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));



ajouter_seance(s);

gtk_label_set_text(GTK_LABEL(output),"Séance ajoutée :) ");


}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button8_clicked   (GtkWidget       *objet ,gpointer  user_data)
{
	
	GtkWidget *window1;
	GtkWidget *window3;
	GtkWidget *treeview1;
	
	
	window1=lookup_widget(objet,"window1");


	gtk_widget_hide(window1);
	window3=lookup_widget(objet,"window3");
	window3=create_window3();
	gtk_widget_show(window3);
	
	treeview1=lookup_widget(window3,"treeview1");
	afficher_fiche(treeview1);
	
	
	

}



