//-----------------------------------------------------------------------------
//@file:	DropRock.h
//@author:	Hector Morales Piloni
//@date:	May 31, 2015
//@brief:	DropRock class can be used instead of AnimateXXX() methods in 
//			Level class to push rocks down while playing. It needs a bit of
//			debugging before it can be used.
//-----------------------------------------------------------------------------
#pragma once

#include <SDL.h>
#include <cassert>
#include <list>
#include "Background.h"
#include "Rock.h"

using namespace std;

class DropRock
{
public:
	DropRock(list<Rock*> rocks);
	~DropRock();

	void Update();
	bool Done();

private:
	bool _mDone;
	SDL_Rect _mDest;
	list<Rock*> _mRocks;
};

