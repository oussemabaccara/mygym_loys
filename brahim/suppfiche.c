#include <gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>




void supprimer_fiche(char n[])
{
  FILE*f,*f1;
  Fiche fi ;
  f=fopen("fiches.txt","r+");
  f1=fopen("fiches1.txt","w+");
  
  if(f !=NULL) 
  { 
     while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",fi.id,fi.nom,fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies,fi.gs,fi.imc)!=EOF)

    {
     if (strcmp(fi.id,n)!=0)	 
    	fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",fi.id,fi.nom,fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies,fi.gs,fi.imc));

    }
  fclose(f1);
  fclose(f);
  }
  f=fopen("fiches.txt","w+");
  f1=fopen("fiches1.txt","r+");
 while (fscanf(f1,"%s %s %s %s %s %s %s %s %s\n",fi.id,fi.nom,fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies,fi.gs,fi.imc))!=EOF)
	fprintf(f,"%s %s %s %s %s %s %s %s %s \n",fi.id,fi.nom,fi.prenom,fi.age,fi.poids,fi.taille,fi.maladies,fi.gs,fi.imc));

  fclose(f1);
  fclose(f);
  remove("fiches1.txt");
}