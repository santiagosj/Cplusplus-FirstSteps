//-----------------------------------------------------------------------------
//@file:	Level.h
//@author:	Hector Morales Piloni
//@date:	May 27, 2015
//@brief:	Rockchain header file, represents a chain that can be removed
//-----------------------------------------------------------------------------
#pragma once

#include <SDL.h>
#include <vector>
#include "Rock.h"

using namespace std;

class RockChain
{
public:
	static const enum Type {HORIZONTAL, VERTICAL};

	RockChain();
	~RockChain();
	void AddRock(Rock* rock);
	vector<Rock*> GetRocks() const;
	void SetType(enum Type t);

private:
	vector<Rock*> _mRocks;
	unsigned short _mType;
};

