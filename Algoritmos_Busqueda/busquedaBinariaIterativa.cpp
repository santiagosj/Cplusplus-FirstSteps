#include <algorithm>
#include <iostream>

template <class T> int busquedabinaria(const T array[], int largo, T valor){

    int bajo = 0;

    int alto = largo - 1;

    while (bajo <= alto) {

      int medio = (bajo + alto) / 2;

      if (array[medio] > valor) {

        alto = medio - 1;

      } else if(array[medio] < valor) {

        bajo = medio + 1;

      } else {

        return medio;

      }

    }

    return -1;
  }

  int main(){

    int array[] = {1, 2, 3, 4, 6, 7, 8};

    int valor;

    std::cout << "Ingrese el valor a buscar: " << '\n';

    std::cin >> valor;

    int posicion = busquedabinaria(array, sizeof(array), valor);

    if (posicion == -1) {
      std::cout << "El numero " << valor << " no fue encontrado." << '\n';
    }else{
      std::cout << "El numero " << valor << " se encuentra en la posicion " << posicion << '\n';
    }

    return 0;
  }
