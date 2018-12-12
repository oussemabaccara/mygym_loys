#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "offre.h"

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

