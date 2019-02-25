//Hola tito con puntero:
/*
El proceso funciona tratando al string como un vector de caracteres y recorriendolo por referencia utilizando el puntero
*/

#include <iostream>

using namespace std;

void imprimirChar(const char *);//prototipo

int main() {
  char frase[] = "Hola tito";
  imprimirChar(frase);
}

void imprimirChar(const char *ptrStr){
   for (; *ptrStr != '\0'; *ptrStr++) //sin inicializacion;
      cout << *ptrStr;
}
