#include "Flower.h"



using namespace Sexy;

Flower::Flower(unsigned x_,unsigned y_)
:x(x_)
,y(y_)
,mCoinsTick(0)
{

}

Flower::~Flower()
{

}

void Flower::Flower::Update()
{
	mCoinsTick++;
}
