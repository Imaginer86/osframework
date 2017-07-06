#include "Field.h"



using namespace Sexy;

Field::Field()
{
	for (unsigned i = 0; i < gFieldHeight; ++i)
		for (unsigned j = 0; j < gFieldWidth; ++j)
			mField.push_back(0);
}


Field::~Field()
{
	int t = 0;
}
