int sommeTableau(int tableau[], int tailleTab)
{
    int somme = 0;
    for (int i=0; i<tailleTab; i++)
    {
        somme += tableau[i];
    }
    return somme;

}


double moyenneTableau(int tableau[], int tailleTab)
{
    double moyenne = 0;
    for (int i=0; i<tailleTab; i++)
    {
        moyenne += tableau[i];
    }
    moyenne /= tailleTab;
    return moyenne;

}

void copieTableau(int tableau1[], int tableau2[], int tailleTab)
{
    for (int i=0; i<tailleTab; i++)
    {
        tableau2[i] += tableau1[i];
    }

}

void maximumTableau(int tableau1[], int tailleTab, int maximum)
{
    for (int i=0; i<tailleTab; i++)
    {
        if (tableau1[i] >= maximum)
        {
            tableau1[i] = 0;
        }
    }

}

void ordreCroisantTableau(int tableau1[], int tailleTab)
{
    int swap = 0;
    int move = 0;
    do
    {
        swap = 0;
        for (int i=0; i<tailleTab; i++)
        {
            if (tableau1[i] > tableau1[i+1])
            {
                move = tableau1[i];
                tableau1[i] = tableau1[i+1];
                tableau1[i+1] = move;
                swap += 1;

            }
        }

    } while (swap);

}
