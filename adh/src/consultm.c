#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "consultm.h"
enum
{ 	ID,
	NOM,
	PRENOM,
	DATEDENAISSANCE,
	SPECIALITE,
	CELLULAIRE,
	COLUMNS
};


//fonction permettant de retourner le role
int getrole(char id[])
{
user us;
int num1,x1=-1;
FILE *f;
f=fopen("users.txt","r");
if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %s\n",us.id,us.mdp,us.role)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (x1==-1 && strcmp(us.id,id)==0)//test d'auth
			{	
				x1=1;
				num1 = atoi(us.role);
				return(num1);
			}	           	
	}
     fclose(f);   
    }
}
//affichage des séances

void afficher_med(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	compte1 cp;
	int n;
	char ch[20],ch1[50];
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
		column = gtk_tree_view_column_new_with_attributes("  prénom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  datedenaissance", renderer, "text",DATEDENAISSANCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  specialité", renderer, "text",SPECIALITE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  cellulaire", renderer, "text",CELLULAIRE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("comptes.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("comptes.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",cp.id,cp.nom,cp.prenom,cp.datenaiss.jour,cp.datenaiss.mois,cp.datenaiss.annee,cp.sexe,cp.ville,cp.numtel,cp.ligne)!=EOF)
		{n=getrole(cp.id);
		 sprintf(ch1,"%d",n);
		 strcpy(ch,cp.datenaiss.jour);
	         strcat(ch,"/");
		 strcat(ch,cp.datenaiss.mois);
 	 	 strcat(ch,"/");
		 strcat(ch,cp.datenaiss.annee);
		 if(n==2) strcpy(ch1,"Kinésithérapeute");
		 else if(n==4) strcpy(ch1,"Médecin généraliste");
		 if(n==6) strcpy(ch1,"Médecin nutritionniste");
		 if(n==2 || n==4 || n==6)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID, cp.id, NOM, cp.nom, PRENOM, cp.prenom,DATEDENAISSANCE,ch,SPECIALITE,ch1,CELLULAIRE,cp.numtel, -1);
		}
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
