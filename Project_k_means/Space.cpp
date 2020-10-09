#include "Space.h"
//d-> data's d
Space::Space(int d, int n)
{
	numDimension = d;
	numData = n;
	srand(static_cast<unsigned>(time(0)));
}

Space::~Space()
{
}

void Space::initializationData(float lo, float hi)
{
	dataLo = lo;
	dataHi = hi;
	data.resize(numData);
	for (int i = 0; i < numData; ++i)
	{
		data[i].resize(numDimension);
		for (int j = 0; j < numDimension; j++)
		{
			data[i][j]= lo + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (hi - lo)));
		}
	}
}

vector<vector<float>> Space::getData()
{
	if (data.empty())
	{
		throw("warn!: empty data");
	}
	else
	{
		return data;
	}
}
