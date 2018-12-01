typedef struct
{	
	int jour;
	int mois;
	int annee;
}Date;

typedef struct
{	char type[50];
	int periode;
	Date date_seance;
}Seance;

void ajouter_seance(Seance s);

