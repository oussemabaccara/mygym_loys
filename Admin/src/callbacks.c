#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "personne.h"



//Login
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



// Espace Admin -> Gestion des comptes
void
on_admin_list_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *Admin;
 GtkWidget *treeview1;

 Admin=lookup_widget(objet,"Admin");
 list=create_list();
 treeview1=lookup_widget(list,"treeview1");

 gtk_widget_destroy(Admin);
 gtk_widget_show(list);
 afficher_personne(treeview1);
}



// Ajouter un compte -> retour
void
on_add_return_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *add, *list;
 GtkWidget *treeview1; 

 add=lookup_widget(objet,"add");
 list=create_list();
 treeview1=lookup_widget(list,"treeview1");

 gtk_widget_destroy(add);
 gtk_widget_show(list);
 afficher_personne(treeview1);
}



//Ajouter un compte -> Ajouter
void
on_add_ajouter_clicked                 (GtkWidget       *objet,
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

 output=lookup_widget(objet,"label15");



 strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));

 p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

 strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
 
 //Conditions manquantes!!(Identifiant unique && cases non vides)	 
 	ajouter_personne(p);
 	gtk_label_set_text(GTK_LABEL(output),"Ajout réussi!");

}



//Liste des Adherents -> retour
void
on_list_return_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *Admin;

 list=lookup_widget(objet,"list");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(list);
}



//Liste des Adherents -> ajouter
void
on_list_add_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *add;

 list=lookup_widget(objet,"list");
 add=create_add();

 gtk_widget_show(add);
 gtk_widget_destroy(list);
}




void
on_activ_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *Admin;

 activ=lookup_widget(objet,"activ");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(activ);
}




void
on_stats_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *stats;
 GtkWidget *Admin;

 stats=lookup_widget(objet,"stats");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(stats);
}




void
on_deals_return_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *deals;
 GtkWidget *Admin;

 deals=lookup_widget(objet,"deals");
 Admin=create_Admin();

 gtk_widget_show(Admin);
 gtk_widget_destroy(deals);
}




void
on_admin_activ_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *Admin;

 Admin=lookup_widget(objet,"Admin");
 activ=create_activ();

 gtk_widget_show(activ);
 gtk_widget_destroy(Admin);
}




void
on_admin_stats_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *stats;
 GtkWidget *Admin;

 Admin=lookup_widget(objet,"Admin");
 stats=create_stats();

 gtk_widget_show(stats);
 gtk_widget_destroy(Admin);
}




void
on_admin_deals_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *deals;
 GtkWidget *Admin;

 Admin=lookup_widget(objet,"Admin");
 deals=create_deals();

 gtk_widget_show(deals);
 gtk_widget_destroy(Admin);
}










