#pragma once
#include<stdio.h>
#include<random>
#include<vector>
#include<time.h>

class Space
{
private:
	int numData = 0;
	int numDimension = 0;
	float dataLo = 0;
	float dataHi = 0;
	std::vector<std::vector<float>> data;
public:
	//d-> data's dimension
	//n-> number of datas
	Space(int d, int n);
	~Space();
	void initializationData(float, float);
	std::vector<std::vector<float>> getData();
};

