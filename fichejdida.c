#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "fiche.h"

enum
{ 	ID,
	NOM,
	PRENOM,
	AGE,
	POIDS,
	TAILLE,
	MALADIES,
	COLUMNS
};


//verifier si l identifiant existe dans fiches.txt
int verifier (char user[])
{
	FILE*f;
	Fiche fi;
	int exist=-1;
	
f=fopen("fiches.txt" , "r");
if (f!=NULL)
{	while (fscanf(f,"%s " , fi.id)!=EOF)
		{ if (strcmp(user,fi.id)==0 )
			exist=1;	
		}

}
fclose(f);

return(exist);						
}


//Afficher la fiche de l identifiant correspondant
void afficher(char user[] ,char ficha[])	
{	FILE*f;
	
	Fiche fi ;
	


f=fopen("fiches.txt" , "r");
if (f!=NULL)
{	while (fscanf(f,"%s %s %s %s %s %s %s\n" , fi.id ,fi.nom, fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies)!=EOF)
	{ if (strcmp(fi.id,user)==0 )
		{

			
		strcpy(ficha,"Nom :        ");strcat(ficha,fi.nom); strcat(ficha," \n");
		strcat(ficha,"Prénom :     ");strcat(ficha,fi.prenom);strcat(ficha,"\n ");
		strcat(ficha,"Age :        ");strcat(ficha,fi.age);strcat(ficha," ans\n ");
		strcat(ficha,"Poids :      ");strcat(ficha,fi.poids);strcat(ficha," Kg\n");
		strcat(ficha,"Taille :     ");strcat(ficha,fi.taille);strcat(ficha," Cm\n");
		strcat(ficha,"Maladies :   ");strcat(ficha,fi.maladies);strcat(ficha," ");
		}
	}

}
fclose(f);

}

//ajouter une fiche dans fiches.txt
void ajouter_fiche(Fiche fi)
{
	FILE *f;
	f=fopen("fiches.txt","a+");
	if (f!=NULL)
		{ fprintf(f,"%s %s %s %s %s %s %s\n", fi.id , fi.nom , 				fi.prenom, fi.age , fi.poids , fi.taille , fi.maladies);
		fclose(f);
		}
}




void afficher_fiche(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char id[20];
	char nom[20];
	char prenom[20];
	char age[5];
	char poids[10];
	char taille[10];
	char maladies[100];
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
		column = gtk_tree_view_column_new_with_attributes("  age", renderer, "text",AGE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  taille", renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  maladies", renderer, "text",MALADIES, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("fiches.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("fiches.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s\n", id,nom,prenom,age,poids,taille,maladies)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID, id, NOM, nom, PRENOM, prenom,AGE,age,POIDS,poids,TAILLE,taille,MALADIES,maladies ,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
		








