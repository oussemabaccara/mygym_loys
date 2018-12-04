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
#include "auth.h"


void
on_button1_clicked(GtkWidget  *objet_graphique,gpointer user_data)
{
 GtkWidget *input1;
 GtkWidget *input2;
 GtkWidget *output;
 GtkWidget *window1;
 GtkWidget *admin;
 GtkWidget *adherant;
 GtkWidget *coach;
 GtkWidget *generaliste;
 GtkWidget *nutritionniste;
 GtkWidget *kinesitherapeute;
 GtkWidget *label9;
 char login[20];
 char password[20];
 char erreur1[50];
 char erreur2[50];
 int s;
	strcpy(erreur1,"vous n'avez aucun espace !!! ");
	strcpy(erreur2,"erreur d'authentification" );
	input1=lookup_widget(objet_graphique,"entry1");
	input2=lookup_widget(objet_graphique,"entry2");
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
        output=lookup_widget(objet_graphique,"label9");	
	s=verifier(login,password);
	if (s==-1)
		gtk_label_set_text(GTK_LABEL(output),erreur2);
	else
	  {switch (s)
		{case 1 : {window1=lookup_widget(objet_graphique,"window1");
		   	gtk_widget_hide(window1);
		   	admin=create_admin();
		   	gtk_widget_show (admin);
		  	}break;
		 case 2 : {window1=lookup_widget(objet_graphique,"window1");
		   	gtk_widget_hide(window1);
		   	adherant=create_adherant();
		   	gtk_widget_show (adherant);
		   	break;
		  	}
		 case 3 : {window1=lookup_widget(objet_graphique,"window1");
		   	gtk_widget_hide(window1);
		   	coach=create_coach();
		  	 gtk_widget_show (coach);
		   	break;
		  	}
	 	case 4 : {window1=lookup_widget(objet_graphique,"window1");
		   	gtk_widget_hide(window1);
		  	 generaliste=create_generaliste();
		   	gtk_widget_show (generaliste);
		  	 break;
		  	}
	 	case 5 : {window1=lookup_widget(objet_graphique,"window1");
		   	gtk_widget_hide(window1);
		   	nutritionniste=create_nutritionniste();
		   	gtk_widget_show (nutritionniste);
		   	break;
		  	}

	 	case 6 : {window1=lookup_widget(objet_graphique,"window1");
		   	gtk_widget_hide(window1);
		   	kinesitherapeute=create_kinesitherapeute();
		   	gtk_widget_show (kinesitherapeute);
		   	break;
		  	}
		default :gtk_label_set_text(GTK_LABEL(output),erreur1);
		}  
	}	

}

