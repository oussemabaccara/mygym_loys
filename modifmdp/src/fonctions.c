#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
int verif(char password[])
{
 FILE*f;
 char login1[30],password1[30];
 int role1,x1;
 x1=-1;

 f=fopen("/home/oussemabaccara/Projects/project2/src/auth.txt","r");//lecture de fichier



 if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %d",login1,password1,&role1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (x1==-1 && strcmp(password1,password)==0)//test d'auth
			x1=1;	           	
	}
     fclose(f);   
    }
    return(x1);
}
void modif(char password[],char mdp[])
{
 FILE*f;
 char login1[30],password1[30];
 int role1,x1;
 x1=-1;

 f=fopen("/home/oussemabaccara/Projects/project2/src/auth.txt","r+");//lecture de fichier



 if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %d",login1,password1,&role1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (x1==-1 && strcmp(password1,password)==0)//test d'auth
		{
			strcpy(password1,mdp);
			fprintf(f,"%s %s %d",login1,password1,role1);
			x1=1;
		}	           	
	}
     fclose(f);   
    }
}


