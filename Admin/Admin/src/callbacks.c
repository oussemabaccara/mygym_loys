#include <string.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "personne.h"
#include "acct.h"
#include "event.h"
#include "offre.h"


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
 GtkWidget *c;

 list=lookup_widget(objet,"list");
 add=create_add();
c=lookup_widget(add,"combobox1");

 gtk_widget_show(add);
 gtk_widget_destroy(list);
 gtk_combo_box_set_active (c,
                          0);
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
  GtkWidget *c;

 list=lookup_widget(objet,"list");
 edit_acc=create_edit_acc();
c=lookup_widget(edit_acc,"comborole");
gtk_combo_box_set_active (c,0);
 gtk_widget_show(edit_acc);
 gtk_widget_destroy(list);
}
//double click
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *e1,*e2,*e3,*s1,*s2,*s3,*c1;
GtkTreeIter iter;
GtkTreeModel *model;
gchar *string;
model=gtk_tree_view_get_model(treeview);
gtk_tree_model_get_iter(model,&iter,path);
gtk_tree_model_get(model,&iter,0,&string,-1);


 GtkWidget *list;
 GtkWidget *edit_acc;
 Personne p;
 list=lookup_widget(treeview,"list");
 edit_acc=create_edit_acc();
 gtk_widget_show(edit_acc);
e1=lookup_widget(edit_acc,"edit_id");
e2=lookup_widget(edit_acc,"edit_last");
e3=lookup_widget(edit_acc,"edit_first");
 s1=lookup_widget(edit_acc, "spinday");
 s2=lookup_widget(edit_acc, "spinmonth");
 s3=lookup_widget(edit_acc, "spinyear");
 c1=lookup_widget(edit_acc,"comborole");
p=get_personne(string);
gtk_entry_set_text(GTK_ENTRY(e1),p.id);
gtk_entry_set_text(GTK_ENTRY(e2),p.nom);
gtk_entry_set_text(GTK_ENTRY(e3),p.prenom);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(s1),p.date.jour);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(s2),p.date.mois);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(s3),p.date.annee);
 gtk_combo_box_prepend_text (GTK_COMBO_BOX (c1), _(p.role));
 gtk_widget_destroy(list);
 gtk_combo_box_set_active (c1,0);
}

void
on_edit_acc_show                       (GtkWidget       *widget,
                                        gpointer         user_data)
{

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
 gtk_combo_box_prepend_text (GTK_COMBO_BOX (combobox), _(p.role));
 GtkWidget *c;
 c=lookup_widget(edit_acc,"comborole");
 gtk_combo_box_set_active (c,0);
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
 GtkWidget *treeview;

 Admin=lookup_widget(objet,"Admin");
 activ=create_activ();

 gtk_widget_show(activ);
 treeview=lookup_widget(activ,"treeactiv");
 afficher_event(treeview);
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
 GtkWidget *c;
 c=lookup_widget(activ_add,"combomin_ev");
 gtk_combo_box_set_active (c,0);
}

// ajouter un ev

void
on_add_activ_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 event e;

 GtkWidget *name;
 GtkWidget *des;
 GtkWidget *spind;
 GtkWidget *spinm;
 GtkWidget *spiny;
 GtkWidget *spinh;
 GtkWidget *combomin;
 GtkWidget *nb_ev;
 GtkWidget *nbm_ev;
 GtkWidget *num_ev;
 GtkWidget *activ_add;
 GtkWidget *output;



 activ_add=lookup_widget(objet,"activ_add");

 name=lookup_widget(objet,"name_ev");
 des=lookup_widget(objet,"des_ev");
 spind=lookup_widget(objet,"spind_ev");
 spinm=lookup_widget(objet,"spinm_ev");
 spiny=lookup_widget(objet,"spiny_ev");
 spinh=lookup_widget(objet,"spinh_ev");
 combomin=lookup_widget(objet,"combomin_ev");
 nb_ev=lookup_widget(objet,"nb_ev");
 nbm_ev=lookup_widget(objet,"nbm_ev");
 num_ev=lookup_widget(objet,"num_ev");



 strcpy(e.num,gtk_entry_get_text(GTK_ENTRY(num_ev)));
 strcpy(e.description,gtk_entry_get_text(GTK_ENTRY(des)));
 strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(name)));
 e.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spind));
 e.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinm));
 e.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spiny));
 e.heure.h=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinh));
 strcpy(e.heure.min,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomin)));
 strcpy(e.nombre,gtk_entry_get_text(GTK_ENTRY(nb_ev)));
 strcpy(e.nombremax,gtk_entry_get_text(GTK_ENTRY(nbm_ev)));

 if (existev(e.num)!=1)
 ajout_ev(e);
}

//

void
on_add_activ_return_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *activ_add;
 GtkWidget *treeview;

 activ_add=lookup_widget(objet,"activ_add");
 activ=create_activ();

 gtk_widget_show(activ);
 treeview=lookup_widget(activ,"treeactiv");
 afficher_event(treeview);
 gtk_widget_destroy(activ_add); 
}

//double click treeview event
void
on_treeactiv_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkWidget *entry;
 GtkWidget *entry2;
 GtkWidget *entry3;
 GtkWidget *entry4;
 GtkWidget *entry5;
GtkTreeIter iter;
GtkTreeModel *model;
gchar *string,*string1,*string2,*string3,*string4,*string5;
model=gtk_tree_view_get_model(treeview);
gtk_tree_model_get_iter(model,&iter,path);
gtk_tree_model_get(model,&iter,0,&string,-1);
gtk_tree_model_get(model,&iter,1,&string1,-1);
gtk_tree_model_get(model,&iter,2,&string2,-1);
gtk_tree_model_get(model,&iter,3,&string3,-1);
gtk_tree_model_get(model,&iter,4,&string4,-1);
gtk_tree_model_get(model,&iter,5,&string5,-1);


 GtkWidget *activ;
 GtkWidget *activ_edit;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *h;
 GtkWidget *combobox;
 event e;
 activ=lookup_widget(treeview,"activ");
 activ_edit=create_activ_edit();
 gtk_widget_show(activ_edit);
entry=lookup_widget(activ_edit,"numedev");
entry2=lookup_widget(activ_edit,"nameedev");
entry3=lookup_widget(activ_edit,"desedev");
entry4=lookup_widget(activ_edit,"nbedev");
entry5=lookup_widget(activ_edit,"nbmedev");
 jour=lookup_widget(activ_edit, "edjev");
 mois=lookup_widget(activ_edit, "edmev");
 annee=lookup_widget(activ_edit, "edyev");
 h=lookup_widget(activ_edit, "edhev");
 combobox=lookup_widget(activ_edit,"comboedev");
gtk_entry_set_text(GTK_ENTRY(entry),string);
gtk_entry_set_text(GTK_ENTRY(entry2),string1);
gtk_entry_set_text(GTK_ENTRY(entry3),string2);
gtk_entry_set_text(GTK_ENTRY(entry4),string5);
e=get_event(string);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),e.date.jour);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),e.date.mois);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),e.date.annee);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(h),e.heure.h);
gtk_entry_set_text(GTK_ENTRY(entry5),e.nombremax);
 gtk_combo_box_prepend_text (GTK_COMBO_BOX (combobox), _(e.heure.min));
 gtk_widget_destroy(activ);
 GtkWidget *c;
 c=lookup_widget(activ_edit,"comboedev");
 gtk_combo_box_set_active (c,0);
}


//

void
on_edit_ev_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
 event e;

 GtkWidget *name;
 GtkWidget *des;
 GtkWidget *spind;
 GtkWidget *spinm;
 GtkWidget *spiny;
 GtkWidget *spinh;
 GtkWidget *combomin;
 GtkWidget *nb_ev;
 GtkWidget *nbm_ev;
 GtkWidget *num_ev;
 GtkWidget *activ_edit;
 GtkWidget *output;



 activ_edit=lookup_widget(objet,"activ_edit");

 name=lookup_widget(objet,"nameedev");
 des=lookup_widget(objet,"desedev");
 spind=lookup_widget(objet,"edjev");
 spinm=lookup_widget(objet,"edmev");
 spiny=lookup_widget(objet,"edyev");
 spinh=lookup_widget(objet,"edhev");
 combomin=lookup_widget(objet,"comboedev");
 nb_ev=lookup_widget(objet,"nbedev");
 nbm_ev=lookup_widget(objet,"nbmedev");
 num_ev=lookup_widget(objet,"numedev");



 strcpy(e.num,gtk_entry_get_text(GTK_ENTRY(num_ev)));
 strcpy(e.description,gtk_entry_get_text(GTK_ENTRY(des)));
 strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(name)));
 e.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spind));
 e.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinm));
 e.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spiny));
 e.heure.h=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinh));
 strcpy(e.heure.min,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomin)));
 strcpy(e.nombre,gtk_entry_get_text(GTK_ENTRY(nb_ev)));
 strcpy(e.nombremax,gtk_entry_get_text(GTK_ENTRY(nbm_ev)));

 suppev(e.num);
 ajout_ev(e);
}

//
void
on_delev_clicked                       (GtkButton       *objet,
                                        gpointer         user_data)
{
 event e;
 GtkWidget *num_ev;
 GtkWidget *activ_edit;
 GtkWidget *output;



 activ_edit=lookup_widget(objet,"activ_edit");
 num_ev=lookup_widget(objet,"numedev");
 strcpy(e.num,gtk_entry_get_text(GTK_ENTRY(num_ev)));
 suppev(e.num);
}

//

void
on_edev_return_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *activ;
 GtkWidget *activ_edit;
 GtkWidget *treeview;

 activ_edit=lookup_widget(button,"activ_edit");
 activ=create_activ();

 gtk_widget_show(activ);
 treeview=lookup_widget(activ,"treeactiv");
 afficher_event(treeview);
 gtk_widget_destroy(activ_edit);
}

// Gestion des Activités -> modifier


void
on_activ_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *activ;
 GtkWidget *activ_edit;
 activ=lookup_widget(objet,"activ");
 activ_edit=create_activ_edit();
 gtk_widget_show(activ_edit);
 gtk_widget_destroy(activ);
 GtkWidget *c;
 c=lookup_widget(activ_edit,"comboedev");
 gtk_combo_box_set_active (c,0);
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
 GtkWidget *tree;
 tree=lookup_widget(stats,"stats_treeview");
 afficher_bpersonne(tree);
}



// Espace Admin -> Gestion des offres
void
on_admin_deals_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *tree;
 GtkWidget *deals;
 GtkWidget *Admin;

 Admin=lookup_widget(objet,"Admin");
 deals=create_deals();
 tree=lookup_widget(deals,"deals_treeview");
 gtk_widget_show(deals);
 afficher_offre(tree);
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
 GtkWidget *deals;
 GtkWidget *deals_add;

 deals=lookup_widget(objet,"deals");
 deals_add=create_deals_add();

 gtk_widget_show(deals_add);
 gtk_widget_destroy(deals);
}

//double click treeview
void
on_deals_treeview_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkWidget *entry;
 GtkWidget *entry2;
 GtkWidget *entry3;
GtkTreeIter iter;
GtkTreeModel *model;
gchar *string,*string1,*string2;
model=gtk_tree_view_get_model(treeview);
gtk_tree_model_get_iter(model,&iter,path);
gtk_tree_model_get(model,&iter,0,&string,-1);
gtk_tree_model_get(model,&iter,1,&string1,-1);
gtk_tree_model_get(model,&iter,2,&string2,-1);


 GtkWidget *deals;
 GtkWidget *deals_edit;
 offre o;
 deals=lookup_widget(treeview,"deals");
 deals_edit=create_deals_edit();
 gtk_widget_show(deals_edit);
entry=lookup_widget(deals_edit,"numeddl");
entry2=lookup_widget(deals_edit,"deseddl");
entry3=lookup_widget(deals_edit,"preddl");
gtk_entry_set_text(GTK_ENTRY(entry),string);
gtk_entry_set_text(GTK_ENTRY(entry2),string1);
gtk_entry_set_text(GTK_ENTRY(entry3),string2);
 gtk_widget_destroy(deals);
}

// Gestion des offres -> modifier
void
on_deals_upd_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *deals;
 GtkWidget *deals_edit;

 deals=lookup_widget(objet,"deals");
 deals_edit=create_deals_edit();

 gtk_widget_show(deals_edit);
 gtk_widget_destroy(deals);
}



void
on_adddeal_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
 offre o;
  GtkWidget *deals;
 GtkWidget *e1;
 GtkWidget *e2;
 GtkWidget *e3;
 GtkWidget *output;



 deals=lookup_widget(button,"deals_add");

 e1=lookup_widget(button,"numaddl");
 e2=lookup_widget(button,"desaddl");
 e3=lookup_widget(button,"praddl");



 strcpy(o.nbre,gtk_entry_get_text(GTK_ENTRY(e1)));
 strcpy(o.description,gtk_entry_get_text(GTK_ENTRY(e2)));
 strcpy(o.prix,gtk_entry_get_text(GTK_ENTRY(e3)));
 if (existof(o.nbre)!=1)
 ajout_of(o);
}


void
on_adddeal_return_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *tree;
 GtkWidget *deals;
 GtkWidget *deals_add;

 deals_add=lookup_widget(button,"deals_add");
 deals=create_deals();
 tree=lookup_widget(deals,"deals_treeview");
 gtk_widget_show(deals);
 afficher_offre(tree);
 gtk_widget_destroy(deals_add);
}


void
on_editdeal_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
 offre o;
  GtkWidget *deals;
 GtkWidget *e1;
 GtkWidget *e2;
 GtkWidget *e3;
 GtkWidget *output;



 deals=lookup_widget(button,"deals_edit");

 e1=lookup_widget(button,"numeddl");
 e2=lookup_widget(button,"deseddl");
 e3=lookup_widget(button,"preddl");



 strcpy(o.nbre,gtk_entry_get_text(GTK_ENTRY(e1)));
 strcpy(o.description,gtk_entry_get_text(GTK_ENTRY(e2)));
 strcpy(o.prix,gtk_entry_get_text(GTK_ENTRY(e3)));
 suppof(o.nbre);
 ajout_of(o);
}


void
on_suppdeal_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{offre o;
GtkWidget *deals;
 GtkWidget *e1;
deals=lookup_widget(button,"deals_edit");
 e1=lookup_widget(button,"numeddl");
 strcpy(o.nbre,gtk_entry_get_text(GTK_ENTRY(e1)));
 suppof(o.nbre);
}


void
on_editdeal_return_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *tree;
 GtkWidget *deals;
 GtkWidget *deals_edit;

 deals_edit=lookup_widget(button,"deals_edit");
 deals=create_deals();
 tree=lookup_widget(deals,"deals_treeview");
 gtk_widget_show(deals);
 afficher_offre(tree);
 gtk_widget_destroy(deals_edit);
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




















