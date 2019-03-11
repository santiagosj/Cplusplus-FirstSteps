//-----------------------------------------------------------------------------
//@file:	Level.h
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Texture header file, represents an SDL texture object
//-----------------------------------------------------------------------------
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Logger.h"

class Texture
{
public:
	Texture();
	~Texture();

	void Load(const char* file);
	void SetClip(SDL_Rect r);
	void SetPos(SDL_Rect r);
	SDL_Rect GetPos() const;
	void SetRenderer(SDL_Renderer *r);
	void Render();

protected:
	SDL_Renderer *_mRenderer;
	SDL_Texture *_mTexture;
	SDL_Rect _mClip;
	SDL_Rect _mPos;
};

