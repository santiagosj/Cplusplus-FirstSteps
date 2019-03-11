//-----------------------------------------------------------------------------
//@file:	Swap.h
//@author:	Hector Morales Piloni
//@date:	May 27, 2015
//@brief:	Swap header file, represents a swap move, it animates the rocks
//			from their iriginal position to a final position and swap back
//			if an invalid move was done
//-----------------------------------------------------------------------------
#pragma once

#include <SDL.h>
#include <cassert>
#include "Rock.h"

class Swap
{
public:
	static enum Direction {LEFT, RIGHT, UP, DOWN};

	Swap(Rock* A, Rock* B);
	~Swap();

	void SetDirection(enum Direction d);
	void Rollback();
	void Update();
	bool RollingBack();
	bool Done();

private:
	Rock* _mA;
	Rock* _mB;
	SDL_Rect _mDestA;
	SDL_Rect _mDestB;
	bool _mDone;
	bool _mInvalid;
	enum Direction _mDirection;
};

