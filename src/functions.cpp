//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include "functions.hh"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;
clock_t Start;
clock_t End;

 void printEl(int* tab, int X) 
 {
	cout << endl;
	for (int i = 0; i < X; i++) 
    {
      cout << tab[i] << ", ";
	  }
  cout << endl;
}

int* newTab(int X)
{
	int* tab = new int[X];
	int min = 1;
	int max = 10;
	srand((unsigned)time(NULL));
  for(int i = 0; i < X; i++) 
  {
		tab[i] = min + rand() % (max-min+1);
  }
	return tab;
}

bool test (int* tab, int n)
{
  for (int i = 0; i < n-1 ; i++)
  {
    if (tab[i] > tab[i+1])
    {
      return 0;
    }
  }
  return 1;
}

void SortScalanie(int* tab, int X)
{
  if (X <= 20)
  {
    cout <<  "Tablica przed posortowaniem:"<< endl ;
    printEl(tab, X);
  }
  Start = clock();
  scalanie(tab, 0, X-1);
  End = clock();
  if (test(tab, X))
  {
    if (X <= 20)
    { 
    	cout << "Oto tablica po sortowaniu przez scalanie:"<< endl ;
	    printEl(tab, X);
    }
  	else
    {
	    cout << "Sortowanie przez scalanie przebiegło poprawnie"<< endl ;
    }
  median(tab,X);
  mean(tab,X);
  cout << "Czas sortowania wynosił: " << ((double)(End - Start))/(CLOCKS_PER_SEC/1000) << " ms" << endl ;
  }
  else
  {
    cout << "Błąd podczas sortowania"<< endl ;
  }
}

void SortQuicksort(int* tab, int X)
{
  if (X <= 20)
  {
    cout << "Tablica przed posortowaniem:"<< endl ;
    printEl(tab, X);
  }
  Start = clock();
	quicksort(tab, 0, X-1);
  End = clock();
  if (test(tab, X))
  {
    if (X <= 20)
    {
    	cout << "Oto tablica po sortowaniu przez quicksort:"<< endl ;
	    printEl(tab, X);
	  }
	  else
	  {
	    cout << "Sortowanie quciksortem przebiegło poprawnie"<< endl ;
	  }
    median(tab,X);
    mean(tab,X);
    cout << "Czas sortowania wynosił: " << ((double)(End - Start))/(CLOCKS_PER_SEC/1000) << " ms" << endl ;
  }
  else
  {
    cout << "Błąd podczas sortowania"<< endl ;
  }
}

void SortKubelkowe(int* tab, int X)
{
  if (X <= 20)
  {
    cout << "Tablica przed posortowaniem:"<< endl ;
    printEl(tab, X);
  }
  Start = clock();
	kubelkowe(tab, 0, X-1);
  End = clock();
  if (test(tab, X))
  {
    if (X <= 20)
    {
    	cout << "Oto tablica po sortowaniu przez scalanie:"<< endl ;
	    printEl(tab, X);
	  }
	  else
	  {
	    cout << "Sortowanie przez kubełkowanie przebiegło poprawnie"<< endl ;
	  }
    median(tab,X);
    mean(tab,X);
    cout << "Czas sortowania wynosił: " << ((double)(End - Start))/(CLOCKS_PER_SEC/1000) << " ms" << endl ;
  }
  else
  {
    cout << "Błąd podczas sortowania" << endl;
  }
}

void median(int* tab, int X)
{
  int i = 0;
  double med;
  if (X%2 == 0)
  {
    i = X/2;
    med = (tab[i-1] + tab[i]);
    med = med/2;
  }
  else
  {
    i = X/2;
    med = tab[i];
  }
  cout << "Mediana ocen filmów wynosi: " << med << endl;
}

void mean(int* tab, int X)
{
  double me = 0;
  for (int i = 0; i < X-1; i++)
  {
    me = me+tab[i];
  }
  me = me/X;
  cout << "Średnia ocen filmów wynosi: " << me << endl;
}

int* loadData(int X)
{
  int i = 0;
  int* tab = newTab(X);
  FILE* file = fopen("dane.csv","r");
  while (1)
   {
      int g = 0;            
      char linijka[200];   
      fgets(linijka, 200, file);
      //cout << linijka << endl;
      if((feof(file) != 0) || (X+1 == i))
	    {
	      break;
	    }
      if (X <= 20)
      {
        cout << linijka;
      }
      while (linijka[g] != '\n')
	      {
          if ((linijka[g] == ',')&&(i>0))
          {
            if (((linijka[g+1] == '1') || (linijka[g+1] == '2') || (linijka[g+1] == '3') ||
               (linijka[g+1] == '4') || (linijka[g+1] == '5') || (linijka[g+1] == '6') || 
               (linijka[g+1] == '7') || (linijka[g+1] == '8') || (linijka[g+1] == '9') || 
               (linijka[g+1] == '0')) && ((linijka[g+2] == '0') || linijka[g+2] == '.' ))
            {
            tab[i-1] = (int)linijka[g+1]-48;
            if (linijka[g+2] == '0')
              {
                tab[i-1] = 10;
              }
            }
          }
        g++;
        }
        g = 0;
        i++;
    }
  fclose(file);
  cout << endl;
  return tab;
}

 