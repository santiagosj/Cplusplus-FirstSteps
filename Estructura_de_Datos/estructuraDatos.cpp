/*
Tipos primitivos
Nombre común	Nombre C	Longitud	Procesador 64 bits
BYTE	        char	     8 bits	       8 bits
WORD	        short	     16 bits	     16 bits
DWORD	        int	       32 bits	     32 bits
DWORD	        long	     32 bits	     64 bits
DWORD	        float	     32 bits	     32 bits
QWORD 	      double	   64 bits	     64 bits
TWORD	       long double 80 bits	     128 bits
*/
#include <iostream>
#include <string>

using namespace std;

//prototipos de funcion

void esChar();
void esInt();
void esFloat();

//declaracion de variables
char c;
int b;
float a;

int intentos = 0;

string cDato;
string bDato;

                  //MAIN
//===========================================//

int main() {

  std::cout << "Adivina el dato que almacena la variable" << '\n';

  esChar();

  esInt();

  return 0;
}

                //FUNCIONES
//==========================================//

void esChar(){

  std::cout << "Ingresa un numero del 1 al 10: " << '\n';

  std::cin >> c;

  std::cout << "El tamano de la variable c en bits es: "<< sizeof(c) << " y su valor de "<< c << '\n';

  std::cout << "Que tipo de dato es la variable c ? " << '\n';

  std::cin >> cDato;

  while (cDato != "char" && intentos <= 3) {

    std::cout << "ts ts ts volve a intentar..tenes 3 intentos mas sino pasamos a la siguiente" << '\n';

    std::cin >> cDato;

    intentos++;

  }

  if (cDato == "char") {

    std::cout << "Corrrrrecto!" << '\n';

  }
}

//=============================================//

void esInt(){

  std::cout << "Ingresa un numero del 1 al 10: " << '\n';

  std::cin >> b;

  std::cout << "El tamano de la variable b en bits es: "<< sizeof(b) << " y su valor de "<< b << '\n';

  std::cout << "Que tipo de dato es la variable b ? " << '\n';

  std::cin >> bDato;

  while (bDato != "int" && intentos <= 3) {

    std::cout << "ts ts ts volve a intentar..tenes 3 intentos mas sino pasamos a la siguiente" << '\n';

    std::cin >> bDato;

    intentos++;
  }

  if (bDato == "int") {

    std::cout << "Corrrrrecto!" << '\n';

  }

}
