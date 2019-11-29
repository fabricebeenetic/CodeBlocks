/* Le but de ce petit programme est de faire deviner un nombre compris entre 0 et 100

Le programme tire un nombre au hasard.
Il est demandé à l'utilisateur de deviner le nombre mystère en sasissant une valeur comprise entre 0 et 100
Apres chaque sasie, le programme compare la sasie avec le nombre mystère.
Si la saisie correcpond, on affiche vous avez trouvé en x coups !
Si la saisie est plus petite que le mystère, on affiche Plus grand !
Si la saisie est plus grande que le mystère on affiche, Plus petit !

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "main.h"
#include "tableau.h"


void punition(int nbItteration);
void conversionFrancEuro(int *valeur);
void conversionEuroFranc(int *valeur);
void initialiserUserData(Coordonnees *inputdata);
void initialiserUserDataComposants(Coordonnees *inputdata);


int main(int argc, char *argv[])
{


    // Le jeu du Pendu
    // Créer 5 fichiers avec 1 mot dans chaque fichier
    // Tirer un nombre aleatoire compris entre 1 et 5, x
    // Initialiser le compteur d'essai à nb Max_essai = 10
    // Le mot à deviner sera celui contenu dans le fichier mot_mystere_x.txt
    // Lire le contenu du fichier et en deduire la taille du mot, Y
    // Créer un tableau dynamique de Y valeurs pour le stockage des proposition du joueur
    // Afficher Devinez le mot mystere : suivi par Y etoiles séparées par un espace
    // Demander au joueur de proposer une lettre MAJUSCULE, L
    // Rechercher si la lettre fait partie du mot mystère, une chaine de caracteres se manipule comme un tableau!!
    // Si la lettre ne fait pas partie du mot, décrémenter le compteur d'essai
    // Si le compteur n'est pas nul, afficher La lettre L ne fait pas parti du mot mystère, Il vous reste n essais !!

    // Si la lettre fait partie du mot, Ajouter la lettre dans le tableau réponse à la bonne place puis
    // Rechercher si elle n'y est pas plusieurs fois
    // Decrementer le nombre de caractères non decouverts
    // Si e nombre de caractères non decouverts devient nul, et que le compteur d'essais est non nul, c'est gagné!!



    printf("Le jeu du pendu !\n");



    // Allocation de mémoire dynamique pour gérer un tableau
    // Renseigner le tableau avec des valeurs entrées par l'utilisateur
    // Afficher les valeurs et libérer la ressource mémoire
    int nombreData =0;
    int* Data = NULL;
    printf("\nAllocztion dynamiquye de memoire\n");
    printf("Combien avez-vous de données à saisir  ?\n");
    scanf("%d", &nombreData);
    Data = malloc(nombreData *sizeof(int16_t));
    if (Data == NULL)
    {
        printf("Probleme d'allocation de memoire !!\n");
        exit(0);
    }
    for (int i=0; i<nombreData; i++)
    {
        printf ("Saisissez la donnée %d/%d : !\n", i+1, nombreData);
        scanf("%d", &Data[i]);
    }
    printf("synthèse de votre saisie\n");
    for (int i=0; i<nombreData; i++)
    {
        printf ("Donnée %d, valeur %d : !\n",i+1, Data[i]);
    }
    free(Data);

    printf("char : %d octets\n", (int) sizeof(char));
    printf("int : %d octets\n", (int) sizeof(int));
    printf("long : %d octets\n", (int) sizeof(long));
    printf("double : %d octets\n", (int) sizeof(double));


    // Gestion de fichier, ouverture, lecture du contenu string
    FILE *fichier = NULL;
    char chaine_text[TAILLE_MAX_FICHIER]="";

    fichier = fopen("testFile.txt","r");
    if (fichier!=NULL)
    {
        while(fgets(chaine_text, TAILLE_MAX_FICHIER, fichier) != NULL)
        {
            printf("%s", chaine_text);
        }
        fclose(fichier);
    } else
    {
        printf("Fichier inexistant !!\n");
    }


    Coordonnees* Userdata=NULL;
    printf("taille de la structure %d :", (int) sizeof(Coordonnees));

    Userdata = malloc(sizeof(Coordonnees));
    if (Userdata==NULL) // on verifie que l'allocation a réussie
    {
        exit(0); // Erreur : on arrête tout !
    }
    else
    {
        initialiserUserData(Userdata);
        initialiserUserDataComposants(Userdata);

        printf("\nSaisissez vos coordonnées !!\n");
        printf("Quel est votre prenom ?\n");
        scanf("%s", Userdata->prenom);
        printf("Quel est votre nom de famille %s ?\n", Userdata->prenom);
        scanf("%s", Userdata->nom);
        printf("Où habitez vous %s ?\n", Userdata->prenom);
        scanf("%s", Userdata->adresse);
        printf("Quel âge avez vous %s ?\n", Userdata->prenom);
        scanf("%d", &Userdata->age);
        printf("Etes vous homme = 0, ou Femme = 1 %s ?\n", Userdata->prenom);
        scanf("%d", &Userdata->sexe);

        MAJEUR(Userdata->age)
        free(Userdata);
    }


    int taille_table = 8;
    int table1[taille_table];
    int table2[taille_table];
    int userChoice = 0; // valeur sasie par le joueur

    printf("initialisation !!\n");
    for ( int i=0; i<taille_table; i++ )
    {
        printf (" \nValeur du tableau position %d ?\n", i);
        scanf ("%d", &userChoice);
        table1[i] = userChoice;
        table2[i] = 0;
    }
    printf ("Somme element tableau = %d !!\n", sommeTableau(table1, taille_table));
    printf ("Moyenne element tableau = %f !!\n", moyenneTableau(table1, taille_table));
    printf ("Copie element tableau !!\n" );
    copieTableau(table1, table2, taille_table);

    for ( int i=0; i<taille_table; i++ )
    {
        printf ("Element %d = %d !!\n", i, table2[i]);
    }

    printf("Suppression des maximum !!\n");
    printf (" \nQuel est le seuil de filtrage du tableau ?\n");
    int tabMaxi = 0;
    scanf ("%d", &tabMaxi);
    maximumTableau(table2, taille_table, tabMaxi);
    for ( int i=0; i<taille_table; i++ )
    {
        printf ("Element de tableau traité %d = %d !!\n", i, table2[i]);
    }

    printf("Rangement par ordre croissant du tableau 1 : ");
    ordreCroisantTableau(table1, taille_table);
    for ( int i=0; i<taille_table; i++ )
    {
        printf ("Element %d = %d !!\n", i, table1[i]);
    }


    int nombreMystere = 0; // Valeur mystere tiree par le programme
    int *pointer_nombreMystere = &nombreMystere;
    int triesCount = 0; // Compteur du nombre de tentatives
    int *pointer_userChoice = &userChoice;
    const int MAX = 100, MIN = 1; // valeurs limites de la valeur aleatoire

    // tirage au sort du nombre mystere
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    int rightNumber = 0; // On joue tant que le nombre mystere n'est pas decouvert

    printf ("=== Punition ===\n");
    printf (" \nCombien avez-vous de lignes à recopier ?\n");
    scanf ("%d", &userChoice);
    punition(userChoice);

    printf ("\n=== Jeu du Nombre Mystere ===\n");

    while (!rightNumber)
    {
        printf (" \nQuel est le nombre mystere ?\n");
        scanf ("%d", &userChoice);

        if (userChoice == nombreMystere)
        {
            triesCount++;
            printf("Bravo, vous avez trouve le nombre mystere en %d essais !!!\n", triesCount);
            rightNumber = 1;
        } else if (userChoice > nombreMystere)
        {
            printf("C'est moins !!!\n");
            triesCount++;
        } else if (userChoice < nombreMystere)
        {
            printf("C'est plus !!!\n");
            triesCount++;
        }

    }
    // Conversion du nombre mystere en francs
    conversionEuroFranc(pointer_nombreMystere);
    printf("la valeur mystere en francs vaut %d !!", *pointer_nombreMystere);

    printf (" \nMontant en Francs à convertir en euros ?\n");
    scanf ("%d", &userChoice);
    conversionFrancEuro(pointer_userChoice);
    printf("Votre montant vaut %d Francs !!", *pointer_userChoice);


    return 0;


}

void punition(int nbItteration)
{
    for( int i=1; i<nbItteration; i++)
    {
        printf("Je ne dois pas recopier mon voisin\n");
    }
}

void conversionFrancEuro(int *valeur)
{
    const double taux = TAUX_EUROS_FRANCS;
    *valeur /= taux;

}

void conversionEuroFranc(int *valeur)
{
    const double taux = TAUX_EUROS_FRANCS;
    *valeur *= taux;

}

void initialiserUserData(Coordonnees *inputdata)
{
    inputdata->prenom[SIZE_NAME] = ' ';
    inputdata->nom[SIZE_NAME] = ' ';
    inputdata->adresse[SIZE_ADDRESS] = ' ';
    inputdata->age = 0;
    inputdata->sexe = 0;
}

void initialiserUserDataComposants(Coordonnees *inputdata)
{
    inputdata->prenom[SIZE_NAME] = ' ';
    inputdata->nom[SIZE_NAME] = ' ';
    inputdata->adresse[SIZE_ADDRESS] = ' ';
    inputdata->age = 0;
    inputdata->sexe = 0;
}
