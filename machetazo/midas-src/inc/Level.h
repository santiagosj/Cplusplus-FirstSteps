//-----------------------------------------------------------------------------
//@file:	Level.h
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Level header file
//-----------------------------------------------------------------------------
#pragma once
#include <SDL.h>
#include <cassert>
#include <time.h>
#include <vector>
#include "Background.h"
#include "Rock.h"
#include "RockChain.h"
#include "Swap.h"
#include "TextWriter.h"
#include "Timer.h"
#include "WindowWrapper.h"

using namespace std;

class Level
{
public:
	//Size of the grid by default
	static const unsigned short ROWS = 8;
	static const unsigned short COLS = 8;

	//Handle different game states
	static const enum State {LOADING, IDLE, SWAPPING, ROLLING_BACK, PROCESSING, END_PROCESSING, FINISHED};

	//Scoring system
	static const enum Score { CHAIN3 = 50, CHAIN4 = 100, CHAIN5PLUS = 200 };

	Level(SDL_Renderer *r);
	~Level();
	unsigned short GetState() const;
	void Render() const;
	void LoadLevel(unsigned short levelNumber);
	void SetState(unsigned short state);
	void OnMouseButtonDown(int x, int y);
	void OnMouseButtonUp(int x, int y);	
	void Update();

private:
	unsigned short GetRandomColor(int col, int row) const;
	const char* GetColorFile(unsigned short color) const;
	void GetGridCoords(int x, int y, int &row, int &col) const;
	void SwapRocks(int fromCol, int fromRow, int toCol, int toRow);	
	bool IsValidChain(int col, int row) const;
	void RemoveChains();
	void FindHorizontalChains();
	void FindVerticalChains();
	void FillChainHoles();
	void FillTop();
	void AnimateFallingRocks();
	void AnimateNewRocks();
	void UpdateScore(unsigned int count);

	Background *_mBackground;
	Rock *_mRocks[ROWS][COLS];
	SDL_Renderer *_mRenderer;
	unsigned short _mLevelNumber;
	unsigned short _mState;
	unsigned int _mScore;
	char _mScoreString[10];
	int _mSwapFromCol;
	int _mSwapFromRow;
	int _mSwapToCol;
	int _mSwapToRow;
	bool _mCompleted;
	bool _mSwipe;
	bool _mHasHoles;
	bool _mRefillTop;
	vector<RockChain> _mRockChains;
	vector<Rock*> _mFallingRocks;
	vector<Rock*> _mNewRocks;
	Swap *_mSwap;
	TextWriter *_mTextWriter;
	Timer *_mTimer;
};

