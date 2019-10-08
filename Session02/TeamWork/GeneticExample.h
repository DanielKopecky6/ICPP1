#pragma once

#ifndef GENERIC_EXAMPLE_H
#define GENERIC_EXAMPLE_H

#include <iostream>

struct Point {
	int X;
	int Y;
	Point(int x, int y) : X(x), Y(y){}
};

template <typename T>
void Print(T aValue)
{
	std::cout << aValue << std::endl;
}

template <>
void Print(Point aValue)
{
	std::cout << aValue.X << ", " << aValue.Y << std::endl;
}

void GeneticExpample()
{
	Print(2);
	Print("text");
	Print(Point(1, 1));
}

#endif // !GENERIC_EXAMPLE_H

