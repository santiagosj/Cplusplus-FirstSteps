//-----------------------------------------------------------------------------
//@file:	Swap.cpp
//@author:	Hector Morales Piloni
//@date:	May 27, 2015
//@brief:	Swap implementation
//-----------------------------------------------------------------------------
#include "Swap.h"

Swap::Swap(Rock* A, Rock* B)
{
	assert(A && B);

	_mA = A;
	_mB = B;
	_mDestA = _mB->GetPos();
	_mDestB = _mA->GetPos();
	_mDone = false;
	_mInvalid = false;
}

Swap::~Swap()
{
	_mA = NULL;
	_mB = NULL;
}

void Swap::SetDirection(enum Direction d)
{
	_mDirection = d;
}

bool Swap::Done()
{
	return _mDone;
}

bool Swap::RollingBack()
{
	return _mInvalid;
}

void Swap::Rollback()
{
	assert(_mA && _mB);

	//basically set everything to swap again...
	Rock* tmp = _mA;
	_mA = _mB;
	_mB = tmp;
	_mDestA = _mB->GetPos();
	_mDestB = _mA->GetPos();
	_mDone = false;
	_mInvalid = true;
}

void Swap::Update()
{
	assert(_mA && _mB);

	if (!_mDone)
	{
		SDL_Rect posA, posB;
		//If A is swaping right, B goes in the opposite direction (i.e. left), etc.
		//All positions in board are divisible by 5, so we're using delta = 5
		switch (_mDirection)
		{
		case Swap::LEFT:			
			posA = { _mA->GetPos().x - 5, _mA->GetPos().y, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			posB = { _mB->GetPos().x + 5, _mB->GetPos().y, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			break;
		case Swap::RIGHT:
			posA = { _mA->GetPos().x + 5, _mA->GetPos().y, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			posB = { _mB->GetPos().x - 5, _mB->GetPos().y, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			break;
		case Swap::UP:
			posA = { _mA->GetPos().x, _mA->GetPos().y - 5, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			posB = { _mB->GetPos().x, _mB->GetPos().y + 5, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			break;
		case Swap::DOWN:
			posA = { _mA->GetPos().x, _mA->GetPos().y + 5, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			posB = { _mB->GetPos().x, _mB->GetPos().y - 5, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			break;
		}

		_mA->SetPos(posA);
		_mB->SetPos(posB);

		//have objects reached their destination?
		if (_mA->GetPos().x == _mDestA.x && _mA->GetPos().y == _mDestA.y)
			_mDone = true;			
	}
}