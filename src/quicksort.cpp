//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "quicksort.hh"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void swap(int* tab, int i, int j)
{
    int help = tab[i];
    tab[i] = tab[j];
    tab[j] = help;
}

void quicksort(int *tab, int l, int r)
{
	if(r > l) 
    {
	    int i = l - 1;
        int j = r + 1, 
	    pivot = tab[(l+r)/2]; //wybieramy punkt odniesienia	
	    while(1)
	    {
		    while(pivot>tab[++i]);
		    while(pivot<tab[--j]);
		    if( i <= j)
                {
			        swap(tab, i, j);
                }
		    else
                {
			        break;
                }
        }
	    if(j > l)
        {
	        quicksort(tab, l, j);
        }
	    if(i < r)
        {
	        quicksort(tab, i, r);
        }
    }
}
