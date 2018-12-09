#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "activ.h"
#include <gtk/gtk.h>

//Ajouter une activité

void activadd(activ a)
{
 FILE *f;
 f=fopen("activ.txt","a+");
 if(f!=NULL) 
	{
	 fprintf(f,"%s %s %d %s %s \n" ,a.type,a.jour,a.horH,a.hormin,a.dur);
	 fclose(f);
	}
}

enum   
{       
 TYPE,
 JOUR,
 HORRAIRE,
 DUREE,
 COLUMNS
};

//Afficher

void affactiv(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

 char type[30];
 char jour[30];
 char hor[30];
 char horH[30];
 char hormin[30];
 char dur[30];
 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);
 if (store==NULL)
	{
         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Activité", renderer, "text",IDENTIFIANT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",NOM, NULL);	
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Horraire", renderer, "text",PRENOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Durée", renderer, "text",DATE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("activ.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("activ.txt", "a+");
	 while(fscanf(f,"%s %s %s %s %s \n",type,jour,horH,hormin,dur)!=EOF)
		{
		 strcpy(hor,horH);strcat(hor,"H");
		 strcat(hor,hormin);
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,TYPE,type,JOUR,jour,HORRAIRE,hor,DUREE,dur,-1);
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}
