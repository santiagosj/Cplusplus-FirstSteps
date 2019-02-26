/*
<tipo> [clase::] <nombre> ( [Parámetros] ).
{
    cuerpo;
}
*/
#include <iostream>

//prototipo
double funcion_1(double x);

int main() {
  int y = 2;
  int cuadrado;
  //implementacion
  cuadrado = funcion_1(y);
  std::cout << cuadrado << '\n';
}

//defincion
double funcion_1(double x){
  return x * x;
}
