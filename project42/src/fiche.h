#include <gtk/gtk.h>

typedef struct
{	char id[20];
	char nom[20];
	char prenom[20];
	char age[5];
	char poids[10];
	char taille[10];
	char maladies[100];
} Fiche;


int verifier (char user[]);
void afficher (char user[],char ficha[]);
void ajouter_fiche(Fiche fi);
void afficher_fiche(GtkWidget *liste);
