typedef struct
{	
	char jour[10];
	char mois[10];
	char annee[10];
}Date;

typedef struct
{	
	char num[10];
	char type[50];
	char periode[50];
	char nbp[10];
	Date date_seance;
}Seance;

void ajouter_seance(Seance s);
void afficher_seance(GtkWidget *liste);
void intstring(int x,char su[]);
void modifier_seance(char n[],char modif[]);
void supprimer_seance(char n[]);

