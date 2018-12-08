#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "authentification.h" 


void
on_button1_clicked                     (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	int x;	
	GtkWidget *a ,*b,*c ,*window3,*window4;
	char login[20],password[20];
	
	window3= lookup_widget(objet_graphique,"window3");	
	a=lookup_widget(objet_graphique,"entry1");
	b=lookup_widget(objet_graphique,"entry2");
	c=lookup_widget(objet_graphique,"label4");
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(a)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(b)));
	x =verifier(login,password);
	
	if(x==1){ 
window4=create_window4();
gtk_widget_show (window4);
gtk_widget_hide(window3);
}
	else 
	{ gtk_label_set_text(GTK_LABEL(c),"authentification non validée");}

}


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window3 , *window4;
	window3= lookup_widget(objet_graphique,"window3");
	window3=create_window3();
	gtk_widget_show (window3);
	gtk_widget_hide(window4);
}





void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5,*window4,*List_View;
window5=create_window5();
window4=lookup_widget(objet_graphique,"window4");
gtk_widget_hide(window4);
List_View=lookup_widget(window5,"treeview1");
afficher1(List_View);
gtk_widget_show (window5);


}


void
on_button5_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5,*window6;
window6=create_window6();
gtk_widget_show (window6);
gtk_widget_hide(window5);
}


void
on_button9_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *a ,*b,*c ,*window5;
	char seance[20],date[20],type[20];
	
	a=lookup_widget(objet_graphique,"entry3");
	b=lookup_widget(objet_graphique,"entry4");
	c=lookup_widget(objet_graphique,"entry5");
	strcpy(seance,gtk_entry_get_text(GTK_ENTRY(a)));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(b)));
        strcpy(type,gtk_entry_get_text(GTK_ENTRY(c)));
        ajouter(seance,date,type);

}


void
on_button10_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window5 , *window6;
	window5= lookup_widget(objet_graphique,"window5");
	window5=create_window5();
	gtk_widget_show (window5);
	gtk_widget_hide(window6);

}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4 , *window5;
	window4= lookup_widget(objet_graphique,"window4");
	window4=create_window4();
	gtk_widget_show (window4);
	gtk_widget_hide(window5);

}

