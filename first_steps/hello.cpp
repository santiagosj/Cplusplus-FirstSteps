#include <iostream>

using namespace std;

int x = 5;

int y;

int main(){

  std::cout << sizeof(int) << endl;

  std::cout << "Hola mundo!" << '\n';

  y = sizeof(x) / sizeof(int);

  std::cout << y << '\n';
  
  return 0;
}
