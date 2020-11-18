#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define tabsize 10
#define TAILLEINITIALE 100

int initTab(int*, int);

int afficheTab(int*, int, int);

int* ajoutElementDansTableau(int*, int*, int*, int);