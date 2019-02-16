#include <iostream>

int main(){

  int pinRegistro, pin;

  int tries = 0;

       std::cout << "Registra tu codigo PIN: " << '\n';

       std::cin >> pinRegistro;

       std::cout << "El numero de PIN es: " << pinRegistro << '\n';

       std::cout << "Ingresa tu codigo PIN: " << '\n';

       std::cin >> pin;

       while (pin != pinRegistro && tries <= 3) {

             std::cout << "Ingresa tu codigo PIN: " << '\n';

             std::cin >> pin;

             tries++;
       }

       if (pin == pinRegistro) {

           std::cout << "Bienvenido!" << '\n';

        }
}
