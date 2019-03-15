#ifndef LIST_H //condicionales de cabezara para la definicion de LIST_H
#define LIST_H

class List{
private:

typedef struct node{
       int data;
       node* next;
  } *nodePtr;

  nodePtr head;
  nodePtr curr;
  nodePtr temp;

public:
   //prototipos
   List();//constructor
   void addNode(int addData);
   void deleteNode(int delData);
   void printList();
};

#endif
