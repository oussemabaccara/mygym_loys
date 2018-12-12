#include <gtk/gtk.h>
typedef struct
{
    char id[6];
    char mdp[6];
    char role[6];
}user;

typedef struct
{
    char jour[6];
    char mois[6];
    char annee[6];             
}age;

typedef struct
{
    char id[10];
    char nom[20];
    char prenom[20];
    age datenaiss;
    char sexe[20];
    char ville[20];
    char numtel[20];
    char ligne[20];
}compte1;

int getrole(char id[]);
void afficher_med(GtkWidget *liste);
