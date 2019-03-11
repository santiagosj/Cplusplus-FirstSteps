//-----------------------------------------------------------------------------
//@file:	TextWriter.cpp
//@author:	Hector Morales Piloni
//@date:	May 29, 2015
//@brief:	Text Writer implementation
//-----------------------------------------------------------------------------
#include "TextWriter.h"

TextWriter::TextWriter(SDL_Renderer *r, unsigned short fontSize)
{
	_mRenderer = r;
	_mFontSize = fontSize;
	_mColor = { 255, 255, 255, 255 }; //white color

	//Initialize TTF SDL engine
	if (TTF_Init() != 0)
	{
		Logger::LogError("TTF_Init error");
		SDL_Quit();
		return;
	}

	//Try to open the font
	_mFont = TTF_OpenFont("assets/font.ttf", _mFontSize);
	if (_mFont == NULL)
	{
		Logger::LogError("Error opening TTF Font");
		SDL_Quit();
		return;
	}
}

TextWriter::~TextWriter()
{
	TTF_CloseFont(_mFont);
	SDL_FreeSurface(_mSurface);
	SDL_DestroyTexture(_mTexture);
}

void TextWriter::SetFontColor(SDL_Color color)
{
	_mColor = color;
}

void TextWriter::Render(const char *msg, SDL_Rect pos)
{
	_mSurface = TTF_RenderText_Blended(_mFont, msg, _mColor);

	if (_mSurface == NULL)
	{
		TTF_CloseFont(_mFont);
		Logger::LogError("Error rendering TTF text");
		return;
	}

	_mTexture = SDL_CreateTextureFromSurface(_mRenderer, _mSurface);
	if (_mTexture == NULL)
	{
		Logger::LogError("Error creating TTF texture");
		return;
	}
	
	SDL_QueryTexture(_mTexture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(_mRenderer, _mTexture, NULL, &pos);
}
