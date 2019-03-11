//-----------------------------------------------------------------------------
//@file:	Bacgkround.cpp
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Background implementation
//-----------------------------------------------------------------------------
#include "Background.h"

Background::Background(SDL_Renderer *r)
{
	_mRenderer = r;
}

Background::Background()
{
	_mRenderer = NULL;
}

Background::~Background()
{
}