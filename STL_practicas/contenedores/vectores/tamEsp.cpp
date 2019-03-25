
//crea vector de n elementos y asigna todos sus valores a 10
#include <bits/stdc++.h> //guarda aca... en visual #include <vector>
using namespace std;

int main()
{
    int n = 3;

    vector<int> vect(n, 10);

    for (int x : vect)
        cout << x << " ";

    return 0;
    
}
