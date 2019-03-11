//-----------------------------------------------------------------------------
//@file:	Logger.h
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Logger header file, basic SDL error logger
//-----------------------------------------------------------------------------
#pragma once
#include <SDL.h>
#include <iostream>

class Logger
{
public:
	Logger();
	~Logger();

	static void LogError(const char* msg)
	{
		std::cout << msg << ": " << SDL_GetError() << std::endl;
	}
};

