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
int ajout_part1(char num[],char id[]);
int modif_nb2(char num[]);
int inscription1(char id[],char num[]);
int modif_nb3(char num[]);
void supression_part1(char num[]);
int annulation1(char id[],char num[]);
