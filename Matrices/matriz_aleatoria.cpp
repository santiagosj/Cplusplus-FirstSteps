#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

   char matriz[8][8],filas = 8, columnas = 8;
   char gem[5] = {184, 169, 207, 64, 3} ;



   for(int i = 0;i<filas;i++){
     for(int j =0;j < columnas;j++){
        gem[rand()%5];
        matriz[i][j] = gem;
        cout << matriz[i][j] << " ";
     }
     cout<<"\n";
   }

  return 0;
}
