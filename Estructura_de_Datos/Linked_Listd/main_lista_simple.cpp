#include <cstdlib>
#include "lista_simple.h"
#include "lista_simple.cpp"

using namespace std;

int main() {

  List Santi;

  Santi.addNode(9);
  Santi.addNode(1);
  Santi.addNode(5);
  Santi.printList();
  Santi.deleteNode(6);
  Santi.deleteNode(5);

  return 0;
}
