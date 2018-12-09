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
treeview1=lookup_widget(Sport,"treeview1");

afficher_personne(treeview1); 
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
treeview1=lookup_widget(Sport,"treeview1");

afficher_personne(treeview1);
}


void
on_button8_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
Personne p;
GtkWidget *Nombredeplace;
GtkWidget *Nombredeplacemax;
GtkWidget *Id;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox1, *combobox2;
GtkWidget *Ajout;
GtkWidget *output;

Ajout=lookup_widget(objet_graphique,"Ajout");
Id=lookup_widget(objet_graphique, "spinbutton1");
Nombredeplace=lookup_widget(objet_graphique, "spinbutton2");
Nombredeplacemax=lookup_widget(objet_graphique, "spinbutton3");

jour=lookup_widget(objet_graphique, "spinbutton4");
mois=lookup_widget(objet_graphique, "spinbutton5");
annee=lookup_widget(objet_graphique, "spinbutton6");

combobox1=lookup_widget(objet_graphique,"combobox1");
combobox2=lookup_widget(objet_graphique,"combobox2");


output=lookup_widget(objet_graphique,"label17");

p.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
 p.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
 p.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

p.Id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Id));
 p.Nombredeplace=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplace));
 p.Nombredeplacemax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nombredeplacemax));

strcpy(p.Cours,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(p.Heure,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));


ajouter_personne(p);
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

