//-----------------------------------------------------------------------------
//@file:	Background.h
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Background header file
//-----------------------------------------------------------------------------
#pragma once
#include "Texture.h"

class Background : public Texture
{
public:
	//Size of background textures
	static const int WIDTH = 800;
	static const int HEIGHT = 600;

	//This is the position where rocks can be placed,
	//could be set according to game level, for demo
	//purposes let's hardcode it here
	static const int OFFSET_X = 350;	
	static const int OFFSET_Y = 100;

	Background(SDL_Renderer *r);
	Background();
	~Background();
};

