#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include <stdio.h>
#include <string.h>
#include "greeting.h"
#include <gtk/gtk.h>
enum
{
    COURS,
    NOMBREDEPLACE,
    DATE,
    HEURE,
    COLUMNS
};

void ajouter_personne(Personne p)
{

FILE*f;
f=fopen("utilisateur.txt","a+");//ouvertur du fichier en mode lecture
if(f!=NULL) 
{
fprintf(f,"%s %s %s %s\n", p.Cours, p.Date, p.Heure, p.Nombredeplace);
fclose(f);
}
              
}
void afficher_personne(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	
	char Date[20];
	char Heure[20];
        char Nombredeplace[20];
        char Cours[20];
        store=NULL;

       FILE *f;

store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{


                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Cours", renderer, "text",COURS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               

renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nombredeplace", renderer, "text",NOMBREDEPLACE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
            }



store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("utilisateur.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("utilisateur.txt", "a+");
              while(fscanf(f,"%s %s %s %s \n",Cours,Date,Heure,Nombredeplace)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, COURS, Cours,DATE, Date,HEURE, Heure,NOMBREDEPLACE, Nombredeplace, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
















