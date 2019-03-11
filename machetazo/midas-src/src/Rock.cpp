//-----------------------------------------------------------------------------
//@file:	Rock.cpp
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Rock implementation
//-----------------------------------------------------------------------------
#include "Rock.h"

Rock::Rock(SDL_Renderer *r)
{
	_mRenderer = r;
}

Rock::Rock()
{
	_mRenderer = NULL;
}

Rock::~Rock()
{
}

void Rock::SetColor(unsigned short color)
{
	_mColor = color;
}

unsigned short Rock::GetColor() const
{
	return _mColor;
}

unsigned short Rock::GetCol() const
{
	return _mCol;
}

unsigned short Rock::GetRow() const
{
	return _mRow;
}

void Rock::SetCol(unsigned short col)
{
	_mCol = col;
}

void Rock::SetRow(unsigned short row)
{
	_mRow = row;
}