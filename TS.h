#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TSNode {
    int state;
    char name[20];
    char code[20];
    char type[20];
    char val[20];
    struct TSNode* next;
} TSNode;

typedef struct SMNode {
    char name[20];
    char type[20];
    struct SMNode* next;
} SMNode;

/* GLOBAL TABLES */
extern TSNode *TSHead;
extern SMNode *MHead;
extern SMNode *SHead;

/* FUNCTION PROTOTYPES */
void initialization();
void inserer(char entite[], char code[], char type[], char val[], int y);
int  recherche(const char *name);
void rechercher(char entite[], char code[], char type[], char val[], int y);
void afficher();
void affecterType(char* type);

#endif
