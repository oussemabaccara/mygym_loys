#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "seancec.h"

//affichage des séances de cure
enum
{ 	NUM,
	COURS,
	DATE,
	HEURE,
	NPLACE,
	COLUMNS
};

void afficher_seancec(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	seancec seancec1;
	char ch[20];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" num", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cours", renderer, "text",COURS, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nplace", renderer, "text",NPLACE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("seancec.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("seancec.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace)!=EOF)
		{strcpy(ch,seancec1.date1.jour);
	         strcat(ch,"/");
		 strcat(ch,seancec1.date1.mois);
 	 	 strcat(ch,"/");
		 strcat(ch,seancec1.date1.annee);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NUM, seancec1.num, COURS, seancec1.cours, DATE, ch,HEURE,seancec1.heure,NPLACE,seancec1.nplace, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
//ajouter les participants
int ajout_part2(char num[],char id[])
{
FILE *f;
f=fopen("seancec1.txt","a+");
        if(f!=NULL)
        { 
	fprintf(f,"%s %s\n",num,id);
	fclose(f);
	}
	else
	{
	return 0;
	}
}
//décrémenter le nombre de places 
int modif_nb4(char num[]) 
{
    seancec seancec1;
    FILE *f;
    FILE *f1;
    int num1;
    f1=NULL;
    f=fopen("seancec.txt","r+");
    f1=fopen("seancec.txt.tmp","a+");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace);
            if(strcmp(seancec1.num,num)!=0)
            {
			fprintf(f1,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace);
            }
  	    else
            {		num1 = atoi(seancec1.nplace);
			num1 --;
			sprintf(seancec1.nplace,"%d",num1);
	     		fprintf(f1,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace);
	    }	
	}
	
    fclose(f1);
    fclose(f);
    rename("seancec.txt.tmp","seancec.txt");

	return 0;

    }
}
//inscription à un evenement
int inscription2(char id[],char num[])
{
FILE *f1;
FILE *f2;
char num1[30],id1[30];
int x1=-1,nb;
seancec seancec1;
f1=fopen("seancec1.txt","r");
f2=fopen("seancec.txt","r");
if(f1 !=NULL)
    {

        while(fscanf(f1,"%s %s\n",num1,id1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {
        	if (x1==-1 && strcmp(num1,num)==0 && strcmp(id1,id)==0)
			x1=0;
	}
     }
	if(x1==-1)
			{
			if(f2!=NULL)
				{while(fscanf(f2,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace)!=EOF)
					{if(strcmp(seancec1.num,num)==0)
						{
					 nb = atoi(seancec1.nplace);
					 if(nb==0)
						x1=1 ;
					 else
						x1=2;
						}	
					}	
			        }
			}
     return(x1);	    	           	
     fclose(f1);
     fclose(f2);   
    
}
//incrementer le nombre de places
int modif_nb5(char num[]) 
{
    seancec seancec1;
    FILE *f;
    FILE *f1;
    int num1;
    f1=NULL;
    f=fopen("seancec.txt","r+");
    f1=fopen("seancec.txt.tmp","a+");
   if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace);
            if(strcmp(seancec1.num,num)!=0)
            {
			fprintf(f1,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace);
            }
  	    else
            {		num1 = atoi(seancec1.nplace);
			num1 ++;
			sprintf(seancec1.nplace,"%d",num1);
	     		fprintf(f1,"%s %s %s %s %s %s %s\n",seancec1.num,seancec1.cours,seancec1.date1.jour,seancec1.date1.mois,seancec1.date1.annee,seancec1.heure,seancec1.nplace);
	    }	
	}
	
    fclose(f1);
    fclose(f);
    rename("seancec.txt.tmp","seancec.txt");

	return 0;

    }
}
//suppression de participant
void supression_part2(char num[])
{
char num1[10],id[10];
FILE *f;
FILE *f2;
f=fopen("seancec1.txt","r");

if(f==NULL)
	{
		printf("erreur d'ouverture du fichier ");
		return;
	}
while (fscanf(f,"%s %s",num1,id)!=EOF)
        {
         if (strcmp(num1,num))
        {
	f2=fopen("seancec2.txt", "a");
		if (f2==NULL)
		{
		printf("erreur d'ouverture du fichier en mode a");
		return;
		}

	fprintf(f2,"%s %s\n",num1,id);

	 fclose(f2);
	}
	}

	fclose(f);
remove("seancec1.txt");
rename("seancec2.txt","seancec1.txt");

}
//Annulation d'inscription
int annulation2(char id[],char num[])
{
FILE *f1;
char num1[30],id1[30];
int x1=-1;
seancec seancec1;
f1=fopen("seancec1.txt","r");
if(f1 !=NULL)
    {

        while(fscanf(f1,"%s %s\n",num1,id1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {
        	if (x1==-1 && strcmp(num1,num)==0 && strcmp(id1,id)==0)
			x1=0;
	}
     }
	
    return(x1);
}
