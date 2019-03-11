//-----------------------------------------------------------------------------
//@file:	Rock.h
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Rock header file
//-----------------------------------------------------------------------------
#pragma once
#include "Texture.h"

class Rock : public Texture
{
public:
	//This is the size in pixels of the rock textures
	static const int ROCK_WIDTH = 35;
	static const int ROCK_HEIGHT = 35;

	//Here we define a 10px separation between rocks
	static const int PIXEL_SEPARATION = 10;

	static enum RockColor { RED, YELLOW, GREEN, BLUE, PURPLE };

	Rock(SDL_Renderer *r);
	Rock();
	~Rock();

	void SetColor(unsigned short color);
	void SetRow(unsigned short row);
	void SetCol(unsigned short col);
	unsigned short GetColor() const;
	unsigned short GetRow() const;
	unsigned short GetCol() const;

private:
	unsigned short _mColor;
	unsigned short _mRow;
	unsigned short _mCol;
};

