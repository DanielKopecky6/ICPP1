#include "Pipe.h"
using namespace std;

Pipe::Pipe(const int aSize)
{
	size = aSize;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			
		}

	}
	std::vector<std::vector<APipeElement*>> aMatrix(size, vector<APipeElement*>(size));
	matrix = aMatrix;
}

void Pipe::insertElement(const int aX, const int aY, APipeElement* aElement)
{
	
	matrix[aX][aY] = aElement;


}


const APipeElement* Pipe::GetElement(int aX, int aY) const
{
	APipeElement* prvek;
	try
	{
		if (matrix.size() < aX || aX < 0 || matrix.at(aX).size() < aY || aY < 0) {
			throw std::logic_error("Accesing invalid coordinates");
		}
			prvek = matrix[aX][aY];
			return prvek;
	}
	catch (std::exception& message)
	{
		std::cout << message.what();
	}
	
}
bool Pipe::IsPipeOK() const
{
	APipeElement* prvek = nullptr;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++){

				prvek = matrix[i][j];
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
		if ((aPipe->GetElement(_x , _y - 1) == nullptr) && (aPipe->GetElement(_x , _y + 1) == nullptr))
			return false;
		break;
	case 'I':
		if (aPipe->GetElement(_x - 1, _y ) == nullptr && aPipe->GetElement(_x + 1, _y ) == nullptr)
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
		if (aPipe->GetElement(_x, _y - 1 ) == nullptr && aPipe->GetElement(_x , _y + 1) == nullptr && aPipe->GetElement(_x + 1, _y) == nullptr)
			return false;
		break;
	default:
		break;
	}

	return true;
}

