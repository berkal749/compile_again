#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

TSNode *TSHead = NULL;
SMNode *MHead = NULL;
SMNode *SHead = NULL;


void initialization() {
    
TSHead = NULL;
MHead = NULL;
SHead = NULL;

}

void inserer(char entite[], char code[],char type[],char val[], int y)
{
    switch(y)
    {
        case 1: {
            TSNode *newNode = malloc(sizeof(TSNode));
            newNode->state = 1;
            strcpy(newNode->name, entite);
            strcpy(newNode->code, code);
            strcpy(newNode->type, type);
            strcpy(newNode->val, val);
            newNode->next = NULL;
            if(TSHead == NULL)
            {
                TSHead = newNode;
                break;
            }

            TSNode *current = TSHead;
            while(current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
            break;
        }
        case 2: {
            SMNode *newNode = malloc(sizeof(SMNode));
            strcpy(newNode->name, entite);
            strcpy(newNode->type, type);
            newNode->next = NULL;
            if(MHead == NULL)
            {
                MHead = newNode;
                break;
            }

            SMNode *current = MHead;
            while(current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
            break;
        }
         case 3: {
            SMNode *newNode = malloc(sizeof(SMNode));
            strcpy(newNode->name, entite);
            strcpy(newNode->type, type);
           newNode->next = NULL;
            if(SHead == NULL)
            {
                SHead = newNode;
                break;
            }

            SMNode *current = SHead;
            while(current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
            break;
        }
    }
}

void rechercher(char entite[], char code[],char type[],char val[],int y)
{
    switch(y)
    {
        case 1: {
            TSNode *current = TSHead;
            while((current != NULL)&&(strcmp(current->name, entite) != 0)&&(current->state == 1))
            {
                current = current->next;
            }

            if((current == NULL) || strcmp(current->name, entite) != 0)
            {
                inserer(entite, code, type, val, 1);
            }
            else
            {
                printf("L'entite %s existe deja\n", entite);
            }
            break;
            
        }
        case 2: {
            SMNode *current = MHead;
            while((current != NULL)&&(strcmp(current->name, entite) != 0))
            {
                current = current->next;
            }
            
            if(current == NULL || strcmp(current->name, entite) != 0)
            {
                inserer(entite, code, type, val, 2);
            }
            else
            {
                printf("L'entite %s existe deja\n", entite);
            }
            break;
            
        }
        case 3: {
            SMNode *current = SHead;
            while((current != NULL)&&(strcmp(current->name, entite) != 0))
            {
                current = current->next;
            }
            
            if(current == NULL || strcmp(current->name, entite) != 0)
            {
                inserer(entite, code, type, val, 3);
            }
            else
            {
                printf("L'entite %s existe deja\n", entite);
            }
            break;
        }
    }
}

void afficher()
{
    printf("\n____________________________________________________________________\n");
    printf("/***************Table des symboles IDF et CST*************/\n");
    printf("____________________________________________________________________\n");
    printf("\t| Nom_Entite |  Code_Entite | Type_Entite | Val_Entite\n");
    printf("____________________________________________________________________\n");

    TSNode *current = TSHead;
    while(current != NULL)
    {
        printf("\t|%11s |%12s | %12s | %12s\n", current->name, current->code, current->type, current->val);
        current = current->next;
    }


    printf("\n____________________________________________________________________\n");
    printf("\n/***************Table des symboles mots cles*************/\n");
    printf("_____________________________________\n");
    printf("\t| NomEntite |  CodeEntite | \n");
    printf("_____________________________________\n");

    SMNode *currentM = MHead;
    while(currentM != NULL)
    {
        printf("\t|%10s |%12s \n", currentM->name, currentM->type);
        currentM = currentM->next;
    }


    printf("\n____________________________________________________________________\n");
    printf("\n/***************Table des symboles separateurs*************/\n");
    printf("_____________________________________\n");
    printf("\t| NomEntite |  CodeEntite | \n");
    printf("_____________________________________\n");

    SMNode *currentS = SHead;
    while(currentS != NULL)
    {
        printf("\t|%10s |%12s \n", currentS->name, currentS->type);
        currentS = currentS->next;
    }



}
