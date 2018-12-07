#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "personne.h"
#include "acct.h"
#include <gtk/gtk.h>

int exist(char user[])
{
 Personne p;
 FILE*f;
 int exist=-1;

 f=fopen("utilisateur.txt" , "r");
 if (f!=NULL)
	{
	 while (fscanf(f,"%s " , p.id)!=EOF)
		{
		 if (strcmp(user,p.id)==0 )
			 exist=1;	
		}
	}

 fclose(f);

 return(exist);						
}

enum   
{       
 IDENTIFIANT,
 NOM,
 PRENOM,
 DATE,
 ROLE,
 COLUMNS
};



//Ajouter une personne

void ajouter_personne(Personne p)
{
 FILE *f;
 f=fopen("utilisateur.txt","a+");
 if(f!=NULL) 
	{
	 fprintf(f,"%s %s %s %d/%d/%d %s \n" ,p.id,p.nom,p.prenom,p.date.jour,p.date.mois,p.date.annee,p.role);
	 fclose(f);
	}
 FILE *f1;
 f1=fopen("users.txt","a+");
 if(f!=NULL) 
	{
	 int r=0;
	 if((strcmp(p.role,"Admin")==0))r=1;
	 else if((strcmp(p.role,"Kinésithérapeute")==0))r=2;
	 else if((strcmp(p.role,"Coach")==0))r=3;
	 else if((strcmp(p.role,"Adhérent")==0))r=4;
	 else if((strcmp(p.role,"Médecin_nutritionniste")==0))r=5;
	 fprintf(f,"%s %s %d \n" ,p.id,p.id,r);
	 fclose(f);
	}
}



//Afficher une personne

void afficher_personne(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter    iter;
 GtkListStore *store;

 char nom [30];
 char prenom [30];
 char id[30];
 char date[30];
 char role[30];
 store=NULL;

 FILE *f;

 store=gtk_tree_view_get_model(liste);	
 if (store==NULL)
	{

         renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);	
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text",PRENOM, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text",DATE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	 renderer = gtk_cell_renderer_text_new ();
	 column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",ROLE, NULL);
	 gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	}


 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("utilisateur.txt", "r");

 if(f==NULL)
	{
	 return;
	}		
 else 
	{
 	 f = fopen("utilisateur.txt", "a+");
	 while(fscanf(f,"%s %s %s %s %s \n",id,nom,prenom,date,role)!=EOF)
		{
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,IDENTIFIANT,id,NOM,nom,PRENOM,prenom,DATE,date,ROLE,role,-1); 
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	 g_object_unref (store);
	}
}





