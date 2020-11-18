#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tab.h"
#define tabsize 10
#define TAILLEINITIALE 100

int main() {
	
	int* myTab2 = NULL;
	int TAB2SIZE = TAILLEINITIALE;
	int nbElts = 0;
	
	myTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int));
	
	if (myTab2 != NULL) { initTab(myTab2, TAB2SIZE); }
	
	else { printf("mémoire insuffisante"); return(-1); }
	
	for (int i = 0; i < 20; i++) {   //on remplie les 20 premières valeurs du tableau
		*(myTab2 + i) = i + 1;
	}

	afficheTab(myTab2, TAB2SIZE,20);
	free(myTab2);


}