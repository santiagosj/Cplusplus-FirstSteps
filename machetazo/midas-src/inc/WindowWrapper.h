//-----------------------------------------------------------------------------
//@file:	Level.h
//@author:	Hector Morales Piloni
//@date:	May 26, 2015
//@brief:	Window header file, an SDL window wrapper
//-----------------------------------------------------------------------------
#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Logger.h"

class WindowWrapper
{
public:
	WindowWrapper(unsigned short w, unsigned short h);	
	~WindowWrapper();
	SDL_Renderer* GetRenderer();

private:
	unsigned short _mWidth;
	unsigned short _mHeight;

	SDL_Window *_mWindow;
	SDL_Renderer *_mRenderer;
};

