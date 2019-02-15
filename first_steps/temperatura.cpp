#include <iostream>

int main(){

  double tempf;

  double tempc;

  std::cout << "Ingresa la temperatura en Fahrenheints: " << '\n';

  std::cin >> tempf;

  tempc = (tempf - 32) / 1.8;

  std::cout << "La temperatura en Celsius es de :" << tempc << " grados" << '\n';
}
