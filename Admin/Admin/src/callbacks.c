#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "personne.h"
#include "acct.h"
#include "activ.h"


// Login
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


// Gestion des comptes -> retour
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



// Gestion des comptes -> ajouter
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



// Ajouter un compte -> Ajouter
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
 
 // Condition manquante!!(cases non vides)
 int e;
 e=exist(p.id);
 if(e==1)
	 gtk_label_set_text(GTK_LABEL(output),"L'identifiant existe");
 else
	{
	 ajouter_personne(p);
	 gtk_label_set_text(GTK_LABEL(output),"Ajout réussi!");
	}
	 
}



// Gestion des comptes -> modifier
void
on_list_upd_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *list;
 GtkWidget *edit_acc;

 list=lookup_widget(objet,"list");
 edit_acc=create_edit_acc();

 gtk_widget_show(edit_acc);
 gtk_widget_destroy(list);
}

// Modifier un compte -> Chercher
void
on_search_acc_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
 char id[30];
 Personne p;

 GtkWidget *input1, *input2,*input3;
 GtkWidget *combobox;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *edit_acc;
 GtkWidget *output;

 edit_acc=lookup_widget(objet,"edit_acc");

 input1=lookup_widget(objet,"edit_id");
 input2=lookup_widget(objet,"edit_last");
 input3=lookup_widget(objet,"edit_first");

 jour=lookup_widget(objet, "spinday");
 mois=lookup_widget(objet, "spinmonth");
 annee=lookup_widget(objet, "spinyear");

 combobox=lookup_widget(objet,"comborole");

 strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
 p=get_personne(id);
 gtk_entry_set_text (GTK_ENTRY(input2),p.nom);
 gtk_entry_set_text (GTK_ENTRY(input3),p.prenom);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),p.date.jour);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),p.date.mois);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),p.date.annee);
 gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _(p.role));
}

// Modifier un compte -> Modifier

void
on_EDIT_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
 Personne p;

 GtkWidget *input1, *input2,*input3;
 GtkWidget *combobox;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *edit_acc;
 GtkWidget *output;
 char id[30];



 edit_acc=lookup_widget(objet,"edit_acc");

 input1=lookup_widget(objet,"edit_id");
 input2=lookup_widget(objet,"edit_last");
 input3=lookup_widget(objet,"edit_first");

 jour=lookup_widget(objet, "spinday");
 mois=lookup_widget(objet, "spinmonth");
 annee=lookup_widget(objet, "spinyear");

 combobox=lookup_widget(objet,"comborole");

 strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));

 p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

 strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
 dis_acc(id);
 ajouter_personne(p);
	 
}

// Modifier un compte -> Désactiver

void
on_des_acc_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
 Personne p;

 GtkWidget *input1, *input2,*input3;
 GtkWidget *combobox;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *edit_acc;
 GtkWidget *output;
 char id[30];

 edit_acc=lookup_widget(objet,"edit_acc");

 input1=lookup_widget(objet,"edit_id");

 strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

 dis_acc(id); 
}

// Modifier un compte -> retour
void
on_edit_acc_return_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *edit_acc;
 GtkWidget *list;
 GtkWidget *treeview1;

 edit_acc=lookup_widget(objet,"edit_acc");
 list=create_list();

 gtk_widget_show(list);
 treeview1=lookup_widget(list,"treeview1");
 afficher_personne(treeview1);
 gtk_widget_destroy(edit_acc);
}

// Espace Admin -> Gestion des activités
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



// Gestion des Activités -> retour
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



// Gestion des Activités -> ajouter
void
on_activ_add_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *activ_add;

 activ=lookup_widget(objet,"activ");
 activ_add=create_activ_add();

 gtk_widget_show(activ_add);
 gtk_widget_destroy(activ); 
}


void
on_add_activ_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 activ a;

 GtkWidget *activ;
 GtkWidget *jour;
 GtkWidget *spinH;
 GtkWidget *min;
 GtkWidget *duree;
 GtkWidget *activ_add;
 GtkWidget *output;



 activ_add=lookup_widget(objet,"activ_add");

 activ=lookup_widget(objet,"comboactiv");
 jour=lookup_widget(objet,"combojour");
 spinH=lookup_widget(objet,"spinH");
 min=lookup_widget(objet,"combomin");
 duree=lookup_widget(objet,"comboduree");



 strcpy(a.type,gtk_entry_get_text(GTK_ENTRY(activ)));
 strcpy(a.jour,gtk_entry_get_text(GTK_ENTRY(jour)));
 a.horH=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinH));
 strcpy(a.hormin,gtk_entry_get_text(GTK_ENTRY(min)));
 strcpy(a.dur,gtk_entry_get_text(GTK_ENTRY(duree)));
 
 activadd(a);
}


void
on_add_activ_return_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

}

// Gestion des Activités -> modifier
void
on_activ_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 
}



// Espace Admin -> Rapports et statistiques
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



// Espace Admin -> Gestion des offres
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



// Gestion des offres -> retour
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



// Gestion des offres -> ajouter
void
on_deals_add_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

}



// Gestion des offres -> modifier
void
on_deals_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

}



// Rapports et statistiques -> retour
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




