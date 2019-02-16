#include <iostream>
#include <stdlib.h>
#include <ctime>

int main(){


  srand (time(NULL));

  int coin = rand() % 2;

  if(coin == 0){

    std::cout << "cara" << '\n';

  }else{

    std::cout << "cruz" << '\n';
    
  }
}
