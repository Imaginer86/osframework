#pragma once
#include <vector>

#include "Field.h"

namespace Sexy
{

class Snake
{
public:
	enum RunWay { Left, Right, Up, Down };
private:	
	Snake();

	struct Box
	{
		unsigned x;
		unsigned y;
	};
	
	bool mSleep;
	unsigned mGrownUpTick;

	Field *pField;

	RunWay mRunWay;
	RunWay mWayRand;

public:
	std::vector<Box> Boxes;
	unsigned  mRunPosTick;
	Snake(unsigned x, unsigned y);
	~Snake();

	void Init(Field *pField_);

	void Update();

	bool SetRunWay( RunWay way);
	RunWay GetRunWay() { return mRunWay; }

	void Upper();
	void Lower();

	unsigned GetSize() { return Boxes.size(); }
	unsigned GetPosX(unsigned i) { return Boxes[i].x; }
	unsigned GetPosY(unsigned i) { return Boxes[i].y; }
		
};

}
