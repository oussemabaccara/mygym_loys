#include <gtk/gtk.h>

typedef struct
{	char num[5];
	char cours[40];
	char date[100];
	char heure[10];
	char nplace[5];
	char nplacemax[5];
}seancee;

void afficher_seancee(GtkWidget *liste);
