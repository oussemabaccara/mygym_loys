#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "rdv.h"



enum 
{
	ID1,
	ID2,
	JOUR,
	MOIS,
	ANNEE,
	HEURE,
	COLUMN
}






void afficher_rdv(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char id1[10];
	char id2[20];
	char jour[20];
	char mois[10];
	char annee[10];
	char heure[10];
	
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ID médecin", renderer, "text",ID1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ID adhérant", renderer, "text",ID2, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Jour", renderer, "text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Année", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("rdv.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("rdv.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s\n", id1,id2,jour,mois,annee,heures)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID1,id1,ID2,id2,JOUR,jour,MOIS,mois,ANNEE,annee,HEURE,heure ,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}