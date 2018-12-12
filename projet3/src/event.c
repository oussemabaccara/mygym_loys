#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "event.h"
//affichage des evenements
enum
{ 	NUM,
	NOM,
	DESCRIPTION,
	DATE,
	HEURE,
	NOMBRE,
	COLUMNS
};


void afficher_event(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	event event1;
        store=NULL;

        FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" num", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  description", renderer, "text",DESCRIPTION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  heure", renderer, "text",HEURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nombre", renderer, "text",NOMBRE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("event.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("event.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NUM, event1.num, NOM, event1.nom, DESCRIPTION, event1.description, DATE, event1.date, HEURE, event1.heure, NOMBRE, event1.nombre, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
//ajouter les participants
int ajout_part(char num[],char id[])
{
FILE *f;
f=fopen("event1.txt","a+");
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
int modif_nb(char num[]) 
{
    event event1;
    FILE *f;
    FILE *f1;
    int num1;
    f1=NULL;
    f=fopen("event.txt","r+");
    f1=fopen("event.txt.tmp","a+");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax);
            if(strcmp(event1.num,num)!=0)
            {
			fprintf(f1,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax);
            }
  	    else
            {		num1 = atoi(event1.nombre);
			num1 --;
			sprintf(event1.nombre,"%d",num1);
	     		fprintf(f1,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax);
	    }	
	}
	
    fclose(f1);
    fclose(f);
    rename("event.txt.tmp","event.txt");

	return 0;

    }
}
//inscription à un evenement
int inscription(char id[],char num[])
{
FILE *f1;
FILE *f2;
char num1[30],id1[30],ch[2];
int x1=-1,nb;
event event1;
f1=fopen("event1.txt","r");
f2=fopen("event.txt","r");

if(f1 !=NULL)
    {

        while(fscanf(f1,"%s %s\n",num1,id1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {
        	if (x1==-1 && strcmp(num1,num)==0 && strcmp(id1,id)==0)	
			x1=0;
			
		
			
	
        }
     }
	if (x1==-1)	
			{
			if(f2!=NULL)
				{while(fscanf(f2,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax)!=EOF)
					{
					 nb = atoi(event1.nombre);
					 if(nb==0)
						x1=1;
						
					 else
						x1=2;
							
					}	
			        }
			}
	
     return(x1);	    	           	
     fclose(f1);
     fclose(f2);   
    

}
//incrementer le nombre de places
int modif_nb1(char num[]) 
{
    event event1;
    FILE *f;
    FILE *f1;
    int num1;
    f1=NULL;
    f=fopen("event.txt","r+");
    f1=fopen("event.txt.tmp","a+");
   if (f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax);
            if(strcmp(event1.num,num)!=0)
            {
			fprintf(f1,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax);
            }
  	    else
            {		num1 = atoi(event1.nombre);
			num1 ++;
			sprintf(event1.nombre,"%d",num1);
	     		fprintf(f1,"%s %s %s %s %s %s %s\n",event1.num,event1.nom,event1.description,event1.date,event1.heure,event1.nombre,event1.nombremax);
	    }	
	}
	
    fclose(f1);
    fclose(f);
    rename("event.txt.tmp","event.txt");

	return 0;

    }
}
//suppression de participant
void supression_part(char num[])
{
char num1[10],id[10];
FILE *f;
FILE *f2;
f=fopen("event1.txt","r");

if(f==NULL)
	{
		printf("erreur d'ouverture du fichier ");
		return;
	}
while (fscanf(f,"%s %s",num1,id)!=EOF)
        {
         if (strcmp(num1,num))
        {
	f2=fopen("event2.txt", "a");
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
remove("event1.txt");
rename("event2.txt","event1.txt");

}
//Annulation d'inscription
int annulation(char id[],char num[])
{
FILE *f1;
char num1[30],id1[30];
int x1=-1;
event event1;
f1=fopen("event1.txt","r");
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
