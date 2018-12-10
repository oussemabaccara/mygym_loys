#include <gtk/gtk.h>

typedef struct 
{	char jour[10];
	char mois[10];
	char annee[10];
	
} Date2 ;

typedef struct 
{
	Date2 date_rdv ;
	char id1[10];
	char id2[10];
	char heure[10];
};


void afficher_rdv(GtkWidget *liste);