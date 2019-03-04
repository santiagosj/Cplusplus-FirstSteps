/*
Asignacion dinamica de memoria
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h> //invoca new y delete, para asignar y liberar memoria;

using namespace std;

//Prototipos de funcion

void pedirNotas();
void mostrarNotas();
void promedio();

//declaracion de puntero y variables globales

int numCalif, *calificacion;

double promedioNotas;

//============MAIN=============//

int main()
{
	pedirNotas();
	mostrarNotas();
	promedio();

	delete[] calificacion; //liberando espacio

	system("PAUSE");

	return 0;
}

//==================DEFINICION DE FUNCIONES==============================//

void pedirNotas()
{
	cout << "Ingresa el numero de calificaciones: \n";
	cin >> numCalif;

	calificacion = new int[numCalif]; //reserva de memoria (heap), creacion del arreglo dinamico, se le asigna al puntero la primer posicion del arreglo dinamico.

	for (int i = 0; i < numCalif; i++)
	{
		cout << "Ingresa la calificacion: ";
		cin >> calificacion[i];
	}
}

void mostrarNotas()
{

	cout << "\n\nMostrando notas: \n";

	for (int i = 0; i < numCalif; i++)
	{
		cout << calificacion[i] << endl;
	}

}

void promedio()
{
	for (int i = 0; i < numCalif; i++)
	{
		promedioNotas += calificacion[i];
	}

	cout << "El promedio es de: " << promedioNotas / numCalif << endl;
}
