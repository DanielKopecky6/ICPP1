#include <iostream>
#include <utility>
#include <Time.h>
#include "Time.h"


void ArraySort(IComparable** aArray, int aArraySize) //selection sort
{
	
	for (int i = 0; i < aArraySize - 1; i++)
	{
		int maxIndex = i;
		for (int j = i + 1; j < aArraySize; j++) {
			if ((aArray[j]->compareTo(aArray[maxIndex])==1)){
				maxIndex=j;
			}

		}
		std::swap(aArray[maxIndex], aArray[i]);
	
	}
}
void printArray(IComparable** aArray, int aArraySize)
{
	for (size_t i = 0; i < aArraySize; i++) {
		std::cout << "Time at index: " << i << " = " << aArray[i]->toString() << std::endl;
	}
}

int main(void) {
	srand(time(NULL));
	Time cas1 = Time(5, 25, 49);
	Time cas2 = Time(13, 0, 0);

		
	std::cout << "Time compare: " << cas1.compareTo(&cas2) << std::endl;
	std::cout << "Time toString: " << cas1.toString() << std::endl;
	
	IComparable** array = new IComparable*[10];
	int arraySize = 0;

	for (int i = 0; i < 10; i++)
	{
		int _hours = rand() % 24;
		int _minutes = rand() % 60;
		int _seconds = rand() % 60;
		array[i] = new Time(_hours, _minutes, _seconds);
		arraySize++;		
	}
	std::cout << "Array before sort" << std::endl;
	printArray(array, arraySize);
	
	ArraySort(array, arraySize);


	std::cout << "Array after sort" << std::endl;
	printArray(array, arraySize);

	std::cin.get();
	return 0;
}