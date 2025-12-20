#include "TS.h"
TSNode *TSHead = NULL;
SMNode *MHead = NULL;
SMNode *SHead = NULL;

void initialization() {
    TSNode *currentTS = TSHead;
    while (currentTS != NULL) {
        TSNode *temp = currentTS;
        currentTS = currentTS->next;
        free(temp);
    }
    SMNode *currentM = MHead;
    while (currentM != NULL) {
        SMNode *temp = currentM;
        currentM = currentM->next;
        free(temp);
    }
    
    
    SMNode *currentS = SHead;
    while (currentS != NULL) {
        SMNode *temp = currentS;
        currentS = currentS->next;
        free(temp);
    }
    
    
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

int recherche(const char *name) {
    TSNode *cur = TSHead;
    while (cur) {
        if (strcmp(cur->name, name) == 0)
            return 1;
        cur = cur->next;
    }
    return 0;
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
               // printf("L'entite %s existe deja\n", entite);
            }
            break; }
        case 2: {
            SMNode *current = MHead;
            while((current != NULL)&&(strcmp(current->name, entite) != 0))
            {
                current = current->next; }
            
            if(current == NULL || strcmp(current->name, entite) != 0)
            {
                inserer(entite, code, type, val, 2);
            }
            else
            {
               // printf("L'entite %s existe deja\n", entite);
            }
            break;
            
        }
        case 3: {
            SMNode *current = SHead;
            while((current != NULL)&&(strcmp(current->name, entite) != 0))
            {
                current = current->next;  }
            
            if(current == NULL || strcmp(current->name, entite) != 0)
            {
                inserer(entite, code, type, val, 3); }
            else
            {
               // printf("L'entite %s existe deja\n", entite);
                 }
            break;
        }
    }
}

void affecterType(char* type) {
    TSNode *cur = TSHead;
    while (cur) {
        if (strcmp(cur->type,"")==0)
            strcpy(cur->type,type);
        cur = cur->next;
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