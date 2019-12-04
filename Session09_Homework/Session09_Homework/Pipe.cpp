#include "Pipe.h"
using namespace std;

Pipe::Pipe(const int aSize)
{
	std::vector<std::vector<APipeElement*>> aMatrix(aSize, vector<APipeElement*>(aSize));
	matrix = aMatrix;
}

void Pipe::insertElement(const int aX, const int aY, APipeElement* aElement)
{
	try{
	if (matrix.size() > aX && aX >= 0 && matrix.size() > aY && aY >= 0) {
		matrix[aX][aY] = aElement;
	}
	else {
		throw std::logic_error("Accesing invalid coordinates\n");
	}
	}
	catch (std::exception& message)
	{
		std::cout << message.what();
	}
	

}


const APipeElement* Pipe::GetElement(int aX, int aY) const
{
	APipeElement* prvek;
	char sign;
	if (matrix.size() > aX && aX >= 0 && matrix.size() > aY && aY >= 0) {
		prvek = matrix[aX][aY];
		if (prvek == nullptr || prvek->ReturnSign() == ' ') {
			return false;
		}
		return prvek;
	}
	else {
		return false;
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

const char PipeElement::ReturnSign() const
{
	return sign;
}

bool PipeElement::IsConnectionOk(const IPipe * aPipe) const
{
	switch (sign)
	{
	case '-':
		if (aPipe->GetElement(_x, _y - 1) == false) {
			return false;
		}
		if ((aPipe->GetElement(_x, _y - 1) == false) || (aPipe->GetElement(_x, _y + 1) == false))
			return false;
		break;
	case 'I':
		if (aPipe->GetElement(_x - 1, _y ) == false || aPipe->GetElement(_x + 1, _y ) == false)
			return false;
		break;
	case '+':
		if ((aPipe->GetElement(_x - 1, _y) == false) || (aPipe->GetElement(_x + 1, _y) == false) || (aPipe->GetElement(_x, _y - 1) == false) || (aPipe->GetElement(_x, _y + 1) == false))
			return false;
		break;
	case 'O':
		break;
	case 'T':
		if (aPipe->GetElement(_x, _y - 1 ) == false || aPipe->GetElement(_x , _y + 1) == false || aPipe->GetElement(_x + 1, _y) == false)
			return false;
		break;
	default:
		break;
	}

	return true;
}

