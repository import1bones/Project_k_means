#pragma once
#include<random>
#include<vector>
#include<time.h>
using std::vector;


class Space
{
private:
	int numData = 0;
	int numDimension = 0;
	float dataLo = 0;
	float dataHi = 0;
	vector<vector<float>> data;
public:
	Space(int,int);
	~Space();
	void initializationData(float, float);
	vector<vector<float>> getData();
};

