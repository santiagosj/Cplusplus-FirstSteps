//-----------------------------------------------------------------------------
//@file:	DropRock.cpp
//@author:	Hector Morales Piloni
//@date:	May 31, 2015
//@brief:	DropRock implementation
//-----------------------------------------------------------------------------
#include "DropRock.h"

DropRock::DropRock(list<Rock*> rocks)
{
	_mRocks = rocks;
	_mDone = false;
	_mDest = { -1, -1, 0, 0 };
}

DropRock::~DropRock()
{
}

bool DropRock::Done()
{
	return _mDone;
}

void DropRock::Update()
{
	if (!_mDone)
	{
		Rock *r = _mRocks.front();

		//check if destination is already set
		if (_mDest.y < 0)
		{
			_mDest.x = r->GetPos().x;
			_mDest.y = Background::OFFSET_Y + (r->GetRow() * Rock::ROCK_HEIGHT) + (Rock::PIXEL_SEPARATION * r->GetRow());
		}

		SDL_Rect newPos = { _mDest.x, r->GetPos().y + 5, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
		r->SetPos(newPos);

		if (r->GetPos().y >= _mDest.y) {
			_mDest.y = -1;
			_mRocks.pop_front();
		}

		if (_mRocks.empty()) {
			_mDone = true;
		}
	}
}
