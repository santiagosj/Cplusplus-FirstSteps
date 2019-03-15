//crea el vector vacio y agrega los elementos uno por uno
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector vacio 
    vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);

    for (int x : vect)
        cout << x << " ";

    return 0;
}
