#include <iostream>
#include <cstdlib>

#include "lista_simple.h"

using namespace std;

List::List() {
  head = NULL;
  curr = NULL;
  temp = NULL;
}

void List::addNode(int addData){
  nodePtr n = new node; //1-crear un nuevo nodo
  //agregar al final de la lista
  n->next = NULL; //2-Asignar como siguiente del nodo creado al ultimo de la lista
  n->data = addData;//3-Asigno data al nodo creado

  if (head != NULL) { //comprobar que la lista no está vacía
      curr = head;

      while (curr->next != NULL) { //mientras el nodo actual no sea el ultimo de la lista
        curr = curr->next;//recorrer la lista
      }
      curr->next = n;// asignar al siguiente el nuevo nodo
  }else{
    head = n;
  }
}

void List::deleteNode(int delData){
  nodePtr delPtr = NULL;
  temp = head;
  curr = head;
   //recorremos la lista
  while (curr != NULL && curr->data != delData) {
     temp = curr;
     curr = curr->next;
  }
  if (curr == NULL) {
      cout << delData <<" no esta en la lista" << '\n';
      delete delPtr;
  }
  else{
    delPtr = curr;
    curr = curr->next;
    temp->next = curr;
    delete delPtr;
    cout << "El valor " << delData << " fue eliminado"<<'\n';
  }
}

void List::printList(){
  curr = head;
  while (curr != NULL) {
    cout << curr->data << '\n';
    curr = curr->next;
  }
}
