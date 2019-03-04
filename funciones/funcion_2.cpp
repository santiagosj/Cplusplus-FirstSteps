//copiando un string;

#include <iostream>

using namespace std;

void copiarChar(const char *, char *);//prototipo

int main() {
  char origen[10];
  char destino[10];

  std::cout << "Origen: " << '\n';
  std::cin >> origen;
  std::cout << "Copia: " << '\n';
  
  copiarChar(origen, destino);
}

void copiarChar(const char *origen, char *destino){

   for (int i = 0; *origen != '\0'; *origen++) {
         destino[i] = origen[i];
         cout << destino[i];
   }
}
