#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "greeting.h"


void
on_button1_clicked     (GtkWidget   *objet_graphique,
                                        gpointer  user_data)
{
GtkWidget *Coach;
GtkWidget *Sport;
GtkWidget *treeview1;
Coach=lookup_widget(objet_graphique,"Coach");
Sport=create_Sport ();
gtk_widget_show(Sport);
gtk_widget_destroy(Coach);
treeview1=lookup_widget(Sport,"treeview500");

afficher_amine(treeview1); 
}

void
on_button6_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Coach;
GtkWidget *Sport;

Sport=lookup_widget(objet_graphique,"Sport");
Coach=create_Coach ();
gtk_widget_show(Coach);
gtk_widget_hide(Sport);
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
GtkWidget *Sport;
GtkWidget *treeview1;
Ajout=lookup_widget(objet_graphique,"Ajout");
Sport=create_Sport ();
gtk_widget_show(Sport);
gtk_widget_hide(Ajout);
treeview1=lookup_widget(Sport,"treeview500");

afficher_amine(treeview1);
}


void
on_button8_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
Personnet p;
GtkWidget *Nombredeplace;
GtkWidget *Nombredeplacemax;
GtkWidget *input1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox1, *combobox2;
GtkWidget *Ajout;
GtkWidget *output;

Ajout=lookup_widget(objet_graphique,"Ajout");

Nombredeplace=lookup_widget(objet_graphique, "spinbutton502");
Nombredeplacemax=lookup_widget(objet_graphique, "spinbutton503");

jour=lookup_widget(objet_graphique, "spinbutton504");
mois=lookup_widget(objet_graphique, "spinbutton505");
annee=lookup_widget(objet_graphique, "spinbutton506");

combobox1=lookup_widget(objet_graphique,"combobox500");
combobox2=lookup_widget(objet_graphique,"combobox502");


output=lookup_widget(objet_graphique,"label517");
input1=lookup_widget(objet_graphique,"entry500");
strcpy(p.Id,gtk_entry_get_text(GTK_ENTRY(input1)));

p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


 p.Nombredeplace=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplace));
 p.Nombredeplacemax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplacemax));

strcpy(p.Cours,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(p.Heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));


ajouter_amine(p);
gtk_label_set_text(GTK_LABEL(output),"Cours ajouté!");



}


void
on_button4_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
GtkWidget *Sport;

Sport=lookup_widget(objet_graphique,"Sport");
Ajout=create_Ajout ();
gtk_widget_show(Ajout);
gtk_widget_hide(Sport);
}


void
on_treeview1_remove                    (GtkContainer    *container,
                                        GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void
on_button9_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button10_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button12_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_list_upd_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
GtkWidget *mod;

Ajout=lookup_widget(objet_graphique,"Ajout");
mod=create_mod ();
gtk_widget_show(mod);
gtk_widget_hide(Ajout);

}

              //bouton supprimer
void
on_des_acc_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

Personnet p;

 GtkWidget *input2;
 GtkWidget *Nombredeplace;
 GtkWidget *Nombredeplacemax;
 GtkWidget *combobox4,*combobox5;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *mod;
char Id[30];
 //GtkWidget *output;
mod=lookup_widget(objet_graphique,"mod");
 input2=lookup_widget(objet_graphique,"entry502");

 strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input2)));
aminesupprimer(Id);


}

             //bouton mofidier
void
on_EDIT_clicked                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
Personnet p;

 GtkWidget *input2;
 GtkWidget *Nombredeplace;
 GtkWidget *Nombredeplacemax;
 GtkWidget *combobox4,*combobox5;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *mod;
 //GtkWidget *output;
char Id[30];
mod=lookup_widget(objet_graphique,"mod");


Nombredeplace=lookup_widget(objet_graphique, "spinbutton511");
Nombredeplacemax=lookup_widget(objet_graphique, "spinbutton512");

jour=lookup_widget(objet_graphique, "spinbutton508");
mois=lookup_widget(objet_graphique, "spinbutton509");
annee=lookup_widget(objet_graphique, "spinbutton510");

combobox4=lookup_widget(objet_graphique,"combobox504");
combobox5=lookup_widget(objet_graphique,"combobox505");
input2=lookup_widget(objet_graphique,"entry502");
 strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.Id,gtk_entry_get_text(GTK_ENTRY(input2)));

p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

 p.Nombredeplace=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplace));
 p.Nombredeplacemax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplacemax));


strcpy(p.Cours,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
strcpy(p.Heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));
 aminesupprimer(Id);
 ajouter_amine(p);


}

            
          //boutton chercher
void
on_search_acc_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char Id[30];
Personnet p;

 GtkWidget *input2;
 GtkWidget *Nombredeplace;
 GtkWidget *Nombredeplacemax;
 GtkWidget *combobox4,*combobox5;
 GtkWidget *jour;
 GtkWidget *mois;
 GtkWidget *annee;
 GtkWidget *mod;
 //GtkWidget *output;

mod=lookup_widget(objet_graphique,"mod");
 input2=lookup_widget(objet_graphique,"entry502");
Nombredeplace=lookup_widget(objet_graphique, "spinbutton511");
Nombredeplacemax=lookup_widget(objet_graphique, "spinbutton512");

jour=lookup_widget(objet_graphique, "spinbutton508");
mois=lookup_widget(objet_graphique, "spinbutton509");
annee=lookup_widget(objet_graphique, "spinbutton510");

combobox4=lookup_widget(objet_graphique,"combobox504");
combobox5=lookup_widget(objet_graphique,"combobox505");
strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input2)));

 p=chercheramine(Id);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),p.date.jour);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),p.date.mois);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),p.date.annee);


 gtk_spin_button_set_value(GTK_SPIN_BUTTON(Nombredeplace),p.Nombredeplace);
 gtk_spin_button_set_value(GTK_SPIN_BUTTON(Nombredeplacemax),p.Nombredeplacemax);

gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _(p.Cours));
gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _(p.Heure));

}

