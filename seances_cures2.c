#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "seances_cures.h" 

enum
{	TYPE,
	JOUR,
	MOIS,
	ANNEE,
	PERIODE,
	COLUMNS
};


//ajouter une seance de cure dans seances_cures.txt

void ajouter_seance(Seance s)
{	FILE* f;
	f=fopen("seances_cures.txt","a");
  	if(f!=NULL) 
 		{  fprintf(f,"%s %d %d %d %d \n", s.type, s.date_seance.jour ,s.date_seance.mois, s.date_seance.annee, s.periode);  	
	fclose(f);  } 	


} 

//Afficher la liste des séances de cures
void afficher_seance(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char type[20];
	char annee[5];
	char mois [5];
	char jour[5];
	char periode[20];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" type", renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",JOUR, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  annee", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  periode", renderer, "text",PERIODE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("seances_cures.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("seances_cures", "a+");
              while(fscanf(f,"%s %s %s %s %s\n", type,jour,mois,annee,periode)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,TYPE, type,JOUR,jour,MOIS,mois,ANNEE,annee,PERIODE,periode ,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
