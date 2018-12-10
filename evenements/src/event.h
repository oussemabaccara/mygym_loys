
#include <gtk/gtk.h>

typedef struct
{
 	int jour;
 	int mois;
	int annee;
}Date;

typedef struct
{	char num[5];
	char nom[40];
	char description[100];
	Date date;
	char heure[10];
	char nombre[5];
	char nombremax[5];
}event;

void afficher_event(GtkWidget *liste);
int ajout_part(char num[],char id[]);
int modif_nb(char num[]);
int inscription(char id[],char num[]);
int modif_nb1(char num[]);
void supression_part(char num[]);
int annulation(char id[],char num[]);



