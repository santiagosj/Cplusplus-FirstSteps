//-----------------------------------------------------------------------------
//@file:	WindowWrapper.cpp
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	SDL Window wrapper implementation
//-----------------------------------------------------------------------------
#include "WindowWrapper.h"

WindowWrapper::WindowWrapper(unsigned short w, unsigned short h)
{
	_mWidth = w;
	_mHeight = h;
	_mWindow = NULL;
	_mRenderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		Logger::LogError("SDL failed to initialize");
		SDL_Quit();
	}

	//create the window
	_mWindow = SDL_CreateWindow("Midas Miner Demo", 100, 100, _mWidth, _mHeight, SDL_WINDOW_SHOWN);
	if (_mWindow == NULL)
	{
		Logger::LogError("Error creating window");
		SDL_Quit();
	}

	_mRenderer = SDL_CreateRenderer(_mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_mRenderer == NULL)
	{
		SDL_DestroyWindow(_mWindow);
		Logger::LogError("SDL_CreateRenderer Error");
		SDL_Quit();
	}
}

WindowWrapper::~WindowWrapper()
{
	SDL_DestroyRenderer(_mRenderer);
	SDL_DestroyWindow(_mWindow);
	SDL_Quit();
}

SDL_Renderer* WindowWrapper::GetRenderer()
{
	return _mRenderer;
}
