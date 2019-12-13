#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "liste.h"

typedef struct File File;

struct File
{
    Element* premier;
};

File* createFile();
void enfiler(File* maFile, int valeur);
int defiler(File* mafile);
void afficherFile(File* laFile);

#endif // FILE_H_INCLUDED
