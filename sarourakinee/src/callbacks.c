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
 GtkWidget *j; //spinbuttun pour le choix du jour
 GtkWidget *m; //spinbuttun pour le choix du mois 
GtkWidget *a; //spinbuttun pour le choix de l’année
GtkWidget *nb; //spinbutton pour nbre de places
GtkWidget *output;
GtkWidget *input;
Seance s;
int jj,mm,aa,nbb;



combobox1=lookup_widget(objet_graphique, "combobox1");
 j=lookup_widget(objet_graphique, "spinbutton4"); 
 m=lookup_widget(objet_graphique, "spinbutton5"); 
 a=lookup_widget(objet_graphique, "spinbutton6"); 
 nb=lookup_widget(objet_graphique, "spinbutton7");
 combobox2=lookup_widget(objet_graphique, "combobox2");
output=lookup_widget(objet_graphique, "label17"); 
input=lookup_widget(objet_graphique,"entry8");

jj=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (j));
mm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (m));
aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (a));
nbb=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nb));

intstring(jj,s.date_seance.jour);
intstring(mm,s.date_seance.mois);
intstring(aa,s.date_seance.annee);
intstring(nbb,s.nbp);



if(strcmp("9h-->10h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)  
	strcpy(s.periode,"9h-->10h");
if(strcmp("10h-->11h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	strcpy(s.periode,"10h-->11h");
if(strcmp("11h-->12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0) 
	strcpy(s.periode,"11h-->12h");
if(strcmp("15h-->16h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0) 
	strcpy(s.periode,"15h-->16h");
if(strcmp("16h-->17h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0) 
	strcpy(s.periode,"16h-->17h");

strcpy(s.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

strcpy(s.num,gtk_entry_get_text(GTK_ENTRY(input)));



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




void
on_button9_clicked   (GtkWidget    *objet,gpointer user_data)
{
GtkWidget *window1;
	GtkWidget *window4;
	GtkWidget *treeview2;
	
	
	window1=lookup_widget(objet,"window1");

	window4=lookup_widget(objet,"window4");
	gtk_widget_hide(window1);
	window4=create_window4();
	gtk_widget_show(window4);
	
	treeview2=lookup_widget(window4,"treeview2");
	afficher_seance(treeview2);
}



void
on_button10_clicked   (GtkWidget       *objet,gpointer         user_data)
{
	GtkWidget *window5 ;
	GtkWidget *window4 ;
	window4=lookup_widget(objet,"window4");
	window5=lookup_widget(objet,"window5");
	window5=create_window5();
	gtk_widget_show(window5);
}


void
on_button11_clicked  (GtkWidget      *objet, gpointer         user_data)
{
	GtkWidget *window6 ;
	GtkWidget *window4 ;
	window4=lookup_widget(objet,"window4");
	window6=lookup_widget(objet,"window6");
	window6=create_window6();
	gtk_widget_show(window6);

}




void
on_button13_clicked  (GtkWidget       *objet,gpointer         user_data)
{	
	GtkWidget *output;
	GtkWidget *input1;
	GtkWidget *input2;
	Seance s;
	char nn[5];

	output=lookup_widget(objet, "label21"); 
	input1=lookup_widget(objet,"entry5");
	input2=lookup_widget(objet,"entry6");

	strcpy(nn,gtk_entry_get_text(GTK_ENTRY(input1)));

	modifier_seance(nn,gtk_entry_get_text(GTK_ENTRY(input2)));
	gtk_label_set_text(GTK_LABEL(output),"Modification réussie :) ");


}


void
on_button14_clicked (GtkWidget      *objet, gpointer         user_data)
{	
	GtkWidget *output;
	GtkWidget *input;
	Seance s;
	char nn[5];

	output=lookup_widget(objet, "label22"); 
	input=lookup_widget(objet,"entry7");

	strcpy(nn,gtk_entry_get_text(GTK_ENTRY(input)));

	supprimer_seance(nn);
	gtk_label_set_text(GTK_LABEL(output),"Suppression réussie :) ");
}


void
on_retour1_clicked  (GtkWidget       *objet,  gpointer         user_data)
{	
	GtkWidget *window1 ;
	GtkWidget *window2 ;
	window2=lookup_widget(objet,"window2");
	gtk_widget_destroy(window2);
	window1=create_window1();
	gtk_widget_show(window1);
						
}


void
on_retour3_clicked    (GtkWidget      *objet, gpointer         user_data)
{
	GtkWidget *window1 ;
	GtkWidget *window4 ;
	window4=lookup_widget(objet,"window4");
	gtk_widget_destroy(window4);
	window1=create_window1();
	gtk_widget_show(window1);

}


void
on_retour2_clicked (GtkWidget     *objet,gpointer         user_data)
{
	GtkWidget *window1 ;
	GtkWidget *window3 ;
	window3=lookup_widget(objet,"window3");
	gtk_widget_destroy(window3);
	window1=create_window1();
	gtk_widget_show(window1);
	

}

