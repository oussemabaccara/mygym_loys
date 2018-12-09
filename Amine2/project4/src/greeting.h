#include <gtk/gtk.h>

typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct
{
int Id;
char Cours[20];
Date date;
char Heure[20];
int Nombredeplace;
int Nombredeplacemax;
}Personne;
void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
