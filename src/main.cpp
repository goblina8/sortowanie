//Gabriela Kaczmarek 259234 PAMSI czw. 9:15 2022r
#include <iostream>
#include "functions.hh"
#include <time.h>
using namespace std;

int main()
{
  clock_t Start;
  clock_t End;
  int* tab;
  int X;
  char choice;
  system("clear");
  cout << "Ile liczb ma zostać posortowanych?" << endl;
  cin >> X;
  cout << "Jakiego sortowania chcesz użyć?" << endl;
  cout << "s - scalanie" << endl;
  cout << "q - quicksort" << endl;
  cout << "k - kubełkowe" << endl;
  cin >> choice;
  system("clear");
  Start = clock();
  //tab = newTab(X);
  tab = loadData(X);
  End = clock();

  cout << "Czas porządkowania danych: " << ((double)(End - Start))/(CLOCKS_PER_SEC/1000) << " ms" << endl;
  switch (choice)
  {
    case 's':
    {
      SortScalanie(tab, X);
      break;
    }
    case 'q':
    {
      SortQuicksort(tab, X);
      break;
    }
    case 'k':
    {
      SortKubelkowe(tab, X);
      break;
    }
    default:
    {
      break;
    }
  }
	return 0;
}
