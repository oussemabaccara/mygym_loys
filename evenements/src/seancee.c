#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "seancee.h"
enum
{ 	NUM,
	COURS,
	DATE,
	HEURE,
	NPLACE,
	COLUMNS
};


void afficher_seancee(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	seancee seancee1;
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" num", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cours", renderer, "text",COURS, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nplace", renderer, "text",NPLACE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("seancee.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("seancee.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s\n",seancee1.num,seancee1.cours,seancee1.date,seancee1.heure,seancee1.nplace,seancee1.nplacemax)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NUM, seancee1.num, COURS, seancee1.cours, DATE, seancee1.date,HEURE,seancee1.heure,NPLACE,seancee1.nplace, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
