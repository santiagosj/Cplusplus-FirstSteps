#include <iostream>

int main(){
//para declarar variables en C++ es necesario aclarar el tipo de dato que esta va a almecenar(tipado fuerte)

//declaro una variable que almacenará un numero entero
int year;

//le asigno un valor a dicha variable(inicialización)
year = 2019;

//se puede hacer ambos pasos simultaneamente
int score = 0;

//operadores aritmeticos

score = 4 + 2;
score = 4 - 2;
score = 4 * 2;
score = 4 / 2;
score = 5 % 2;

std::cout << year << '\n';
std::cout << score << '\n';

}
