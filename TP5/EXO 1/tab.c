#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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