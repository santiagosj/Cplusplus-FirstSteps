#include <iostream>

int main() {

  int number;

  std::cout << "Ingresa un numero del 1 al 9: " << '\n';
  
  std::cin >> number;

  switch(number) {

    case 1 :
      std::cout << "Kenny\n";
      break;
    case 2 :
      std::cout << "Eric\n";
      break;
    case 3 :
      std::cout << "Stan\n";
      break;
    case 4 :
      std::cout << "Kyle\n";
      break;
    case 5 :
      std::cout << "Ice\n";
      break;
    case 6 :
      std::cout << "Bothers\n";
      break;
     case 7 :
      std::cout << "Twike\n";
      break;
     case 8 :
      std::cout << "Randy\n";
      break;
     case 9 :
      std::cout << "Gerald\n";
      break;
    default :
      std::cout << "Unknown\n";
      break;

  }


}
