typedef struct
{
    char jour[6];
    char mois[6];
    char annee[6];
}age;

typedef struct
{
    int id;
    char nom[20];
    char prenom[20];
    age datenaiss;
    char sexe[20];
    char ville[20];
    char numtel[20];
    char ligne[20];
}compte;

compte get_compte(int ide); 
