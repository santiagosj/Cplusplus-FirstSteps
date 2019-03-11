//-----------------------------------------------------------------------------
//@file:	Rock.h
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Rock header file
//-----------------------------------------------------------------------------
#pragma once
#include "Texture.h"

//hereda de texturas para hacer el render de las gemas...

class Rock : public Texture
{
public:
	//This is the size in pixels of the rock textures
	static const int ROCK_WIDTH = 35;
	static const int ROCK_HEIGHT = 35;

	//Here we define a 10px separation between rocks
	static const int PIXEL_SEPARATION = 10;

	//array de colores para asignar a las texturas

	static enum RockColor { RED, YELLOW, GREEN, BLUE, PURPLE };
  //constructors
	//pasa por parametro el Render con puntero a la imagen
	Rock(SDL_Renderer *r);
	Rock();
	~Rock();
  //funciones
  //asigna color
  void SetColor(unsigned short color);

	//asigna fila
	void SetRow(unsigned short row);

	//asigna columna
	void SetCol(unsigned short col);

	//obtiene valor color
	unsigned short GetColor() const;

	//obtiene valor fila
	unsigned short GetRow() const;

	//obtiene valor columna
	unsigned short GetCol() const;

private:
	unsigned short _mColor;
	unsigned short _mRow;
	unsigned short _mCol;
};
