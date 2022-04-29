//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "kubelkowe.hh"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

 void kubelkowe(int* tab, int l, int r) 
 {
    int max = r;
    int min = l;
    int lw[max];
    for (int i = min; i <= max; i++)
    {
        lw[i] = 0;
    }
    for(int i = min; i <= max; i++) 
    {
        lw[tab[i]-1]++;
    }
    int k = 0;
    for(int i = min; i <= max; i++) 
    {
        for (int j = 0; j < lw[i]; j++)
        {
            tab[k] = i+1;
            k++;
        }     
    }
}
