#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED



typedef struct Element Element;
struct Element {
    int Value;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste{
    Element * premier;
    int nbElement;
};


Liste* initialisation(int valeur);
void insertion(Liste *tete, int nombre);
void suppressionPremier(Liste * tete);
void afficherListe(Liste* tete);
void supprimerItemN(Liste* tete, int index);


#endif // LISTE_H_INCLUDED
