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
void re_acc(Personne p);
void dis_acc(char id[]);
Personne get_personne(char ide[]);
void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
