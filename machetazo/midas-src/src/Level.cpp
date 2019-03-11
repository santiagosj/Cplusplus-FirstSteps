//-----------------------------------------------------------------------------
//@file:	Level.cpp
//@author:	Hector Morales Piloni
//@date:	May 25, 2015
//@brief:	Level implementation file
//-----------------------------------------------------------------------------
#include "Level.h"

Level::Level(SDL_Renderer *r)
{
	_mLevelNumber = 0;
	_mScore = 0;
	_mScoreString[0] = '0';
	 _mState = 0;
	_mSwapFromCol = -1;
	_mSwapFromRow = -1;
	_mSwapToCol = -1;
	_mSwapToRow = -1;
	_mCompleted = false;
	_mSwipe = false;
	_mHasHoles = false;
	_mRefillTop = false;
	_mSwap = NULL;
	_mRenderer = r;	
	_mBackground = new Background(_mRenderer);
	_mTextWriter = new TextWriter(_mRenderer, 40);
	_mTextWriter->SetFontColor({ 255, 250, 0, 255 });
	_mTimer = new Timer(0);

	for (int r = 0; r < Level::ROWS; r++) {
		for (int c = 0; c < Level::COLS; c++) {
			_mRocks[r][c] = NULL;
		}
	}
}

Level::~Level()
{
	_mRenderer = NULL;

	if (_mBackground)
		delete _mBackground;
	_mBackground = NULL;

	for (int r = 0; r < Level::ROWS; r++) {
		for (int c = 0; c < Level::COLS; c++) {
			delete _mRocks[r][c];
		}
	}
}

unsigned short Level::GetRandomColor(int col, int row) const
{
	unsigned short color;

	//Try to get a color that does not produce a chain (3 or more of the same color)
	//useful when loading, so we don't present any pre-loaded chains
	do {
		color = Rock::RED + (rand() % 5);
	} while (
		(col >= 2 &&
		_mRocks[row][col - 1]->GetColor() == color &&
		_mRocks[row][col - 2]->GetColor() == color)
		||
		(row >= 2 &&
		_mRocks[row - 1][col]->GetColor() == color &&
		_mRocks[row - 2][col]->GetColor() == color));

	return color;
}

const char* Level::GetColorFile(unsigned short color) const
{
	//Given a color ID, match with a texture name
	const char *colorFile = "";

	switch (color)
	{
	case Rock::RED:
		colorFile = "assets/Red.png";
		break;
	case Rock::BLUE:
		colorFile = "assets/Blue.png";
		break;
	case Rock::GREEN:
		colorFile = "assets/Green.png";
		break;
	case Rock::PURPLE:
		colorFile = "assets/Purple.png";
		break;
	case Rock::YELLOW:
		colorFile = "assets/Yellow.png";
		break;
	default:
		colorFile = "assets/Red.png";
		break;
	}

	return colorFile;
}

void Level::LoadLevel(unsigned short levelNumber)
{
	SDL_Rect clip = { 0, 0, 0, 0 };
	SDL_Rect pos = { 0, 0, 0, 0 };
	_mLevelNumber = levelNumber;
	_mTimer->SetTime(60); //60 seconds to beat, this could be set when loading the level from file

	/*
	We can load the level from a file here (JSON, CSV, etc) e.g.:
	8,8				<-- Rows/Cols
	0,1,1,1,1,1,1,0	<-- Level layout
	1,1,1,1,1,1,1,1
	1,1,0,0,0,0,1,1
	1,1,0,0,0,0,1,1
	1,1,0,0,0,0,1,1
	1,1,0,0,0,0,1,1
	1,1,1,1,1,1,1,1
	0,1,1,1,1,1,1,0	
	Or something similar, but for demo purposes, let's hardcore level 1 instead
	And we're assuming rocks grid will be 8x8 always
	*/

	unsigned short layout[8][8] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};

	//Load background, it could change according to level number
	pos.x = pos.y = 0;
	pos.w = Background::WIDTH;
	pos.h = Background::HEIGHT;
	_mBackground->SetPos(pos);
	_mBackground->Load("assets/background.jpg");

	//Load rocks, randomize their colors
	pos.w = Rock::ROCK_WIDTH;
	pos.h = Rock::ROCK_HEIGHT;

	srand((unsigned int)time(NULL));
	for (int row = 0; row <Level::ROWS; row++)
	{
		for (int col = 0; col < Level::COLS; col++)
		{
			//Ensure that at loading time we don't have combos
			unsigned short color = GetRandomColor(col, row);
			const char *colorFile = GetColorFile(color);

			//Position changes dinamically based on x/y position, we add the BG offset and pixel separation
			pos.x = Background::OFFSET_X + (col * Rock::ROCK_WIDTH) + (Rock::PIXEL_SEPARATION * col);
			pos.y = Background::OFFSET_Y + (row * Rock::ROCK_HEIGHT) + (Rock::PIXEL_SEPARATION * row);

			if (layout[row][col] == 1)
			{	
				_mRocks[row][col] = new Rock();
				_mRocks[row][col]->SetColor(color);
				_mRocks[row][col]->SetRenderer(_mRenderer);
				_mRocks[row][col]->SetPos(pos);
				_mRocks[row][col]->SetRow(row);
				_mRocks[row][col]->SetCol(col);
				_mRocks[row][col]->Load(colorFile);
			}
		}
	}
}

void Level::Render() const
{
	SDL_RenderClear(_mRenderer);
		
	//Render background and each visible rock
	_mBackground->Render();

	for (int row = 0; row < Level::ROWS; row++) {
		for (int col = 0; col < Level::COLS; col++) {
			if (_mRocks[row][col] != NULL)
				_mRocks[row][col]->Render();
		}
	}

	_mTextWriter->Render("Score: ", { 10, 100, 0, 0 });
	_mTextWriter->Render(_mScoreString, { 120, 100, 0, 0 });
	_mTextWriter->Render("Time left: ", { 10, 150, 0, 0 });
	_mTextWriter->Render(_mTimer->GetTimeStr(), { 180, 150, 0, 0 });

	if (_mState == Level::FINISHED) {
		_mTextWriter->Render("GAME OVER", { 400, 50, 0, 0 });
	}

	SDL_RenderPresent(_mRenderer);
}

unsigned short Level::GetState() const
{
	return _mState;
}

void Level::SetState(unsigned short state)
{
	_mState = state;
}

void Level::Update()
{
	switch (_mState) {
	case Level::LOADING:
		//_mTimer->Start();
		break;

	case Level::IDLE:
		_mTimer->Update();
		if (_mTimer->Finished())
			_mState = Level::FINISHED;

		if (!_mRockChains.empty() || !_mFallingRocks.empty() || !_mNewRocks.empty()) {
			_mState = Level::PROCESSING;
		}
		break;

	case Level::SWAPPING:
		assert(_mSwap);

		_mTimer->Update();
		_mSwap->Update();
		if (_mSwap->Done())
		{
			//position animation finished, now swap the actual objects
			SwapRocks(_mSwapFromCol, _mSwapFromRow, _mSwapToCol, _mSwapToRow);

			//Check whether is a valid move (i.e. forms a chain)
			if (IsValidChain(_mSwapFromCol, _mSwapFromRow) || IsValidChain(_mSwapToCol, _mSwapToRow))
			{
				delete _mSwap;
				_mSwapFromCol = _mSwapToCol = -1;
				_mSwapFromRow = _mSwapToRow = -1;

				FindHorizontalChains();
				FindVerticalChains();

				_mState = Level::PROCESSING;
			}
			else
			{
				_mSwap->Rollback();
				_mState = Level::ROLLING_BACK;
			}
		}
		break;

	case Level::ROLLING_BACK:		
		assert(_mSwap);

		_mTimer->Update();
		_mSwap->Update();
		if (_mSwap->Done())
		{
			//position animation finished, now swap the actual objects
			SwapRocks(_mSwapFromCol, _mSwapFromRow, _mSwapToCol, _mSwapToRow);

			delete _mSwap;
			_mSwapFromCol = _mSwapToCol = -1;
			_mSwapFromRow = _mSwapToRow = -1;

			_mState = Level::IDLE;
		}
		break;

	case Level::PROCESSING:
		_mTimer->Update();
		RemoveChains();
		FillChainHoles();
		AnimateFallingRocks();
		FillTop();
		AnimateNewRocks();

		if (_mRockChains.empty() && _mFallingRocks.empty() && _mNewRocks.empty()) {
			_mState = END_PROCESSING;
		}
		break;

	case Level::END_PROCESSING:
		_mTimer->Update();
		//Check if moving rocs produced more chains
		FindHorizontalChains();
		FindVerticalChains();

		//go back to IDLE... 
		//if any chains were created, this state will take care of them
		_mState = Level::IDLE;
		break;

	case Level::FINISHED:
		//TODO display final score, load nother texture etc
		_mTextWriter->SetFontColor({ 200, 0, 0, 255 });
		break;
	}
}

void Level::GetGridCoords(int x, int y, int &row, int &col) const
{
	assert(x >= 0 && y >= 0);

	//convert window position into ROW/COL coordinates in our grid
	row = (y - Background::OFFSET_Y) / (Rock::ROCK_HEIGHT + Rock::PIXEL_SEPARATION);
	col = (x - Background::OFFSET_X) / (Rock::ROCK_WIDTH + Rock::PIXEL_SEPARATION);
}

void Level::OnMouseButtonDown(int x, int y)
{
	//On button DOWN we only track swapTo positions
	//we also start a swipe event, later on buttonUp, 
	//we check whether it was a swipe or just a click
	if (_mSwapFromCol >= 0)
		return;

	_mSwipe = true;

	int row, col;
	GetGridCoords(x, y, row, col);	
	if (row >= 0 && row < Level::ROWS && col >= 0 && col < Level::COLS)
	{	
		_mSwapFromCol = col;
		_mSwapFromRow = row;
	}
}

void Level::OnMouseButtonUp(int x, int y)
{
	//On button UP we track swapTo position, 
	//this allows to swap rocks either by clicking or swiping	
	GetGridCoords(x, y, _mSwapToRow, _mSwapToCol);
	
	if (_mSwapToRow >= 0 && _mSwapToRow < Level::ROWS && _mSwapToCol >= 0 && _mSwapToCol < Level::COLS)
	{
		if (_mRocks[_mSwapToRow][_mSwapToCol] == NULL || _mRocks[_mSwapFromRow][_mSwapFromCol] == NULL)
		{
			//empty cell, invalid move
			_mSwapFromCol = _mSwapFromRow = -1;
			_mSwapToCol = _mSwapToRow = -1;
			_mSwipe = false;
			return;
		}

		//if this is not set, it means previous click was at some invalid position
		if (_mSwapFromCol >= 0)
		{
			//check that we're not clicking on the same rock as previously clicked
			if (_mSwapFromCol == _mSwapToCol && _mSwapFromRow == _mSwapToRow)
			{
				//Since we released the mouse in the same position, we're NOT swiping
				_mSwipe = false;
				return;
			}

			//If we're clicking, check that final grid position is valid (+/- 1)
			//If we're swiping, use deltas, it doesn't matter on what position we release the mouse
			//this improves user experience on a touch screen
			int deltaX = _mSwapToCol - _mSwapFromCol; //(+) right, (-) left
			int deltaY = _mSwapToRow - _mSwapFromRow; //(+) up, (-) down
			int direction = 0;

			if (deltaX != 0 && deltaY != 0)
			{
				//invalid move... 
				_mSwapFromCol = _mSwapFromRow = -1;
				_mSwapToCol = _mSwapToRow = -1;
				_mSwipe = false;
				return;
			}

			if (deltaX > 0){
				_mSwapToCol = _mSwapFromCol + 1;
				direction = Swap::RIGHT;
			}
			if (deltaX < 0){
				_mSwapToCol = _mSwapFromCol - 1;
				direction = Swap::LEFT;
			}
			if (deltaY > 0){
				_mSwapToRow = _mSwapFromRow + 1;
				direction = Swap::DOWN;
			}
			if (deltaY < 0){
				_mSwapToRow = _mSwapFromRow - 1;
				direction = Swap::UP;
			}

			//Try to swap the rocks
			_mState = Level::SWAPPING;
			_mSwap = new Swap(_mRocks[_mSwapFromRow][_mSwapFromCol], _mRocks[_mSwapToRow][_mSwapToCol]);
			_mSwap->SetDirection((Swap::Direction)direction);
			_mSwipe = false;
		}
	}
	else 
	{
		//invalid position, reset swap flags
		_mSwapFromCol = _mSwapFromRow = -1;
		_mSwapToCol = _mSwapToRow = -1;
		_mSwipe = false;
	}
}

bool Level::IsValidChain(int col, int row) const
{	
	assert(col >= 0 && row >= 0);

	unsigned short color = _mRocks[row][col]->GetColor();
	int hLen = 1;
	int vLen = 1;

	//check for horizontal chains
	//while rock is not null and its color is equal to matching color, increment hLen or vLen
	for (int i = col - 1; i >= 0 && _mRocks[row][i] && _mRocks[row][i]->GetColor() == color; i--, hLen++);
	for (int i = col + 1; i < Level::COLS && _mRocks[row][i] && _mRocks[row][i]->GetColor() == color; i++, hLen++);
	if (hLen >= 3) return true;

	//check for vertical chains
	for (int i = row - 1; i >= 0 && _mRocks[i][col] && _mRocks[i][col] && _mRocks[i][col]->GetColor() == color; i--, vLen++);
	for (int i = row + 1; i < Level::ROWS && _mRocks[i][col] && _mRocks[i][col]->GetColor() == color; i++, vLen++);
	return (vLen >= 3);
}

void Level::SwapRocks(int fromX, int fromY, int toX, int toY)
{
	assert(fromX >= 0 && fromY >= 0);
	assert(toX >= 0 && toY >= 0);

	//Change rock's row/col pairs
	_mRocks[fromY][fromX]->SetCol(toX);
	_mRocks[fromY][fromX]->SetRow(toY);
	_mRocks[toY][toX]->SetCol(fromX);
	_mRocks[toY][toX]->SetRow(fromY);

	//Now, update our grid, since we have moved rock objects around
	Rock* rockFrom = _mRocks[fromY][fromX];
	Rock* rockTo = _mRocks[toY][toX];
	_mRocks[fromY][fromX] = rockTo;
	_mRocks[toY][toX] = rockFrom;
}

void Level::RemoveChains()
{
	for (size_t chain = 0; chain < _mRockChains.size(); chain++)
	{
		_mHasHoles = true;
		vector<Rock*> rocksArr = _mRockChains[chain].GetRocks();

		for (size_t i = 0; i < rocksArr.size(); i++) {
			_mRocks[rocksArr[i]->GetRow()][rocksArr[i]->GetCol()] = NULL;
		}
	}

	if (!_mRockChains.empty())
		_mRockChains.clear();
}

void Level::FillChainHoles()
{
	if (!_mHasHoles)
		return; 

	//since we're filling holes, we're going to have to push new rocks on top
	_mRefillTop = true;

	for (int col = 0; col < Level::COLS; col++)
	{
		//scan bottom-up for holes
		for (int row = Level::ROWS - 1; row >= 0; row--)
		{
			if (_mRocks[row][col] == NULL)
			{
				//found a hole, lookup the next rock upwards
				for (int lookup = row - 1; lookup >= 0; lookup--)
				{
					Rock *rock = _mRocks[lookup][col];
					if (rock != NULL)
					{
						//push down the rock
						rock->SetRow(row);
						_mRocks[lookup][col] = NULL;
						_mRocks[row][col] = rock;
						//add to an array that will be used for animation later
						_mFallingRocks.push_back(rock);
						break;
					}
				}
			}
		}
	}

	_mHasHoles = false;
}

void Level::AnimateFallingRocks()
{
	for (size_t i = 0; i < _mFallingRocks.size(); i++)
	{		
		//get each rock in the array and calclate its new position
		//update their positions by 5 pixels, when a rock reaches
		//its destination, delete it from the array
		Rock *rock = _mFallingRocks[i];
		int finalY = Background::OFFSET_Y + (rock->GetRow() * Rock::ROCK_HEIGHT) + (Rock::PIXEL_SEPARATION * rock->GetRow());

		SDL_Rect pos = { rock->GetPos().x, rock->GetPos().y + 5, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
		rock->SetPos(pos);

		if (rock->GetPos().y == finalY)
			_mFallingRocks.erase(_mFallingRocks.begin() + i);
	}
}

void Level::FillTop()
{
	if (!_mRefillTop)
		return; 

	for (int col = 0; col < Level::COLS; col++)
	{
		for (int row = 0; row < Level::ROWS && _mRocks[row][col] == NULL; row++)
		{
			int x = Background::OFFSET_X + (col * Rock::ROCK_HEIGHT) + (Rock::PIXEL_SEPARATION * col);
			SDL_Rect pos = {x, 0, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
			
			unsigned short color = GetRandomColor(col, row);
			const char *colorFile = GetColorFile(color);

			Rock* rock = new Rock();
			rock->SetColor(color);
			rock->SetCol(col);
			rock->SetRow(row);
			rock->SetPos(pos);
			rock->SetRenderer(_mRenderer);
			rock->Load(colorFile);
			_mRocks[row][col] = rock;
			_mNewRocks.push_back(rock);
		}
	}

	_mRefillTop = false;
}

void Level::AnimateNewRocks()
{
	for (size_t i = 0; i < _mNewRocks.size(); i++)
	{
		//get each rock in the array and calclate its new position
		//update their positions by 5 pixels, when a rock reaches
		//its destination, delete it from the array
		Rock *rock = _mNewRocks[i];
		int finalY = Background::OFFSET_Y + (rock->GetRow() * Rock::ROCK_HEIGHT) + (Rock::PIXEL_SEPARATION * rock->GetRow());

		SDL_Rect pos = { rock->GetPos().x, rock->GetPos().y + 5, Rock::ROCK_WIDTH, Rock::ROCK_HEIGHT };
		rock->SetPos(pos);

		if (rock->GetPos().y == finalY)
			_mNewRocks.erase(_mNewRocks.begin() + i);
	}
}

void Level::FindHorizontalChains()
{
	for (int row = 0; row < Level::ROWS; row++)
	{
		//Don't need to check the last 2 columns, we could get out of bounds
		for (int col = 0; col < Level::COLS-2;)
		{
			//check that coordinate has a valid rock
			if (_mRocks[row][col] != NULL)
			{
				//get current rock color to match neighbors' color
				unsigned short matchColor = _mRocks[row][col]->GetColor();
				
				if (_mRocks[row][col + 1] && 
					_mRocks[row][col + 1]->GetColor() == matchColor &&
					_mRocks[row][col + 2] && 
					_mRocks[row][col + 2]->GetColor() == matchColor)
				{
					//So we have at least 3 with the same color
					//create a chain object and fill it with Rocks
					RockChain chain;
					chain.SetType(RockChain::HORIZONTAL);

					unsigned int count = 0;
					do {
						chain.AddRock(_mRocks[row][col]);
						col++;
						count++;
					} while (col < Level::COLS && _mRocks[row][col] && _mRocks[row][col]->GetColor() == matchColor);

					UpdateScore(count);
					_mRockChains.push_back(chain);
				}
			}
			col++;
		}
	}
}

void Level::FindVerticalChains()
{
	for (int col = 0; col < Level::COLS; col++)
	{
		//Don't need to check the last 2 rows, we could get out of bounds
		for (int row = 0; row < Level::ROWS - 2;)
		{
			//check that coordinate has a valid rock
			if (_mRocks[row][col] != NULL)
			{
				//get current rock color to match neighbors' color
				unsigned short matchColor = _mRocks[row][col]->GetColor();

				if (_mRocks[row + 1][col] &&
					_mRocks[row + 1][col]->GetColor() == matchColor &&
					_mRocks[row + 2][col] &&
					_mRocks[row + 2][col]->GetColor() == matchColor)
				{
					//So we have at least 3 with the same color
					//create a chain object and fill it with Rocks
					RockChain chain;
					chain.SetType(RockChain::VERTICAL);

					unsigned int count = 0;
					do {
						chain.AddRock(_mRocks[row][col]);
						row++;
						count++;
					} while (row < Level::ROWS && _mRocks[row][col] && _mRocks[row][col]->GetColor() == matchColor);

					UpdateScore(count);
					_mRockChains.push_back(chain);
				}
			}
			row++;
		}
	}
}

void Level::UpdateScore(unsigned int count)
{
	if (count == 3)		
		_mScore += Level::CHAIN3;
	else if (count == 4)	
		_mScore += Level::CHAIN4;
	else if (count >= 5)
		_mScore += Level::CHAIN5PLUS;

	_itoa_s(_mScore, _mScoreString, 10, 10);
}