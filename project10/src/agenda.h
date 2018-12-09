#include <gtk/gtk.h>

typedef struct 
{
char jour[150];
char mois[150];
char annee[150];
char heure[150];
char notes[150];

} agenda;
void ajouter_agenda(agenda ag);
void afficher_agenda(GtkWidget *liste);
