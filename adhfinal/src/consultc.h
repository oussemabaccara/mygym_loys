#include <gtk/gtk.h>
typedef struct
{
    char id[6];
    char mdp[6];
    char role[6];
}user1;

typedef struct
{
    char jour[6];
    char mois[6];
    char annee[6];             
}age1;

typedef struct
{
    char id[10];
    char nom[20];
    char prenom[20];
    age1 datenaiss;
    char sexe[20];
    char ville[20];
    char numtel[20];
    char ligne[20];
}compte2;
float calcul_note(char idc[]);
int comparaison_id1(char idc[],char ida[]);
int comparaison_id(char idc[]);
int modif_note(char ida[],char idc[],char note[]);
int ajout_note(char ida[],char idc[],char note[]);
int getrole1(char id[]);
void afficher_c(GtkWidget *liste);
