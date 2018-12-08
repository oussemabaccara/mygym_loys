
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentification.h"

void ajouter(char seance[],char date[],char type[])
{
	FILE *f;
	f = fopen("/home/amine/Projects/Amine1/project5/src/seance.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s %s %s\n", seance, date, type);
	}
	fclose(f);

}

void afficher()
{
	FILE *f;
	char login[20],password[20];

	f=fopen("/home/amine/Projects/Amine1/project5/users.txt","r");
	
	int role;
	while(fscanf(f,"%s %s %d", login, password, &role)!=EOF){
		printf("%s %s %d\n", login, password, role);
	}
	fclose(f);
}

int verifier(char login[],char password[])
{
	FILE *f;
	f=fopen("/home/amine/Projects/Amine1/project5/users.txt","r");
	
	char login1[20],password1[20];
	while(fscanf(f,"%s %s", login1, password1)!=EOF){
		if (strcmp(login1,login)==0 && strcmp(password1,password)==0)
		{
			fclose(f);			return 1;
		}
	}
	fclose(f);
	return(0);

}

void afficher1(GtkWidget *plistview)
{ 
enum { COL_SEANCE,
       COL_DATE,
       COL_TYPE,
       NUM_COLS
      };
char seance[20],date[20],type[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("/home/amine/Projects/Amine1/project5/src/seance.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s",seance,date,type)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_SEANCE, seance,
		          COL_DATE, date,
		          COL_TYPE, type,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("seance",celrender,"text",COL_SEANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("date",celrender,"text",COL_DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("type",celrender,"text",COL_TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}


