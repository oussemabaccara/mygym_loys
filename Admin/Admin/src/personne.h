#include <gtk/gtk.h>

typedef struct
	{
	 int jour;
	 int mois;
	 int annee;
	}Date;

typedef struct
	{
	 char id[20];
	 char nom[20];
	 char prenom[30];
	 char role[30];
	 Date date;
	}Personne;

Personne get_personne(char ide[30]);
void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
