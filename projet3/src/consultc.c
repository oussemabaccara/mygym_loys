#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "consultc.h"
enum
{ 	ID,
	NOM,
	PRENOM,
	DATEDENAISSANCE,
	CELLULAIRE,
	NOTE,
	COLUMNS
};
//calcul de note
float calcul_note(char idc[])
{
char note1[20],idc1[20],ida1[20];
int num,num1=0,i=1;
float x;
FILE *f;
f=fopen("note.txt","r");
if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %s\n",ida1,idc1,note1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (strcmp(idc1,idc)==0)//test d'auth
			{	
				i++;
				num=atoi(note1);
				num1+=num;
			}	           	
	}
     x=(float)num1/i;
     return(x);
     fclose(f);   
    }
}
//verification si adhérant a noté deja
int comparaison_id1(char idc[],char ida[])
{
char note1[20],idc1[20],ida1[20];
int num1,x1=-1;
FILE *f;
f=fopen("note.txt","r");
if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %s\n",ida1,idc1,note1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (x1==-1 && strcmp(idc1,idc)==0 && strcmp(ida1,ida)==0)//test d'auth
			{	
				x1=1;
				return(x1);
			}	           	
	}
     fclose(f);   
    }
}
//verification coach existant ou pas
int comparaison_id(char idc[])
{
user1 us;
int num1,x1=-1;
FILE *f;
f=fopen("users.txt","r");
if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %s\n",us.id,us.mdp,us.role)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (x1==-1 && strcmp(us.id,idc)==0)//test d'auth
			{	
				x1=1;
				return(x1);
			}	           	
	}
     fclose(f);   
    }
}
//modifier la note
int modif_note(char ida[],char idc[],char note[]) 
{
    char note1[20],idc1[20],ida1[20];
    FILE *f;
    FILE *f1;
    int num1;
    f1=NULL;
    f=fopen("note.txt","r+");
    f1=fopen("note.txt.tmp","a+");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s\n",ida1,idc1,note1);
            if(strcmp(idc1,idc)!=0 && strcmp(ida1,ida)!=0 )
            {
			fprintf(f1,"%s %s %s\n",ida1,idc1,note1);
            }
  	    else 
            {		
	     		fprintf(f1,"%s %s %s\n",ida1,idc1,note);
	    }	
	}
    fclose(f1);
    fclose(f);
    rename("note.txt.tmp","note.txt");

	return 0;

    }
}
//ajout fichier note
int ajout_note(char ida[],char idc[],char note[])
{
FILE *f;
f=fopen("note.txt","a+");
        if(f!=NULL)
        { 
	fprintf(f,"%s %s %s\n",ida,idc,note);
	fclose(f);
	}
	else
	{
	return 0;
	}
}
//fonction permettant de retourner le role
int getrole1(char id[])
{
user1 us;
int num1;
FILE *f;
f=fopen("users.txt","r");
if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %s\n",us.id,us.mdp,us.role)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (strcmp(us.id,id)==0)//test d'auth
			{	
				
				num1 = atoi(us.role);
				return(num1);
			}	           	
	}
     fclose(f);   
    }
}
//affichage des séances

void afficher_c(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	compte2 cp;
	int n;
	char ch[20],ch1[50];
	float x;
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
		column = gtk_tree_view_column_new_with_attributes("  cellulaire", renderer, "text",CELLULAIRE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  note", renderer, "text",NOTE, NULL);
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
		{n=getrole1(cp.id);
		 strcpy(ch,cp.datenaiss.jour);
	         strcat(ch,"/");
		 strcat(ch,cp.datenaiss.mois);
 	 	 strcat(ch,"/");
		 strcat(ch,cp.datenaiss.annee);
		 x=calcul_note(cp.id);
	 	 sprintf(ch1,"%.2f",x);
		 if(n==3)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID, cp.id, NOM, cp.nom, PRENOM, cp.prenom,DATEDENAISSANCE,ch,CELLULAIRE,cp.numtel,NOTE,ch1, -1);
		}
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
