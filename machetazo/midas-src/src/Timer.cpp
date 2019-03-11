//-----------------------------------------------------------------------------
//@file:	Timer.cpp
//@author:	Hector Morales Piloni
//@date:	May 31, 2015
//@brief:	Timer implementation
//-----------------------------------------------------------------------------
#include "Timer.h"

Timer::Timer(unsigned int time)
{
	_mTime = time;
	_mTimeLeft = time;
	_mTimeStart = SDL_GetTicks();
	_mTimerStr[0] = '0';
}

Timer::~Timer()
{
}

bool Timer::Finished()
{
	return (_mTimeLeft == 0);
}

char* Timer::GetTimeStr()
{
	_itoa_s(_mTimeLeft, _mTimerStr, 3, 10);
	return _mTimerStr;
}

void Timer::Start()
{
	_mTimeStart = SDL_GetTicks();
}

void Timer::SetTime(unsigned int time)
{
	_mTime = time;
	_mTimeLeft = time;
	_mTimeStart = SDL_GetTicks();
	_mTimerStr[0] = '0';
}

void Timer::Update()
{
	//update the timer
	_mTimeLeft = _mTime - (SDL_GetTicks() - _mTimeStart) / 1000;

	if (_mTimeLeft < 0) 
		_mTimeLeft = 0;
}
