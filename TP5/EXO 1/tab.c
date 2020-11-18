#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TAILLEAJOUT 50

int initTab(int* tab, int size) {
	if ((tab == NULL) || (size < 0)) return -1;    //si c'est un pointeur NULL ou size < 0 on return -1
	for (int i = 0; i < 10; i++) {
		*(tab+i) = 0;                     //on remplie le tableau de 0
	}
	return size;
}


int afficheTab(int* tab, int size, int nbElts) {
	if ((tab == NULL) || (size < 0) || (size < nbElts)) return -1;
	for (int i = 0; i < nbElts; i++) {
		printf("%d ", *(tab + i));
	}
	return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
    if (tab == NULL || *size < 0 || *nbElts < 0) return NULL; //Valeurs entrées non valides
    if (*nbElts + 1 > *size) { //Test si dépassement de capacité
        int* tmp = tab; //Sauvegarde de l'ancien pointeur si
        tab = (int*) realloc(tab,(*size+TAILLEAJOUT)*sizeof(int));  //Allocation de la mémoire
        if (tab == NULL) { //Vérification que la mémoire a bien été allouée
            tab = tmp;
            return NULL;
        }
        *size += TAILLEAJOUT;
    }
    *(tab + *nbElts) = element;
    *nbElts += 1;
    return tab;
}