#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acct.h"

#define MAX 256

compte get_compte(int ide)
{
    compte cpt ;
    FILE *f;
    
    
    f=fopen("accounts.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s",&cpt.id,&cpt.nom,&cpt.prenom,
        &cpt.datenaiss.jour,&cpt.datenaiss.mois,&cpt.datenaiss.annee,&cpt.sexe,&cpt.ville,&cpt.numtel,&cpt.ligne)!=EOF)
        {
            
            if (cpt.id==ide)
            {
                return(cpt);
            }
        }
    }
} 
