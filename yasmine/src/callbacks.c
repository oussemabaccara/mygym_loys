#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fiche.h"
#include "agenda.h"


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *treeview1;
window2=lookup_widget(objet_graphique,"window2");
	window2=create_window2();
	gtk_widget_show(window2);

	gtk_widget_hide(window1);



treeview1=lookup_widget(window2,"treeview1");
afficher_fiche(treeview1);
}


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
fiche fi;
GtkWidget *input7,*input8,*input9,*input10,*input11,*input12,*input13,*input14,*input15;
GtkWidget *window1;

window1=lookup_widget(objet_graphique,"window1");
input7=lookup_widget(objet_graphique,"entry1");
strcpy(fi.nom,gtk_entry_get_text(GTK_ENTRY (input7)));
input8=lookup_widget(objet_graphique,"entry2");
strcpy(fi.prenom,gtk_entry_get_text(GTK_ENTRY (input8)));
input9=lookup_widget(objet_graphique,"spinbutton1");
fi.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input9));
input10=lookup_widget(objet_graphique,"entry3");
strcpy(fi.poids,gtk_entry_get_text(GTK_ENTRY (input10)));
input11=lookup_widget(objet_graphique,"entry4");
strcpy(fi.taille,gtk_entry_get_text(GTK_ENTRY (input11)));
input12=lookup_widget(objet_graphique,"entry5");
strcpy(fi.maladies,gtk_entry_get_text(GTK_ENTRY (input12)));
input13=lookup_widget(objet_graphique,"entry6");
strcpy(fi.regime_alimentaire,gtk_entry_get_text(GTK_ENTRY (input13)));
input14=lookup_widget(objet_graphique,"entry7");
strcpy(fi.remarques,gtk_entry_get_text(GTK_ENTRY (input14)));
input15=lookup_widget(objet_graphique,"entry8");
strcpy(fi.id,gtk_entry_get_text(GTK_ENTRY (input15)));
ajouter_fiche(fi);
}


void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window3;
GtkWidget *treeview2;
window3=lookup_widget(objet_graphique,"window3");
	window3=create_window3();
	gtk_widget_show(window3);

	gtk_widget_hide(window1);



treeview2=lookup_widget(window3,"treeview2");
afficher_agenda(treeview2);
}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
agenda ag;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;
GtkWidget *window1;

window1=lookup_widget(objet_graphique,"window1");
input1=lookup_widget(objet_graphique,"spinbutton2");
ag.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input1));
input2=lookup_widget(objet_graphique,"spinbutton3");
ag.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
input3=lookup_widget(objet_graphique,"spinbutton4");
ag.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input3));
input4=lookup_widget(objet_graphique,"combobox1");
strcpy(ag.heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input4)));
input5=lookup_widget(objet_graphique,"entry9");
strcpy(ag.notes,gtk_entry_get_text(GTK_ENTRY (input5)));
input6=lookup_widget(objet_graphique,"entry10");
strcpy(ag.id,gtk_entry_get_text(GTK_ENTRY (input6)));


ajouter_agenda(ag);
}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *window1;
window2=lookup_widget(objet_graphique,"window2");
	window1=create_window1();
	gtk_widget_show(window1);
        gtk_widget_destroy(window2);
}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *window3;
GtkWidget *window1;
window3=lookup_widget(objet_graphique,"window3");
	window1=create_window1();
	gtk_widget_show(window1);
        gtk_widget_destroy(window3);
}


void
on_button8_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window4;
window1=lookup_widget(objet_graphique,"window1");
	window4=create_window4();
	gtk_widget_show(window4);
        gtk_widget_destroy(window1);
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry18;

char ide2[20];
fiche fi;

entry18=lookup_widget(objet_graphique,"entry18");


strcpy(ide2,gtk_entry_get_text(GTK_ENTRY(entry18)));
supprimer_fiche(ide2);
}


void
on_button9_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window5;
window1=lookup_widget(objet_graphique,"window1");
	window5=create_window5();
	gtk_widget_show(window5);
        gtk_widget_destroy(window1);
}


void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry19;

char ide1[20];
agenda ag;

entry19=lookup_widget(objet_graphique,"entry19");



strcpy(ide1,gtk_entry_get_text(GTK_ENTRY(entry19)));
supprimer_agenda(ide1);
}




void
on_button12_clicked                    (GtkWidget       *objet_graphique,
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
on_button13_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *window4;
GtkWidget *window1;
window4=lookup_widget(objet_graphique,"window4");
	window1=create_window1();
	gtk_widget_show(window1);
        gtk_widget_destroy(window4);
}

