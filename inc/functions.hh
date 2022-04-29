//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#ifndef FUNCTIONS
#define FUNCTIONS
using namespace std; 
#include "scalanie.hh"
#include "quicksort.hh"
#include "kubelkowe.hh"
#include <iomanip>

int* newTab(int X);
void printEl(int* tab, int n);
bool test (int* tab, int n);
void SortScalanie(int* tab, int X);
void SortQuicksort(int* tab, int X);
void SortKubelkowe(int* tab, int X);
void median(int* tab, int X);
void mean(int* tab, int X);
int* loadData(int X);

#endif
