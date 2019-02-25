/*
 operador de dirección (&)
 operador de indirección (*)
 sintaxis
*/

#include <iostream>

//declaracion de variables y punteros

int X = 7; //variable X
int *ptrX; // puntero
ptrX = &X; //asignamos la direccion de memoria de X al puntero

//punteros en arrays. Los vectores son punteros constantes.Un Vector sin subindice es un puntero al primer elemento del vector.
int arr[6] = {1, 2, 3, 4, 5, 6}
int *ptrArr;
ptrArr = arr; //ptrArr recibe la direccion del primer elemento de arr

//tambien podria escribirse:
int A[10];
int *ptrA;
ptrA = &A[0];

//se pueden utilizar distintos elementos del vector teniendo en cuanta la sintaxis;
int B[10], C, *ptrB;
ptrB = B;
C = *(ptrB + 7);
//C toma el valor del elemento 7 del vector B;El operador de indireccion queda fuera del parentesis porque tienen una prioridad superior a la del operador +. De no existir el parentesis se le sumaria 7 al elemento B[0].
//Ya que los Vectores son punteros constantes, el nombre del vector puede ser tratado como un puntero:
//C = *(B + 7);

int main() {

  return 0;
}
