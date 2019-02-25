#include <iostream>

using namespace std;

bool funcionA(int, int, bool (*)( int ));
bool funcionB(int);


int main() {
  int x = 135, y = 255; //otra manera de inicializar variables
  if (funcionA(x, y, funcionB)) {
      cout << "El resultado es verdadero--" << '\n';
  }else{
      cout << "El resultado es falso--" << '\n';
  }

}

bool funcionA(int param1, int param2, bool(*verificar)(int)) {
  if (((*verificar)(param1))&&((*verificar)(param2))) {
    return true;
  }
}

bool funcionB(int param) {
  if (param > 100) {
     return true;
  }else{
    return false;
  }
}
