typedef struct
{	
	char jour;
	char mois;
	char annee;
}Date;

typedef struct
{	char type[50];
	char periode[50];
	Date date_seance;
}Seance;

void ajouter_seance(Seance s);
void afficher_seance(GtkWidget *liste);
void intstring(int x,char su[]);

