#include "Snake.h"
#include "Constans.h"

using namespace Sexy;

Snake::Snake(unsigned x_, unsigned y_)
:mSleep(false)
,mGrownUpTick(0)
,mRunPosTick(0)
{
	Box box;
	box.x = x_;
	box.y = y_;
	Boxes.push_back(box);
}

Snake::~Snake()
{
	//delete pField;
}

void Snake::Init(Field *pField_)
{
	pField = pField_;
}

bool Snake::SetRunWay(RunWay way)
{
	unsigned x = Boxes[0].x;
	unsigned y = Boxes[0].y;
	switch (way)
	{
	case RunWay::Left:
		if ( x >= 0 && pField->Get(x, y) == 0 )
		{
			mRunWay = RunWay::Left;
			if ( x != 0 )
				pField->Set(1, x - 1, y);
			return true;
		}
		break;
	case RunWay::Right:
		if (x < (gFieldWidth- 1 ) && pField->Get(x,y) == 0 )
		{
			mRunWay = RunWay::Right;
			if ( x != gFieldWidth)
				pField->Set(1, x + 1, y);
			return true;
		}
		break;
	case RunWay::Up:
		if (y == 0 && pField->Get(x,y) == 0)
		{
			mRunWay = RunWay::Up;
			if ( y != 0 )
				pField->Set(1, x, y - 1);
			return true;
		}
		break;
	case RunWay::Down:
		if (x < (gFieldHeight-1) || pField->Get(x,y) == 0)
		{
			mRunWay = RunWay::Down;
			if ( y != gFieldHeight )
				pField->Set(1, x, y + 1);
			return true;
		}
		break;
	default:
		return false;
	}
	return false;
}

void Snake::Upper()
{
	Box box;
	box.x = Boxes[0].x;
	box.y = Boxes[0].y;
	if (mRunWay == RunWay::Right)
	{
		box.x++;
	}
	if (mRunWay == RunWay::Left)
	{
		box.x--;
	}
	if (mRunWay == RunWay::Up)
	{
		box.y--;
	}
	if (mRunWay == RunWay::Down)
	{
		box.y++;
	}
	Boxes.resize(Boxes.size() + 1);
	for (unsigned i = Boxes.size() - 1; i > 0; --i)
		Boxes[i] = Boxes[i - 1];
	Boxes[0] = box;
}

void Snake::Update()
{
	mRunPosTick++;
	if (mRunPosTick > gBaseSnakePosTick)
	{		
		mRunPosTick = 0;

		for (unsigned i = Boxes.size() - 1; i > 0; --i)
		{
			Boxes[i].x = Boxes[i - 1].x;
			Boxes[i].y = Boxes[i - 1].y;
		}

		if (mRunWay == RunWay::Right)
		{
			Boxes[0].x++;
		}
		if (mRunWay == RunWay::Left)
		{
			Boxes[0].x--;
		}
		if (mRunWay == RunWay::Up)
		{
			Boxes[0].y--;
		}
		if (mRunWay == RunWay::Down)
		{
			Boxes[0].y++;
		}
	}

	mGrownUpTick++;
	if (mGrownUpTick > gSnakeGrowthUpTick)
	{
		mGrownUpTick = 0;		
	}
}

