#pragma once
#include "Shape.h"

class Rectangulo: public Shape
{
public:
	//constructor
	Rectangulo(int, int);

   ~Rectangulo();

   //protoripo
   
   void Draw();

private:
	int width;
	int height;
};