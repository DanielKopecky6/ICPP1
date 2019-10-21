#include <iostream>
#include "Time.h"

int main(void) {

	Time cas1 = Time(23, 25, 49);
	Time cas2 = Time(13, 0, 0);

		
	std::cout << "Time compare: " << cas1.compareTo(&cas2) << std::endl;
	std::cout << "Time toString: " << cas1.toString() << std::endl;
	
	IComparable** array = new IComparable*[10];
	int arraySize = 0;
	Time* time;

	for (int i = 0; i < 10; i++)
	{
		int _hours = rand() % 24;
		int _minutes = rand() % 60;
		int _seconds = rand() % 60;
		time = new Time(_hours, _minutes, _seconds);
		array[i] = time;
		arraySize++;		
	}
	
	//cas1.Time::ArraySort(array,arraySize);

	std::cin.get();
	return 0;
}