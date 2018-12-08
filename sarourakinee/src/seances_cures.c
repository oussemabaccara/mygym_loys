#include <gtk/gtk.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "seances_cures.h" 

enum
{	NUM,
	TYPE,
	JOUR,
	MOIS,
	ANNEE,
	PERIODE,
	NBP,
	COLUMNS
};

void intstring(int x,char su[])
{

    switch(x) {

   case 1  : strcpy(su,"1");break;
   case 2  : strcpy(su,"2");break;
   case 3  : strcpy(su,"3");break;
   case 4  : strcpy(su,"4");break;
   case 5  : strcpy(su,"5");break;
   case 6  : strcpy(su,"6");break;
   case 7  : strcpy(su,"7");break;
   case 8  : strcpy(su,"8");break;
   case 9  : strcpy(su,"9");break;
   case 10 : strcpy(su,"10");break;
   case 11 : strcpy(su,"11");break;
   case 12  : strcpy(su,"12");break;
   case 13  : strcpy(su,"13");break;
   case 14  : strcpy(su,"14");break;
   case 15  : strcpy(su,"15");break;
   case 16  : strcpy(su,"16");break;
   case 17  : strcpy(su,"17");break;
   case 18  : strcpy(su,"18");break;
   case 19  : strcpy(su,"19");break;
   case 20  : strcpy(su,"20");break;
   case 21  : strcpy(su,"21");break;
   case 22  : strcpy(su,"22");break;
   case 23  : strcpy(su,"23");break;
   case 24  : strcpy(su,"24");break;
   case 25  : strcpy(su,"25");break;
   case 26  : strcpy(su,"26");break;
   case 27  : strcpy(su,"27");break;
   case 28  : strcpy(su,"28");break;
   case 29  : strcpy(su,"29");break;
   case 30  : strcpy(su,"30");break;
   case 31  : strcpy(su,"31");break;
   case 2018  : strcpy(su,"2018");break;
   case 2019  : strcpy(su,"2019");break;
   case 2020  : strcpy(su,"2020");break;

   default :   return(0);
}
}


//ajouter une seance de cure dans seances_cures.txt

void ajouter_seance(Seance s)
{	FILE* f;
	f=fopen("seances_cures.txt","a+");
  	if(f!=NULL) 
 		{  fprintf(f,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,s.date_seance.mois,
 		 s.date_seance.annee, s.periode ,s.nbp);  	
	 } 
	 fclose(f); 	


} 

//Afficher la liste des séances de cures
void afficher_seance(GtkWidget *liste)	
{
       GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	Seance s;
	char num[10];
	char type[20];
	char annee[5];
	char mois[5];
	char jour[5];
	char periode[20];
	char nbp[10];
      store=NULL;

       FILE *f;


	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{			

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Numéro", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

        renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Type", renderer, "text",TYPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Jour", renderer, "text",JOUR, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Mois", renderer, "text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Année", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Période", renderer, "text",PERIODE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Nbre de places", renderer, "text",NBP, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, 
		G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("seances_cures.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("seances_cures.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s\n",num, type,jour,mois,annee,periode,nbp)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NUM,num,TYPE, type,JOUR,jour,MOIS,mois,ANNEE,annee,PERIODE,periode ,NBP,nbp,-1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


void modifier_seance(char n[],char modif[])
{
  FILE*f,*f1;
  Seance s ;
  f=fopen("seances_cures.txt","r+");
  f1=fopen("seances_cures1.txt","w+");
  
  if(f !=NULL) 
  { 
    while (fscanf(f,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,
    	s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp)!=EOF)
    {
     if (strcmp(s.num,n)==0)	 
	{
	 strcpy(s.type,modif);
	fprintf(f1,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp);
	}
     else 
     	fprintf(f1,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp);
    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("seances_cures.txt","w+");
  f1=fopen("seances_cures1.txt","r+");
    while (fscanf(f1,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp)!=EOF)
	fprintf(f,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp);


  fclose(f1);
  fclose(f);
  remove("seances_cures1.txt"); 
}


void supprimer_seance(char n[])
{
  FILE*f,*f1;
  Seance s ;
  f=fopen("seances_cures.txt","r+");
  f1=fopen("seances_cures1.txt","w+");
  
  if(f !=NULL) 
  { 
     while (fscanf(f,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,
     	s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp)!=EOF)

    {
     if (strcmp(s.num,n)!=0)	 
    	fprintf(f1,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,
    		s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp);

    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("seances_cures.txt","w+");
  f1=fopen("seances_cures1.txt","r+");
 while (fscanf(f1,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,
 	s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp)!=EOF)
	fprintf(f,"%s %s %s %s %s %s %s\n",s.num, s.type, s.date_seance.jour ,s.date_seance.mois, s.date_seance.annee, s.periode,s.nbp);

  fclose(f1);
  fclose(f);
  remove("seances_cures1.txt");
}