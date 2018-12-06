#include <gtk/gtk.h>

typedef struct
{
char Cours[20];
char Date[20];
char Heure[20];
char Nombredeplace[20];
}Personne;
void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
