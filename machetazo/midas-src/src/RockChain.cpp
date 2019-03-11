//-----------------------------------------------------------------------------
//@file:	RockChain.cpp
//@author:	Hector Morales Piloni
//@date:	May 27, 2015
//@brief:	Rockchain implementation
//-----------------------------------------------------------------------------
#include "RockChain.h"

RockChain::RockChain()
{
}

RockChain::~RockChain()
{
}

void RockChain::AddRock(Rock* rock)
{
	_mRocks.push_back(rock);
}

vector<Rock*> RockChain::GetRocks() const
{
	return _mRocks;
}

void RockChain::SetType(enum Type t)
{
	_mType = t;
}