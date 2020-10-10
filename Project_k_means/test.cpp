#include"KMeans.h"
#include"Space.h"
int main()
{
	Space *testDate = new Space(5,1000);
	testDate->initializationData(-10, 10);
	KMeans* testCase = new KMeans(testDate->getData(), 5);
	testCase->initalCentre();
	testCase->setup(100);
	testCase->iteration();
	return 0;
}