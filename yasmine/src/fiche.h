#include <gtk/gtk.h>

typedef struct 
{
char nom[50];
char prenom[50];
int age;
char poids[50];
char taille[50];
char maladies[50];
char regime_alimentaire[50];
char remarques[50];
char id[20];

} fiche;
void ajouter_fiche(fiche fi);
void afficher_fiche(GtkWidget *liste);
void supprimer_fiche(char id2[20]);
