#include <iostream>

int x = 5;

const int a = 5;

int main(int argc, char** argv){
//para declarar variables en C++ es necesario aclarar el tipo de dato que esta va a almecenar(tipado fuerte)
int x = x; //4201115 ?¿ // should be undefined
std::cout << "el valor de x es : " << x << '\n';

int b[a];
int c = sizeof(b) / sizeof(int); // c = 5;

std::cout << "el valor de c es: " << c << '\n';
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

//concatenando

int age = 32;
std::cout << "Hola mi nombre es Santiago y mi edad es " << age << '\n';
}
