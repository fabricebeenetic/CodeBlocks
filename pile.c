#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

pile* createHeap()
{
    pile *newheap = malloc(sizeof(pile));
    if (newheap == NULL)
    {
        printf ("probleme creation pile");
        exit(0);
    }
    newheap->premier = NULL;
    return newheap;
}

void empiler(pile* laPile, int nombre)
{
    Element* newElement = malloc(sizeof(Element));
    if (laPile==NULL || newElement == NULL)
    {
        printf("memoire insuffisante ou pile invalide");
        exit(0);
    }
    newElement->Value = nombre;
    newElement->suivant = laPile->premier;
    laPile->premier = newElement;
    printf("\nAjoute à la pile : %d", nombre);
}

int depiler(pile* laPile)
{
    int valeur = 0;
    Element* aEnlever = laPile->premier;
    if (laPile!=NULL && aEnlever!=NULL)
    {
        valeur = aEnlever->Value;
        laPile->premier = aEnlever->suivant;
        free(aEnlever);
    }
    return valeur;
}

void afficherPile(pile* laPile)
{
    if (laPile == NULL || laPile->premier == NULL)
    {
        printf("error");
        exit(0);
    }
    printf("\n etat de la pile\n");
    Element* aAfficher = laPile->premier;
    do
    {
        printf(" %d > ", aAfficher->Value);
        aAfficher = aAfficher->suivant;
    } while (aAfficher != NULL);
    printf("\n");
}
