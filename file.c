#include <stdio.h>
#include <stdlib.h>
#include "file.h"

File* createFile()
{
    File* newFile = malloc(sizeof(File));
    if (newFile == NULL)
    {
        printf("mem alloc error");
        exit(EXIT_FAILURE);
    }
    newFile->premier = NULL;
    return newFile;
}

void enfiler(File* maFile, int valeur)
{
    Element* aAjouter = malloc(sizeof(Element));
    if ( maFile == NULL || aAjouter == NULL)
    {
        exit(EXIT_FAILURE);
    }
    aAjouter->Value = valeur;
    aAjouter->suivant = NULL;
    if (maFile->premier == NULL)
    {
        maFile->premier = aAjouter;
    } else
    {
        Element* index = maFile->premier;
        do
        {
            index = index->suivant;
        }while (index->suivant != NULL);
        index->suivant = aAjouter;
    }
    printf("\nAjoute à la file : %d", valeur);
}

int defiler(File* mafile)
{
    int valeur = 0;
    if (mafile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element* aDefiler = mafile->premier;
    valeur = aDefiler->Value;
    mafile->premier = aDefiler->suivant;
    free(aDefiler);
    printf("\n Supprimer de la file : %d", valeur);
    return valeur;
}

void afficherFile(File* laFile)
{
    if (laFile == NULL || laFile->premier == NULL)
    {
        printf("error");
        exit(0);
    }
    printf("\n etat de la file\n");
    Element* aAfficher = laFile->premier;
    do
    {
        printf(" %d > ", aAfficher->Value);
        aAfficher = aAfficher->suivant;
    } while (aAfficher != NULL);
    printf("\n");
}
