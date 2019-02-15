#include <iostream>

int main(){

  double peso, altura, bmi;

  std::cout << "Ingresa tu altura en m: " << '\n';

  std::cin >> altura;

  std::cout << "Ingresa tu peso en kg: " << '\n';

  std::cin >> peso;

  bmi = peso / (altura * altura);

  std::cout << "Tu masa corporal es de: " << bmi << '\n';

}
