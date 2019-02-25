#include <iostream>

using namespace std;

int main() {
  int foo, bar;
  int * const ptrFoo = &foo; // puntero constante a un entero en la direccion de memoria de foo

  *ptrFoo = 30;

  ptrFoo = &bar;//Esta ultima asignacion debe devolver un error debido a la naturaleza constante de ptrFoo y no se puede alterar la direccion de memoria a la que apunta y directamente no compila.
}
