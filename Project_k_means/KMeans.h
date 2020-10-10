#pragma once
#ifdef DISPLAY_ALL_INFO
#define DISPLAY true
#else
#define DISPLAY false
#endif // DISPLAY_ALL_INFO
#include"Space.h"
#include<vector>

class KMeans
{
private:
	int numDimension = 0;
	int numDate = 0;
	int numCategory = 0;
	int numIteration = 0;
	std::vector<std::vector<float>> data;
	std::vector<std::vector<float>> distance;
	std::vector<std::vector<std::vector<float>*>> category;
	std::vector<std::vector<float>> categoryCentre;
public:
	//d -> data
	//c -> number of category
	KMeans(std::vector<std::vector<float>> d, int c);
	//some setting
	void setup(int i);
	void initalCentre();
	void iteration();
	void calculateDistance();
	void reCategory();
	void displayCentre();
	void displayMeanDistance();
	std::vector<std::vector<float>> calculateCategoryCentre();
	~KMeans();
};

