#include <stdio.h>
#include <stdlib.h>


int litTailleDico(char* fichier)
{
    FILE *motsMystere = NULL;
    // ouverture du fichier et controle succes
    motsMystere = fopen("MotMystere_1.txt", "r");
    if (!motsMystere)
    {
        printf("\aERREUR: Impossible d'ouvrir le fichier:\n");
        exit(-1);
    }
    // determination du nombre d'éléments du dictionnaire
    int c;
    int nLignes = 0;
    while((c=fgetc(motsMystere)) != EOF)
    {
        if(c=='\n')
            nLignes++;
    }
    nLignes++;
    printf("il y a %d elements dans le dictionnaire\n", nLignes);
    fclose(motsMystere);
    return nLignes;
}

char* litMot(char* fichier, int ID_mot)
{
    char leMotMystere[30];
    char* ptMotMystere = &leMotMystere[0];
    FILE *motsMystere = NULL;
        // Lecture du mot mystere d'indice le nombre aleatoire
        motsMystere = fopen(fichier, "r");
        for (int i=1; i<ID_mot+1; i++)
        {
            fscanf(motsMystere, "%s", leMotMystere);
        }
        fclose(motsMystere);

    return ptMotMystere;
}

void viderLeBuffer()
{
    // vider le buffer stdin
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
