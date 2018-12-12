#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "agenda.h"

enum
{	
	JOUR,
	MOIS,
	ANNEE,
	HEURE,
	NOTES,
	ID,
	COLUMNS,
	
};

void ajouter_agenda(agenda ag)
{
 FILE *f;
 f=fopen("/home/yasmine/Projects/project10/src/agenda.txt","a+");
 if(f!=NULL)
{
fprintf(f,"%d %d %d %s %s %s \n",ag.jour,ag.mois,ag.annee,ag.heure,ag.notes,ag.id);
fclose(f);
}

}
void afficher_agenda(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int jour;
	int mois;
	int annee;
	char heure[50];
	char notes[50];
	char id[20];
	
	
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
renderer=gtk_cell_renderer_text_new();		      		
column=gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",JOUR, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",MOIS, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee", renderer, "text",ANNEE, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column); 


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" heure", renderer, "text",HEURE, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column); 


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" notes", renderer, "text",NOTES, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
  
}
			  store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f= fopen("/home/yasmine/Projects/project10/src/agenda.txt", "r");
		if(f==NULL)
		{
			return;
		}
		else
		{
		f=fopen("/home/yasmine/Projects/project10/src/agenda.txt", "a+");
		while(fscanf(f,"%d %d %d %s %s %s \n",&jour,&mois,&annee,heure,notes,id)!=EOF)
		  {
		gtk_list_store_append (store, &iter);
		  gtk_list_store_set(store, &iter,JOUR,jour,MOIS,mois,ANNEE,annee,HEURE,heure,NOTES,notes,ID,id, -1);
		  }
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
}


/* Supprimer agenda */
void supprimer_agenda(char id1[20])
{	
	FILE*r, *s;
        agenda ag;
    	r=fopen("agenda.txt","a+");
	s=fopen("suppression.txt","a+");
	
	if(r!=NULL) 

	{
		
	while(fscanf(r,"%d %d %d %s %s %s \n",&ag.jour,&ag.mois,&ag.annee,ag.heure,ag.notes,ag.id)!=EOF)
	{
    		if(strcmp(ag.id,id1)!=0)
    		{	
			fprintf(s,"%d %d %d %s %s %s \n",ag.jour,ag.mois,ag.annee,ag.heure,ag.notes,ag.id);

    		}
    				
	}
	fclose(r);
	fclose(s);
remove("agenda.txt");
rename("suppression.txt","agenda.txt");
        }
}



