#include "Board.h"
#include "SexyAppFramework/Graphics.h"

#include "SexyAppFramework/Color.h"

#include "SexyAppFramework/ImageFont.h"

using namespace Sexy;

//unsigned gField[gFieldWidth][gFieldHeight];

Board::Board(GameApp* theApp)
{
	gField = new Field;
	mApp = theApp;

	mCoins = gStartCoins;
	//mCellSize = mFieldWidth > mFieldHeight ? mHeight / mFieldHeight : mHeight / mFieldWidth;

	mCellSize = 60;//todo
}


Board::~Board()
{
	delete gField;
}


void Board::Update()
{
	Widget::Update();

	for (std::list<Flower>::iterator it = mFlowers.begin(); it != mFlowers.end(); ++it)
	{
		it->Update();
		if (it->mCoinsTick > gFlowerBloomTick)
		{
			it->mCoinsTick = 0;
			mCoins += gFlowerCoins;
		}
	}

	for (std::list<Snake>::iterator it = mSnakes.begin(); it != mSnakes.end(); ++it)
	{
		it->Update();
		switch (it->GetRunWay())
		{
		case Snake::RunWay::Right:

			break;
		case Snake::RunWay::Left:

			break;
		case Snake::RunWay::Up:

			break;
		case Snake::RunWay::Down:

			break;

		default:
			;
		}
	}

	MarkDirty();
}

void Board::Draw(Graphics* g)
{
	g->FillRect(0, 0, mWidth, mHeight);

	g->SetColor(Color(64, 255, 64));
	g->FillRect(0, 0, mHeight, mHeight);

	g->SetColor(Color(64, 128, 64));
	g->FillRect(mHeight, 0, mWidth - mHeight, mHeight);

	g->SetColor(Color(255, 255, 255));

	for(unsigned i = 0; i <= gFieldWidth; ++i)	
		g->DrawLine(i*mCellSize, 0, i*mCellSize, mHeight);
	for (unsigned i = 0; i <= gFieldHeight; ++i)
		g->DrawLine(0, i*mCellSize,mHeight, i*mCellSize);

	g->SetColor(Color(255, 64, 64));
	for(std::list<Flower>::iterator it = mFlowers.begin(); it != mFlowers.end(); ++it)
	{
		g->FillRect(it->x*mCellSize, it->y*mCellSize, mCellSize, mCellSize);
	}

	g->SetColor(Color(0,0,255));
	for (std::list<Snake>::iterator it = mSnakes.begin(); it != mSnakes.end(); ++it)
	{
		for (unsigned i = 0; i < it->GetSize(); ++i)
		{			
			for (unsigned i = 0; i < it->Boxes.size(); ++i)
			{
				int x, y;
				x = it->GetPosX(i)*mCellSize + mCellSize*it->mRunPosTick / gBaseSnakePosTick;
				y = it->GetPosY(i)*mCellSize;
				g->FillRect(x,y,mCellSize,mCellSize);
			}
		}
	}

	g->SetColor(Color(255,255,0));
	g->SetFont(mApp->mFont);
	SexyString myString = StrFormat(_S("Coins: %d"),mCoins);
	g->DrawString(myString,mHeight + 20,20);
}

void Board::MouseDown(int x_,int y_,int theClickCount)
{
	Widget::MouseDown(x_,y_,theClickCount);
	
	if (x_ >= mHeight) return;

	unsigned x = x_ / mCellSize;
	unsigned y = y_ / mCellSize;

	//if (*(gField + gFieldHeight*y + x) == 0)
	//{
		//Flower flower(x, y);
		//mFlowers.push_back(flower);
	//}

	if (gField->Get(x,y) == 0)
	{
		Snake snake(x, y);
		mSnakes.push_back(snake);
		mSnakes.back().Init(gField);
		mSnakes.back().SetRunWay(Snake::RunWay::Right);
		mSnakes.back().Upper();
		mSnakes.back().Upper();
		mSnakes.back().Upper();
		mSnakes.back().Upper();
		mSnakes.back().Upper();
	}
}

