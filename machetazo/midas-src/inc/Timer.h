//-----------------------------------------------------------------------------
//@file:	Timer.h
//@author:	Hector Morales Piloni
//@date:	May 31, 2015
//@brief:	Timer header class
//-----------------------------------------------------------------------------
#pragma once
#include <SDL.h>
#include <iostream>

class Timer
{
public:
	Timer(unsigned int time);
	~Timer();

	bool Finished();
	char *GetTimeStr();
	void SetTime(unsigned int time);
	void Start();
	void Update();

private:
	unsigned int _mTimeStart;
	unsigned int _mTimeLeft;
	unsigned int _mTime;
	char _mTimerStr[3];
};

