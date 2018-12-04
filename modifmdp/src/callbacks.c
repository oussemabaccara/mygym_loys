#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"


void
on_button1_clicked(GtkButton *objet_graphique,gpointer user_data)
{GtkWidget *input1;
 GtkWidget *input2;
 GtkWidget *input3;
 GtkWidget *output;
 GtkWidget *entry1;
 GtkWidget *entry2;
 GtkWidget *entry3;
 GtkWidget *label4;
 char erreur[50],erreur1[50],erreur2[50],msg[50];
 char password[30],mdp1[30],mdp2[30];
 strcpy(erreur,"L'ancien mot de passe est invalide et les nouveaux mot de passes ne sont pas identiques");
 strcpy(erreur1,"L'ancien mot de passe est invalide");
 strcpy(erreur2,"Les nouveaux mot de passes ne sont pas identiques");
 strcpy(msg,"Votre mot de passe a été changé avec succes");
 input1=lookup_widget(objet_graphique,"entry1");
 input1=lookup_widget(objet_graphique,"entry2");
 input1=lookup_widget(objet_graphique,"entry3");
 strcpy(password,gtk_entry_get_text(GTK_ENTRY(input1)));
 strcpy(mdp1,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(mdp2,gtk_entry_get_text(GTK_ENTRY(input3)));
 output=lookup_widget(objet_graphique,"label4");
 if (verif(password)==1 && strcmp(mdp1,mdp2)==0)
	{
		modif(password,mdp1);
		gtk_label_set_text(GTK_LABEL(output),msg);
	}
 else if (verif(password)==1 && strcmp(mdp1,mdp2)!=0)
		gtk_label_set_text(GTK_LABEL(output),erreur2);
 else if (verif(password)!=1 && strcmp(mdp1,mdp2)==0)
		gtk_label_set_text(GTK_LABEL(output),erreur1);
 else 
		gtk_label_set_text(GTK_LABEL(output),erreur);	 

}

