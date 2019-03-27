#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{

	map<string, float> estudiante;

	map<string, float>::iterator it;

	estudiante["Juan"] = 4.0f;
	estudiante["Lucas"] = 1.0f;
	estudiante["Belen"] = 3.0f;
	estudiante["Martin"] = 2.5f;
	estudiante["Rocio"] = 4.5f;
  //imprime los estudiantes en orden alfabetico
	for (it = estudiante.begin(); it != estudiante.end(); ++it)
		cout << it->first << endl;
    //cout << it->second << endl;
	return 0;
}
