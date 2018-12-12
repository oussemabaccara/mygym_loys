#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agenda.h"
#include "fiche.h"







void
on_button1_clicked                     (GtkWidget       *objet_graphique, //bouton ajout jour mois annee heure note dans agenda.txt
                                        gpointer         user_data)
{


agenda ag;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;
GtkWidget *window1;

window1=lookup_widget(objet_graphique,"window1");
input1=lookup_widget(objet_graphique,"spinbutton1");
ag.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input1));
input2=lookup_widget(objet_graphique,"spinbutton2");
ag.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
input3=lookup_widget(objet_graphique,"spinbutton3");
ag.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input3));
input4=lookup_widget(objet_graphique,"combobox1");
strcpy(ag.heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input4)));
input5=lookup_widget(objet_graphique,"entry5");
strcpy(ag.notes,gtk_entry_get_text(GTK_ENTRY (input5)));
input6=lookup_widget(objet_graphique,"entry32");
strcpy(ag.id,gtk_entry_get_text(GTK_ENTRY (input6)));


ajouter_agenda(ag);
}




void
on_button3_clicked                     (GtkWidget       *objet_graphique,  //bouton afficher jour mois annee heure note dans treeview1
                                        gpointer         user_data)


{


GtkWidget *window1;
GtkWidget *window5;
GtkWidget *treeview3;
window5=lookup_widget(objet_graphique,"window5");
	window5=create_window5();
	gtk_widget_show(window5);

	gtk_widget_hide(window1);



treeview3=lookup_widget(window5,"treeview3");
afficher_agenda(treeview3);
}









void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
fiche fi;
GtkWidget *input7,*input8,*input9,*input10,*input11,*input12,*input13,*input14,*input15;
GtkWidget *window1;

window1=lookup_widget(objet_graphique,"window1");
input7=lookup_widget(objet_graphique,"entry25");
strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY (input7)));
input8=lookup_widget(objet_graphique,"entry26");
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY (input8)));
input9=lookup_widget(objet_graphique,"spinbutton7");
fi.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input9));
input10=lookup_widget(objet_graphique,"entry28");
strcpy(fi.poids,gtk_entry_get_text(GTK_ENTRY (input10)));
input11=lookup_widget(objet_graphique,"entry29");
strcpy(fi.taille,gtk_entry_get_text(GTK_ENTRY (input11)));
input12=lookup_widget(objet_graphique,"entry30");
strcpy(fi.maladies,gtk_entry_get_text(GTK_ENTRY (input12)));
input13=lookup_widget(objet_graphique,"entry31");
strcpy(fi.regime_alimentaire,gtk_entry_get_text(GTK_ENTRY (input13)));
input14=lookup_widget(objet_graphique,"entry33");
strcpy(fi.remarques,gtk_entry_get_text(GTK_ENTRY (input14)));
input15=lookup_widget(objet_graphique,"entry35");
strcpy(fi.id,gtk_entry_get_text(GTK_ENTRY (input15)));
ajouter_fiche(fi);
}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window6;
GtkWidget *treeview4;
window6=lookup_widget(objet_graphique,"window6");
	window6=create_window6();
	gtk_widget_show(window6);

	gtk_widget_hide(window1);



treeview4=lookup_widget(window6,"treeview4");
afficher_fiche(treeview4);
}






void
on_button18_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window7;
window5=lookup_widget(objet_graphique,"window5");
	window7=create_window7();
	gtk_widget_show(window7);
        gtk_widget_destroy(window5);
	

}


void
on_button19_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{/*
GtkWidget *entry41;
GtkWidget *entry42;
GtkWidget *entry43;

GtkWidget *label25;
GtkWidget *jour1; //spinbuttun pour le choix du jour
GtkWidget *mois1; //spinbuttun pour le choix du mois
GtkWidget *annee1; //spinbuttun pour le choix de l’

agenda a;
char ide[30];
label25=lookup_widget( objet_graphique, "label25");
entry42=lookup_widget(objet_graphique, "entry42");
entry43=lookup_widget(objet_graphique, "entry43");
entry41=lookup_widget(objet_graphique,"combobox1");

strcpy(a.notes,gtk_entry_get_text(GTK_ENTRY(entry42)));
strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(entry43)));
strcpy(a.heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX (entry41)));


jour1=lookup_widget(objet_graphique, "spinbutton4");
mois1=lookup_widget(objet_graphique, "spinbutton5");
annee1=lookup_widget(objet_graphique, "spinbutton6");


a.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
a.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
a.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));

modifier_agenda(ide,a);
gtk_label_set_text(GTK_LABEL(label25),"agenda modifiée");*/


}




void
on_button20_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window8;
window5=lookup_widget(objet_graphique,"window5");
	window8=create_window8();
	gtk_widget_show(window8);
        gtk_widget_destroy(window5);
}


void
on_button21_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *entry44;

char ide1[20];
agenda ag;

entry44=lookup_widget(objet_graphique,"entry44");


strcpy(ide1,gtk_entry_get_text(GTK_ENTRY(entry44)));
supprimer_agenda(ide1);

}



void
on_button22_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window8;
GtkWidget *window1;
window8=lookup_widget(objet_graphique,"window8");
	window1=create_window1();
	gtk_widget_show(window1);
        gtk_widget_destroy(window8);
}


void
on_button24_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window6;
GtkWidget *window9;
window6=lookup_widget(objet_graphique,"window6");
	window9=create_window9();
	gtk_widget_show(window9);
        gtk_widget_destroy(window6);
}


void
on_button23_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button25_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry45;

char ide2[20];
fiche fi;

entry45=lookup_widget(objet_graphique,"entry45");


strcpy(ide2,gtk_entry_get_text(GTK_ENTRY(entry45)));
supprimer_fiche(ide2);
}


void
on_button26_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window9;
GtkWidget *window1;
window9=lookup_widget(objet_graphique,"window9");
	window1=create_window1();
	gtk_widget_show(window1);
        gtk_widget_destroy(window9);
}


void
on_button27_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *window1;
window5=lookup_widget(objet_graphique,"window5");
	window1=create_window1();
	gtk_widget_show(window1);
        gtk_widget_destroy(window5);
}


void
on_button28_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window6;
GtkWidget *window1;
window6=lookup_widget(objet_graphique,"window6");
	window1=create_window1();
	gtk_widget_show(window1);
        gtk_widget_destroy(window6);
}

