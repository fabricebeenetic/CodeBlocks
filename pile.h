#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include "liste.h"


typedef struct pile pile;
struct pile
{
    Element* premier;
};

pile* createHeap();
void empiler(pile* laPile, int nombre);
int depiler(pile* laPile);
void afficherPile(pile* laPile);

#endif // PILE_H_INCLUDED
