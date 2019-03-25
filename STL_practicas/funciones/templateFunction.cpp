
#include <iostream>

using namespace std;

//funcion generica para hacer un swap que nos permita ingresar diferentes tipos de dato como parametro.

template <class T>
  inline void swap(T const& a, T const& b) {  /*inline es util para aumentar el tiempo de ejecución de un programa. Con la palabra clave inline, el compilador reemplaza la declaración de llamada de función con el código de función en sí y luego compila el código completo. Por lo tanto, con las funciones en línea, el compilador no tiene que saltar a otra ubicación para ejecutar la función, y luego retroceder cuando el código de la función llamada ya está disponible para el programa que llama..*/
	  T aux;

	  aux = a;

	  a = b;

	  b = aux;

	cout << "haciendo un swap entre " << a << " y " << b << " respectivamente " << endl;

}

int main() {

	int a = 10, b = 20;
	float c = 10.5, d = 20.5;

	cout << "este es el valor de a: " << a << " antes del llamado a la funcion swap." << '\n';
	cout << "este es el valor de b: " << b << " antes del llamado a la funcion swap." << '\n';
	cout << "este es el valor de c: " << c << " antes del llamado a la funcion swap." << '\n';
	cout << "este es el valor de d: " << d << " antes del llamado a la funcion swap." << '\n';

	 swap(a, b);

	 swap(c, d);

	cout << "este es el valor de a: " << a << " despues del llamado a la funcion swap." << '\n';
	cout << "este es el valor de b: " << b << " despues del llamado a la funcion swap." << '\n';
	cout << "este es el valor de c: " << c << " despues del llamado a la funcion swap." << '\n';
	cout << "este es el valor de d: " << d << " despues del llamado a la funcion swap." << '\n';

	return 0;
}
