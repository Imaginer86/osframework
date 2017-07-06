#pragma once
#include "Constans.h"

#include <vector>

namespace Sexy
{

class Field
{
private:
	std::vector<unsigned> mField;
public:	
	Field();
	~Field();

	void Set(unsigned data,unsigned x,unsigned y) { mField[gFieldHeight*y + x] = data; }
	unsigned Get(unsigned x, unsigned y) { return mField[gFieldHeight*y + x]; }	
};

}
