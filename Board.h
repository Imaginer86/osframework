#pragma once

#include "SexyAppFramework/Widget.h"
#include "GameApp.h"

#include "Constans.h"
#include "Field.h"
#include "Snake.h"
#include "Flower.h"

namespace Sexy
{
class Graphics;

class GameApp;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class Board : public Widget
{

	private:
		GameApp*	mApp;

		Field  *gField;

		std::list<Flower>	mFlowers;
		std::list<Snake>	mSnakes;

		unsigned  mCoins;
		unsigned  mTickToCoinsUp;

		unsigned  mCellSize;


	public:
		Board(GameApp* theApp);
		virtual ~Board();

		virtual void Draw(Graphics* g);
		virtual void Update();
		virtual void MouseDown(int x,int y,int theClickCount);
};
}