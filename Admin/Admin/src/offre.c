#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "offre.h"


//exist
int existof(char num[])
{
 char ch1[30];
 char ch2[30];
 char ch3[30];
 FILE*f;
 int exist=-1;

 f=fopen("offre.txt" , "r");
 if (f!=NULL)
	{
	 while (fscanf(f,"%s %s %s" ,ch1,ch2,ch3)!=EOF)
		{
		 if (strcmp(num,ch1)==0 )
			 exist=1;	
		}
	}

 fclose(f);

 return(exist);						
}

//supp offre
void suppof(char num[])
{
FILE *f;
FILE *f2;
char ch1[30],ch2[30],ch3[30];
f=fopen("offre.txt","r");

if(f==NULL)
	{
		return;
	}
while (fscanf(f,"%s %s %s",ch1,ch2,ch3)!=EOF)
        {
         if (strcmp(num,ch1))
        {
	f2=fopen("testof.txt", "a");
		if (f2==NULL)
		{
		return;
		}

	fprintf(f2,"%s %s %s\n",ch1,ch2,ch3);

	 fclose(f2);
	}
	}

	fclose(f);
remove("offre.txt");
rename("testof.txt","offre.txt");

}

//ajout
void ajout_of(offre o)
{
 FILE *f;
 f=fopen("offre.txt","a+");
 if(f!=NULL) 
	{
	 fprintf(f,"%s %s %s \n" ,o.nbre,o.description,o.prix);
	 fclose(f);
	}
}

//aff
enum
{ 	
	NUM,
	DES,
	PRIX,
	COLUMNS
};

void afficher_offre(GtkWidget *liste)	
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	
	char num[30];;
	char des[30];
	char prix[30];
	store=NULL;
        FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("num", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("description", renderer, "text",DES, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
 store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 f = fopen("offre.txt", "r");
	
 if(f==NULL)
	{
	 return;
	}		
 else
	{
	 f = fopen("offre.txt", "a+");
         while(fscanf(f,"%s %s %s \n",num,des,prix)!=EOF)
		{
		 gtk_list_store_append (store, &iter);
		 gtk_list_store_set (store,&iter,NUM,num,DES,des,PRIX,prix,-1); 
		}
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    	 g_object_unref (store);
	}
}

offre getoffre(char nom[])
{
FILE*f;
offre offre1;
int x1;
x1=-1;
f=fopen("/home/oussemabaccara/Projects/project3/src/offre.txt","r");//lecture de fichier



 if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %s",&offre1.nbre,&offre1.description,&offre1.prix)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (x1==-1 && strcmp(offre1.nbre,nom)==0)//test d'auth
			{
				x1=1;
				return(offre1);
			}	           	
	}
     fclose(f);   
    }
}

