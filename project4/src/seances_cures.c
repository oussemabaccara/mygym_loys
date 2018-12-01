#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "seances_cures.h" 


//ajouter une seance de cure dans seances_cures.txt
void ajouter_seance(Seance s)
{	FILE* f;
	f=fopen("seances_cures.txt","a");
  	if(f!=NULL) 
 		{  fprintf(f,"%s %d %d %d %d \n", s.type, s.date_seance.jour ,s.date_seance.mois, s.date_seance.annee, s.periode);  	
	fclose(f);  } 	


} 
