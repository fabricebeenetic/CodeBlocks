#include <stdlib.h>
#include <stdio.h>
#include "liste.h"


Liste* initialisation(int valeur)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    Liste *chainedList = malloc(sizeof(*chainedList));

    if (nouveau == NULL || chainedList == NULL)
    {
        printf("Erreur allocation mémoire");
        exit(0);
    }

    nouveau->Value = valeur;
    nouveau->suivant = NULL;
    chainedList->premier = nouveau;
    chainedList->nbElement=1;

    return chainedList;
}

void insertion(Liste *tete, int nombre)
{
    Element *ajout = malloc(sizeof(*ajout));
    if (ajout == NULL)
    {
        printf("Erreur allocation mémoire");
        exit(0);
    }
    ajout->suivant=tete->premier;
    ajout->Value=nombre;
    tete->premier=ajout;
    tete->nbElement++;
}

void suppressionPremier(Liste * tete)
{
    if (tete == NULL)
    {
        printf("suppression buffer Null impossible");
        exit(0);
    }
    if (tete->premier!=NULL)
    {
        Element *aSupprimer = tete->premier;
        tete->premier=tete->premier->suivant;
        tete->nbElement--;
        free(aSupprimer);
    }
}

void afficherListe(Liste* tete)
{
    if (tete->premier == NULL)
    {
        printf("liste vide!!");
        exit(0);
    }
    Element* aAfficher = tete->premier;
    printf("\nLa Liste\n");
    while (aAfficher!=NULL)
    {
        printf("%d > ", aAfficher->Value);
        aAfficher = aAfficher->suivant;
    }
    printf("NULL\n\n");
}

void supprimerItemN(Liste* tete, int index)
{
    printf("\nTaille liste %d", tete->nbElement);
    printf("\nItem a supprimer %d", index);
    if (tete->premier==NULL || tete->nbElement<index)
    {
        printf("suppression impossible");
        exit(0);

    }
    Element* aSupprimer=tete->premier;
    if(index==1)
    {
        tete->premier=aSupprimer->suivant;
        free(aSupprimer);
        tete->nbElement--;
    }
    else
    {
        Element* precedent = NULL;
        for (int i=1; i<index; i++)
        {
            precedent = aSupprimer;
            aSupprimer = aSupprimer->suivant;
            printf("\nElement precedent %d", precedent->Value);
            printf("\nElement a supprimer %d", aSupprimer->Value);
        }

        precedent->suivant=aSupprimer->suivant;
        free(aSupprimer);
        tete->nbElement--;
    }

}
