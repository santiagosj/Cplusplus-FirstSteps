#include <iostream>
#include <string>

using namespace std;

int main(){

  double peso, masa, gMercurio, gTierra, gVenus, gMarte, gJupiter, gSaturno, gUrano, gNeptuno;

  gMercurio = 3.7;

  gTierra = 9.8;

  gVenus = 8.87;

  gMarte = 3.7;

  gJupiter = 24.8;

  gSaturno = 10.44;

  gUrano = 8.7;

  gNeptuno = 11.15;

  string planeta;

    std::cout << "Ingresa tu peso en la tierra: " << '\n';

    std::cin >> peso;

    masa = peso / gTierra;

    std::cout << "Ingresa el planeta de destino: " << '\n';

    std::cin >> planeta;

     if (planeta == "Mercurio") {

          peso = masa * gMercurio;

      }else if(planeta == "Venus") {

          peso = masa * gVenus;

      }else if(planeta == "Marte"){

          peso = masa * gMarte;

      }else if(planeta == "Jupiter"){

          peso = masa * gJupiter;

      }else if(planeta == "Saturno"){

          peso = masa * gSaturno;

      }else if(planeta == "Urano"){

          peso = masa * gUrano;

      }else if(planeta == "Neptuno"){

         peso = masa * gNeptuno;

   }

  std::cout << "Tu peso en " << planeta << " es de: " << peso << '\n';

}
