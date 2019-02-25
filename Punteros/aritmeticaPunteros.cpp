#include <iostream>

using namespace std;

int main()
{

  int X[6]={1, 2, 3, 4, 5, 6}, A;

  int *ptrX;//declaro puntero;

  ptrX = X;//inicializo el valor del puntero

  A = *(X + 3);//A toma el valor del elemento 3 del vector

  cout << endl << *ptrX;

  ptrX += 2;

  cout << endl << *ptrX;

  ptrX -=2;

  cout << endl << *ptrX;

  ptrX++;

  cout << endl << *ptrX << endl;

  cout << "Variable A: " << A << endl;

  A += 2;

  cout << endl << A;

  A -= 2;

  cout << endl << A;

  A++;

  cout << endl << A;
}
