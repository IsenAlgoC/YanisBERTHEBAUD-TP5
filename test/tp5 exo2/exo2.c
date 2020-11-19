#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.elt = (int*)malloc(tab.size * sizeof(int));
	if (tab.elt == NULL) return tab;
	for (int i = 0; i < tab.size; i++) {
		*(tab.elt + i) = 0;
	}
	tab.eltsCount = 0;
	return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if (((*tab).elt == NULL) || (incrementValue <= 0)) return -1;
	int* tmp = (*tab).elt;
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));
	if ((*tab).elt == NULL) {
		(*tab).elt = tmp;
		return -1;
	}
	for (int i = (*tab).size; i < (*tab).size + incrementValue - 1; i++) {
		(*tab).elt[i] = 0;
	}
	(*tab).size += incrementValue;
	return (*tab).size;
}

int setElement(TABLEAU* tab, int pos, int element) {
	if (((*tab).elt == NULL) || (pos < 1)) return 0;
	if (pos - 1 < (*tab).size) {
		(*tab).elt[pos - 1] = element;
		return 0;
	}
	else {
		
		if (incrementArraySize(tab, pos - (*tab).size) == -1) return 0;
		(*tab).elt[pos - 1] = element;
		return pos;

	}
}

int displayElements(TABLEAU *tab, int startPos, int endPos) {
	int temp;
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size) || (endPos < 1) || (startPos > (*tab).size)) return -1;
	if (startPos > endPos) {
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {
		printf("pos %d : %d\n", startPos, (*tab).elt[startPos - 1]);
		return 0;
	}
	for (int i = startPos - 1; i < endPos; i++) {
		printf("%d ", (*tab).elt[i]);
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int* tmp;
	int temp;
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size)) return -1;
	if (startPos > endPos) {
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {
		for (int i = startPos - 1; i < (*tab).size - 1; i++) {
			(*tab).elt[i] = (*tab).elt[i + 1];
		}
		tmp = (*tab).elt;
		(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size -1) * sizeof(int));
		if ((*tab).elt == NULL) {
			(*tab).elt = tmp;
			return -1;
		}
		return (*tab).size;
	}
	for (int i = startPos - 1; i < (*tab).size - (endPos - startPos + 1); i++) {
		(*tab).elt[i] = (*tab).elt[i + endPos - startPos + 1];
	}
	tmp = (*tab).elt;
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size - (endPos - startPos + 1)) * sizeof(int));
	if ((*tab).elt == NULL) {
		(*tab).elt = tmp;
		return -1;
	}
	return (*tab).size;
}

int main() {
	TABLEAU tab = newArray();	
	setElement(&tab, 1, 1);
	setElement(&tab, 4, 4);
	displayElements(&tab, 1, 4);
	deleteElements(&tab, 2, 3);
	printf("\n");
	displayElements(&tab, 1, 4);
	
	return EXIT_SUCCESS;
}