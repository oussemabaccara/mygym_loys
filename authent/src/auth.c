#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"

/*void ajouter(char login[],char password[],int role)
{ FILE*f;
  f=fopen("auth.txt","a+");//ouvrir un fichier en mode append
  if (f!=NULL)//test pour ouverture du fichier
  {
	fprintf(f,"%s %s %d \n",login,password,role);//ecrire dans le fichier
  }
  else
  {
	printf("impossible d'ouvrir le fichier");}
	fclose(f);//fermeture de fichier
  }*/

/*void  afficher()
{
 FILE*f;
 char login[30],password[30];
 int role;

 f=fopen("auth.txt","r");//lecture de fichier
 if(f != NULL)//test d'ouverture du fichier
 { while (!EOF)//condition pour quitter le fichier
	{ fscanf(f,"%s %s %d",login,password,&role);
	  printf("%s %s %d",login,password,role);
	}
 }
 fclose(f);
}*/
int verifier(char login[], char password[])
{
 FILE*f;
 char login1[30], password1[30];
 int role1,x1;
 x1=-1;

 f=fopen("/home/oussemabaccara/Projects/project2/src/auth.txt","r");//lecture de fichier



 if(f !=NULL)// test d'ouverture de fichier
    {

        while(fscanf(f,"%s %s %d",login1,password1,&role1)!=EOF)//parcours fichier+tantqu' on est encore avant la fin du fichier
        {

        	if (x1==-1 && strcmp(login1,login)==0 && strcmp(password1,password)==0)//test d'auth
			x1=role1;	           	
	}
     fclose(f);   
    }
    return(x1);
}
