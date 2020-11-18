#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tab.h"
#define tabsize 10
#define TAILLEINITIALE 100
#define TAILLEAJOUT 50

int main() {
	
	int* myTab2 = NULL;
	int TAB2SIZE = TAILLEINITIALE;
	int nbElts = 100;
	
	
	myTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int));
	
	if (myTab2 != NULL) { initTab(myTab2, TAB2SIZE); }
	
	else { printf("mémoire insuffisante"); return(-1); }
	
	for (int i = 0; i < nbElts; i++) {   //on remplie les 20 premières valeurs du tableau
		*(myTab2 + i) = i + 1;
	}
	ajoutElementDansTableau(myTab2, &TAB2SIZE, &nbElts, 101);
	afficheTab(myTab2, TAB2SIZE, 100);
	
	
	free(myTab2);

	return EXIT_SUCCESS;
}