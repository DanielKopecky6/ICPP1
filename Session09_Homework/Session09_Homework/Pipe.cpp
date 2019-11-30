#include "Pipe.h"
using namespace std;

Pipe::Pipe(const int aSize)
{
	size = aSize;

	for (int i = 0; i < aSize; i++)
	{
		matrix.insert(matrix.begin(), std::vector<APipeElement*>());

	}
}

void Pipe::insertElement(const int aX, const int aY, APipeElement* aElement)
{	
	
	matrix.at(aX).insert(matrix.at(aX).end(), aElement);
}


const APipeElement* Pipe::GetElement(int aX, int aY) const
{
	APipeElement* prvek;
	if (matrix.size() < aX || aX < 0 || matrix.at(aX).size() < aY || aY < 0) {
		throw std::exception("Invalid coordinates");
	}
	prvek = matrix.at(aX).at(aY);
	return prvek;
}
bool Pipe::IsPipeOK() const
{
	APipeElement* prvek;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if(j<size && i<size) {
				prvek = matrix.at(i).at(j);
			if (prvek->IsConnectionOk(this) == false) {
				return false;
			}
			}

	}
	return true;
}

bool PipeElement::IsConnectionOk(const IPipe * aPipe) const
{
	switch (sign)
	{
	case '-':
		if (aPipe->GetElement(_x - 1, _y) == nullptr && aPipe->GetElement(_x + 1, _y) == nullptr)
			return false;
		break;
	case 'I':
		if (aPipe->GetElement(_x, _y - 1) == nullptr && aPipe->GetElement(_x, _y + 1) == nullptr)
			return false;
		break;
	case '+':
		if (aPipe->GetElement(_x - 1, _y) == nullptr && aPipe->GetElement(_x + 1, _y) == nullptr
			&& aPipe->GetElement(_x, _y - 1) == nullptr && aPipe->GetElement(_x, _y + 1) == nullptr)
			return false;
		break;
	case 'O':
		break;
	case 'T':
		if (aPipe->GetElement(_x - 1, _y) == nullptr && aPipe->GetElement(_x + 1, _y) == nullptr && aPipe->GetElement(_x, _y - 1) == nullptr)
			return false;
		break;
	default:
		break;
	}

	return true;
}

