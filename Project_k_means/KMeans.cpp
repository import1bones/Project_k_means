#include "KMeans.h"
using std::vector;

KMeans::KMeans(std::vector<std::vector<float>> d, int c)
{
	data = d;
	numCategory = c;
	numDate = data.size();
	numDimension = data.front().size();
}

void KMeans::setup(int i)
{
	numIteration = i;
}

void KMeans::initalCentre()
{
	srand(static_cast<unsigned>(time(0)));
	int r;
	for (int i = 0; i < numCategory;)
	{
		r = rand() % numDate;
		bool pb = true;
		for (auto x : categoryCentre)
		{
			if (x == data[r])
			{
				pb = false;
				break;
			}
		}
		if (pb)
		{
			categoryCentre.push_back(data[r]);
			i++;
		}
	}
	printf("\033[41;36m%s \033[0m\n", "[Inital] :");
	displayCentre();
}

void KMeans::iteration()
{
	printf_s("\033[41;36m%s %d\033[0m\n", "[summary]: parameters", numDimension * numDate);
	for (int i = 0; i < numIteration; ++i)
	{
		calculateDistance();
		reCategory();
		if (calculateCategoryCentre() != categoryCentre)
		{
			categoryCentre.clear();
			categoryCentre = calculateCategoryCentre();
		}
		else
		{
			printf_s("\033[41;36m%s\t%d\033[0m\n", "[attention]: break in iteration :", i);
			break;
		}
		if (DISPLAY)
		{
			printf_s("\033[44;33m%s\t%d\033[0m\n", "[iteration]:", i);
			displayCentre();
		}
	}
	printf_s("\033[42;35m%s \033[0m\n", "[final centre]:");
	displayCentre();
}

void KMeans::calculateDistance()
{
	distance.clear();
	distance.resize(numDate);
	for (int i = 0; i < numDate; i++)
	{
		distance[i].resize(numCategory);
		for (int j = 0; j < numCategory; j++)
		{
			float dist = 0;
			for (int k = 0; k < numDimension; k++)
			{
				dist += pow(data[i][k] - categoryCentre[j][k], 2);
			}
			distance[i][j] = sqrt(dist);
		}
	}
}

void KMeans::reCategory()
{
	category.clear();
	category.resize(numCategory);
	for (int i = 0; i < numDate; i++)
	{
		int min = 0;
		for (int j = 0; j < numCategory; j++)
		{
			if (distance[i][j] < distance[i][min])
			{
				min = j;
			}
		}
		category[min].push_back(&data[i]);
	}
}

void KMeans::displayCentre()
{
	for (int i = 0; i < numCategory; i++)
	{
		printf_s("\t\033[43;34m%s\t%d\033[0m\t", "[centre]:",i);
		for (int j = 0; j < numDimension; j++)
		{
			printf_s("%f\t", categoryCentre[i][j]);
		}
		printf_s("\n");
	}
}

void KMeans::displayMeanDistance()
{
	//will display a category's all data's distance to the category's centre.
	//the numer like loss in Gradient descent.
}

std::vector<std::vector<float>> KMeans::calculateCategoryCentre()
{
	vector<vector<float>> newCategoryCentre;
	for (int i = 0; i < numCategory; i++)
	{
		vector<float> meanCentre(numDimension);
		for (int j = 0; j < category[i].size(); j++)
		{
			int k = 0;
			for (vector<float>::iterator iter = category[i][j]->begin(); iter < category[i][j]->end(); iter++)
			{
				meanCentre[k] += *iter;
				k++;
			}
		}
		for (float &x : meanCentre)
		{
			x = x / static_cast<float>(category[i].size());
		}
		newCategoryCentre.push_back(meanCentre);
	}
	return newCategoryCentre;
}

KMeans::~KMeans()
{
}
