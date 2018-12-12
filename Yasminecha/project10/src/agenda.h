#include <gtk/gtk.h>

typedef struct 
{
int jour;
int mois;
int annee;
char heure[50];
char notes[50];
char id[20];
} agenda;
void ajouter_agenda(agenda ag);
void afficher_agenda(GtkWidget *liste);
void supprimer_agenda(char id1[20]);

