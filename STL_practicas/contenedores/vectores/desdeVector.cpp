//inicializa desde otro vector
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vect1{ 10, 20, 30 };

    vector<int> vect2(vect1.begin(), vect1.end());

    for (int x : vect2)
        cout << x << " ";

    return 0;
}
