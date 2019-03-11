//-----------------------------------------------------------------------------
//@file:	Level.h
//@author:	Hector Morales Piloni
//@date:	May 29, 2015
//@brief:	Text Writer header file, a class to write TTF fonts
//-----------------------------------------------------------------------------
#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include "Logger.h"

class TextWriter
{
public:
	TextWriter(SDL_Renderer *r, unsigned short fontSize=12);
	~TextWriter();

	void SetFontColor(SDL_Color color);
	void Render(const char *msg, SDL_Rect pos);

private:
	SDL_Renderer *_mRenderer;
	SDL_Surface *_mSurface;
	SDL_Texture *_mTexture;
	TTF_Font *_mFont;
	unsigned short _mFontSize;
	SDL_Color _mColor;
};

