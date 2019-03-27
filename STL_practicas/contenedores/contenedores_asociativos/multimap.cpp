#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{

	multimap<string, float> estudiante;

	multimap<string, float>::iterator it;

	estudiante.insert(pair<string, float>("Juan", 3.0f));
	estudiante.insert(pair<string, float>("Lucas", 1.5f));
	estudiante.insert(pair<string, float>("Belen", 4.0f));
	estudiante.insert(pair<string, float>("Martin", 5.6f));
	estudiante.insert(pair<string, float>("Rocio", 4.5f));

	for (it = estudiante.begin(); it != estudiante.end(); ++it)
    //cout << it->first << endl;
		cout << it->second << endl;


	return 0;
}
