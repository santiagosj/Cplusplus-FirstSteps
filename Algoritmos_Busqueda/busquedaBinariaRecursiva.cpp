#include <algorithm>
#include <iostream>

template <class T> int busquedabinaria(const T array[], int bajo, int alto, T value){

   if (alto < bajo) {
       return -1;
    }

   auto medio = (alto + bajo) / 2;

   if (value < array[medio]) {
       return busquedabinaria(array, bajo, medio - 1, value);
   }else if(value > array[medio]){
       return busquedabinaria(array, medio + 1, alto, value);
   }

       return medio;
}

int main(){

   int array[] = {2, 3, 5, 6, 8};

   int value;

   std::cout << "Ingrese el numero a buscar: " << '\n';

   std::cin >> value;

   int posicion = busquedabinaria(array, 0, sizeof(array)/sizeof(int), value);


       if (posicion == -1){
         std::cout << "El numero " << value << " no fue encontrado." <<'\n';
       } else {
         std::cout << "El numero " << value << " se encuentra en la posicion " << posicion << '\n';
       }

       return 0;
}
