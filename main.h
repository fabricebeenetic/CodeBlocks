#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


#define TAUX_EUROS_FRANCS 6.55957
#define SIZE_NAME 30
#define SIZE_ADDRESS 150
#define TAILLE_MAX_FICHIER 1000


#define MAJEUR(age) if (age >= 18)\
printf ("Vous êtes Majeur !!\n");\
else printf("Vous n'êtes pas Majeur, ahah!!\n'");


typedef struct Coordonnees Coordonnees;
struct Coordonnees{
    char prenom[SIZE_NAME];
    char nom[SIZE_NAME];
    char adresse[SIZE_ADDRESS];
    int  age;
    int  sexe;
};

#endif // MAIN_H_INCLUDED
