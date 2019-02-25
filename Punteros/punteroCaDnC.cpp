#include <iostream>

void sumaDoble(int *);//Prototipo

int main() {

  int X = 15;

  std::cout << "El valor original de X:" << X <<'\n';

  sumaDoble(&X);//pasa la direccion de memoria de X;

  std::cout << "El valor de X luego de llamar a la funcion X = X + (X * 2): " << X <<'\n';

}

void sumaDoble(int *ptrX) {
   //toma el valor de X mediante el operador de indireccion
   //la funcion en si no devuelve nada porque mdifica el valor de X por referencia
  *ptrX = *ptrX + (*ptrX * 2);

}
