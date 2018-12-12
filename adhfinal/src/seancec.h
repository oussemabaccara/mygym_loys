#include <gtk/gtk.h>
typedef struct
{
	char jour[10];
	char mois[10];
	char annee[10];
}date;
typedef struct
{	
	char num[5];
	char cours[40];
	date date1;
	char heure[10];
	char nplace[5];
}seancec;
void afficher_seancec(GtkWidget *liste);
int ajout_part2(char num[],char id[]);
int modif_nb4(char num[]);
int inscription2(char id[],char num[]);
int modif_nb5(char num[]);
void supression_part2(char num[]);
int annulation2(char id[],char num[]);
