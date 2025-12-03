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

TSNode *TSHead = NULL;
SMNode *MHead = NULL;
SMNode *SHead = NULL;

// Initialize heads
void initialization() {
    TSHead = NULL;
    MHead = NULL;
    SHead = NULL;
}

// Insert function
void inserer(const char entite[], const char code[], const char type[], const char val[], int y) {
    if (y == 1) {
        TSNode *newNode = malloc(sizeof(TSNode));
        if (!newNode) { perror("malloc failed"); exit(1); }
        newNode->state = 1;
        strcpy(newNode->name, entite);
        strcpy(newNode->code, code);
        strcpy(newNode->type, type);
        strcpy(newNode->val, val);
        newNode->next = NULL;

        if (!TSHead) {
            TSHead = newNode;
        } else {
            TSNode *cur = TSHead;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
    } else if (y == 2) {
        SMNode *newNode = malloc(sizeof(SMNode));
        if (!newNode) { perror("malloc failed"); exit(1); }
        strcpy(newNode->name, entite);
        strcpy(newNode->type, type);
        newNode->next = NULL;

        if (!MHead) {
            MHead = newNode;
        } else {
            SMNode *cur = MHead;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
    } else if (y == 3) {
        SMNode *newNode = malloc(sizeof(SMNode));
        if (!newNode) { perror("malloc failed"); exit(1); }
        strcpy(newNode->name, entite);
        strcpy(newNode->type, type);
        newNode->next = NULL;

        if (!SHead) {
            SHead = newNode;
        } else {
            SMNode *cur = SHead;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
    }
}

// Search function
void rechercher(const char entite[], const char code[], const char type[], const char val[], int y) {
    if (y == 1) {
        TSNode *cur = TSHead;
        while (cur && (strcmp(cur->name, entite) != 0 || cur->state != 1)) cur = cur->next;

        if (!cur || strcmp(cur->name, entite) != 0) {
            inserer(entite, code, type, val, 1);
        } else {
            printf("L'entite %s existe deja\n", entite);
        }
    } else if (y == 2) {
        SMNode *cur = MHead;
        while (cur && strcmp(cur->name, entite) != 0) cur = cur->next;

        if (!cur) {
            inserer(entite, code, type, val, 2);
        } else {
            printf("L'entite %s existe deja\n", entite);
        }
    } else if (y == 3) {
        SMNode *cur = SHead;
        while (cur && strcmp(cur->name, entite) != 0) cur = cur->next;

        if (!cur) {
            inserer(entite, code, type, val, 3);
        } else {
            printf("L'entite %s existe deja\n", entite);
        }
    }
}

// Display tables
void afficher() {
    printf("\n--- Table des symboles IDF et CST ---\n");
    printf("Nom_Entite | Code_Entite | Type_Entite | Val_Entite\n");
    TSNode *cur = TSHead;
    while (cur) {
        printf("%-11s | %-12s | %-12s | %-12s\n", cur->name, cur->code, cur->type, cur->val);
        cur = cur->next;
    }

    printf("\n--- Table des symboles mots cles ---\n");
    printf("NomEntite | CodeEntite\n");
    SMNode *curM = MHead;
    while (curM) {
        printf("%-10s | %-12s\n", curM->name, curM->type);
        curM = curM->next;
    }

    printf("\n--- Table des symboles separateurs ---\n");
    printf("NomEntite | CodeEntite\n");
    SMNode *curS = SHead;
    while (curS) {
        printf("%-10s | %-12s\n", curS->name, curS->type);
        curS = curS->next;
    }
}

// Example usage
int main() {
    initialization();

    rechercher("x", "ID", "int", "0", 1);
    rechercher("y", "ID", "int", "0", 1);
    rechercher("total", "ID", "float", "0.0", 1);
    rechercher("print", "KW", "function", "", 2);
    rechercher("{", "SEP", "separator", "", 3);

    afficher();

    return 0;
}
