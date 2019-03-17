#pragma once
#include "Shape.h"

class Rectangulo:public Shape
{
public:
	//constructores
	Rectangulo();

   ~Rectangulo();

   //protoripo
   
   void Draw(int _width, int _height);

private:
	int width;
	int height;
};