#include <gtk/gtk.h>

typedef struct
{
int jour;
int mois;
int annee;
}Datet;
typedef struct
{
char Id[20];
char Cours[20];
Datet date;
char Heure[20];
int Nombredeplace;
int Nombredeplacemax;
}Personnet;
void ajouter_amine(Personnet p);
void afficher_amine(GtkWidget *liste);

void aminesupprimer(char Id[]);//boutton supprimer
Personnet chercheramine(char ide[]);
