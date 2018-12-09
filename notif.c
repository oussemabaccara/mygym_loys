#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "notif.h"

enum
{
	NOTIF,
	COLUMNS
};


void afficher_notif(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char notif[1000];
	int max=1000;
	
	
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Notifications", renderer, "text",NOTIF, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		

               
	
	}

	
	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING);

	f = fopen("notif.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("notif.txt", "a+");
			
              while(fgets(notif,max,f)!=NULL)
		{
				gtk_list_store_append (store, &iter);
				gtk_list_store_set (store, &iter, 	NOTIF,notif,-1); 
		}

		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


void ajouter_notif(char notif[])
{
	FILE* f;
	f=fopen("notif.txt","a+");
  	if(f!=NULL) 
 		{  fprintf(f,"%s\n",notif);  	
	 } 
	 fclose(f); 
}