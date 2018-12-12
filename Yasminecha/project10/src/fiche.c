#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fiche.h"

enum
{	
	NOM,
	PRENOM,
	AGE,
	POIDS,
	TAILLE,
	MALADIES,
	REGIME_ALIMENTAIRE,
	REMARQUES,
	ID,
	COLUMNS,
	
};

void ajouter_fiche(fiche fi)
{
 FILE *f;
 f=fopen("/home/yasmine/Projects/project10/src/fiche.txt","a+");
 if(f!=NULL)
{
fprintf(f,"%s %s %d %s %s %s %s %s %s\n",fi.nom,fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies,fi.regime_alimentaire,fi.remarques,fi.id);
fclose(f);
}

}
void afficher_fiche(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[50];
	char prenom[50];
	int age;
	char poids[50];
	char taille[50];
	char maladies[50];
	char regime_alimentaire[50];
	char remarques[50];
	char id[20];
	
	
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
renderer=gtk_cell_renderer_text_new();		      		
column=gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" age", renderer, "text",AGE, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column); 


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" poids", renderer, "text",POIDS, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column); 


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" taille", renderer, "text",TAILLE, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" maladies", renderer, "text",MALADIES, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" regime_alimentaire", renderer, "text",REGIME_ALIMENTAIRE, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" remarques", renderer, "text",REMARQUES, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID, NULL);				  				gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
  
}
			  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f= fopen("/home/yasmine/Projects/project10/src/fiche.txt", "r");
		if(f==NULL)
		{
			return;
		}
		else
		{
		f=fopen("/home/yasmine/Projects/project10/src/fiche.txt", "a+");
		while(fscanf(f,"%s %s %d %s %s %s %s %s %s\n",nom,prenom,&age,poids,taille,maladies,regime_alimentaire,remarques,id)!=EOF)
		  {
		gtk_list_store_append (store, &iter);
		  gtk_list_store_set(store, &iter,NOM,nom,PRENOM,prenom,AGE,age,POIDS,poids,TAILLE,taille,MALADIES,maladies,REGIME_ALIMENTAIRE,regime_alimentaire,REMARQUES,remarques,ID,id, -1);
		  }
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
		g_object_unref (store);
		}
}

void supprimer_fiche(char id2[20])
{	
	FILE*r, *s;
        fiche fi;
    	r=fopen("fiche.txt","a+");
	s=fopen("suppressionfiche.txt","a+");
	
	if(r!=NULL) 

	{
		
	while(fscanf(r,"%s %s %d %s %s %s %s %s %s  \n",fi.nom,fi.prenom,&fi.age,fi.poids,fi.taille,fi.maladies,fi.regime_alimentaire,fi.remarques,fi.id)!=EOF)
	{
    		if(strcmp(fi.id,id2)!=0)
    		{	
			fprintf(s,"%s %s %d %s %s %s %s %s %s \n",fi.nom,fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies,fi.regime_alimentaire,fi.remarques,fi.id);

    		}
    				
	}
	fclose(r);
	fclose(s);
remove("fiche.txt");
rename("suppressionfiche.txt","fiche.txt");
        }
}

