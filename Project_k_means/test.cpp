#include"KMeans.h"
#include"Space.h"
int main()
{
	Space *testDate = new Space(10,500);
	testDate->initializationData(-32, 32);
	KMeans* testCase = new KMeans(testDate->getData(), 10);
	testCase->initalCentre();
	testCase->setup(500);
	testCase->iteration();
	return 0;
}