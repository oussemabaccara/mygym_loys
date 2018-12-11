#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "consultation.h"
enum
{ 	ID,
	NOM,
	PRENOM,
	DATEDENAISSANCE,
	SPECIALITE,
	CELLULAIRE,
	COLUMNS
};

//affichage des séances

void afficher_med(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	compte cp;
        store=NULL;

       FILE *f;

	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  datedenaissance", renderer, "text",DATEDENAISSANCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  specialite", renderer, "text",SPECIALITE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  cellulaire", renderer, "text",CELLULAIRE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("comptes.txt", "r");
	
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("comptes.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",cp.id,cp.nom,cp.prenom,cp.datenaiss.jour,cp.datenaiss.mois,cp.datenaiss.annee,cp.sexe,cp.ville,cp.numtel,cp.ligne)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID, cp.id, NOM, cp.nom, PRENOM, cp.prenom,DATEDENAISSANCE,cp.datenaiss.jour,SPECIALITE,cp.sexe,CELLULAIRE,cp.numtel, -1);
	 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
