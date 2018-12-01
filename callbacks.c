#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "personne.h"

void on_button_clicked(GtkWidget       *objet_graphique,gpointer         user_data)
{
 GtkWidget *input1;
 GtkWidget *input2;
 GtkWidget *output;
 GtkWidget *Login;
 GtkWidget *Admin;
 char nom[30],mdp[30];
 int v;

 input1=lookup_widget(objet_graphique,"entry1");
 input2=lookup_widget(objet_graphique,"entry2");
 output=lookup_widget(objet_graphique,"Error");
 strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input2)));
 v=verifier(nom,mdp);
 switch(v)
 	{case 1:
 	 	{
		 Login=lookup_widget(objet_graphique,"Login");
		 Admin=create_Admin();
		 gtk_widget_show(Admin);
		 gtk_widget_hide(Login);
		}
	 case 0:
 	 	 gtk_label_set_text(GTK_LABEL(output),"Erreur: verifier login ou mot de passe");
 	}
}


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *Admin;
 
 Admin=lookup_widget(objet_graphique,"Admin");
 list=create_list();
 gtk_widget_show(list);
 gtk_widget_destroy(Admin);
}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *Admin;
 Admin=lookup_widget(objet_graphique,"Admin");
 gtk_widget_destroy(Admin);
}

void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *add, *list;

 add=lookup_widget(objet,"add");
 list=create_list();

 gtk_widget_show(list);
 gtk_widget_destroy(add);
}

void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
 Personne p;

 GtkWidget *input1, *input2,*input3;
 GtkWidget *combobox1;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *add;
 GtkWidget *output;

 add=lookup_widget(objet,"add");

 input1=lookup_widget(objet,"add_ent_id");
 input2=lookup_widget(objet,"add_ent_nom");
 input3=lookup_widget(objet,"add_ent_prenom");

 jour=lookup_widget(objet, "spinbutton1");
 mois=lookup_widget(objet, "spinbutton2");
 annee=lookup_widget(objet, "spinbutton3");

 combobox1=lookup_widget(objet,"combobox1");

 strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));

 p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
 strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

 ajouter_personne(p);

 output=lookup_widget(objet,"label15");
 gtk_label_set_text(GTK_LABEL(output),"Ajout réussi");
}

void on_button6_clicked(GtkWidget *objet_graphique,gpointer user_data)
	{
	 
	}
void on_button7_clicked(GtkWidget *objet_graphique,gpointer user_data)
	{
	 GtkWidget *list;
 	 GtkWidget *Admin;
 
 	 list=lookup_widget(objet_graphique,"list");
	 Admin=create_Admin();

 	 gtk_widget_show(Admin);
 	 gtk_widget_destroy(list);
	}
void on_button8_clicked(GtkWidget *objet_graphique,gpointer user_data)
	{
	 GtkWidget *list;
 	 GtkWidget *add;
 
 	 list=lookup_widget(objet_graphique,"list");
	 add=create_add();

 	 gtk_widget_show(add);
 	 gtk_widget_destroy(list);
	}
void on_button9_clicked(GtkWidget *objet_graphique,gpointer user_data)
	{
	 
	}
void on_button10_clicked(GtkWidget *objet_graphique,gpointer user_data)
	{
	 GtkWidget *list;
 	 GtkWidget *add;
 
 	 add=lookup_widget(objet_graphique,"add");
	 list=create_list();

 	 gtk_widget_show(list);
 	 gtk_widget_destroy(add);
	}
void on_button11_clicked(GtkWidget *objet_graphique,gpointer user_data)
	{
	 
	}









