//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "scalanie.hh"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

void scal(int* tab, int l, int m, int r)
{
	int lSize = m - l + 1;
	int rSize = r - m;
 
	//Tablice pomocnicze
	int* tabL = new int[lSize];
	int* tabR = new int[rSize];
 
	// Kopiowanie danych do tablic pomocniczych
	for (int x = 0; x < lSize; x++)
		tabL[x] = tab[l + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = tab[m + 1 + y];
 
	int indexL = 0;
	int indexR = 0;
	int currIndex;
 
	//Łączenie tablic R i L
	for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++)
	{
		if (tabL[indexL] <= tabR[indexR])
			tab[currIndex] = tabL[indexL++];
		else
			tab[currIndex] = tabR[indexR++];
	}
 
	//Jeśli w tablicy tabL pozostały jeszcze jakieś elementy
	//kopiujemy je
	while (indexL < lSize)
		tab[currIndex++] = tabL[indexL++];
 
	//Jeśli w tablicy tabR pozostały jeszcze jakieś elementy
	//kopiujemy je
	while (indexR < rSize)
		tab[currIndex++] = tabR[indexR++];
    
	delete[] tabL;
	delete[] tabR;
}
 
void scalanie(int* tab, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		scalanie(tab, l, m);
		scalanie(tab, m + 1, r);
		scal(tab, l, m, r);
	}
}
 
 

 
