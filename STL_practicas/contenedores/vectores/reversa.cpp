
#include <iostream>
#include <vector>

using namespace std;


int main()
{
  //declaracion del vector
	vector <int> v;
  //declaracion del iterador
	vector <int>::iterator it;
  //agrega 5 valores al final de la lista de menor a mayor
	v.push_back(5);
  //back devuelve una referencia al ultimo elemento del vector
	while (v.back() > 0)

		v.push_back(v.back() - 1);

	for (it = v.begin(); it != v.end(); ++it)

		cout << *it << ' ';

	cout << endl;

	for (int i = 0; i < v.size(); ++i)

		cout << v.at(i) << ' ';

	cout << endl;

	while (!v.empty())
	{
		cout << v.back() << ' ';

		v.pop_back();

	}
	cout << endl;

	return 0;

}
