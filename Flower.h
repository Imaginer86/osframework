#pragma once

namespace Sexy
{

class Flower
{
private:
	Flower();
public:
	Flower(unsigned x, unsigned y);
	~Flower();

	void Update();

	unsigned x, y;
	unsigned mCoinsTick;
};

}
