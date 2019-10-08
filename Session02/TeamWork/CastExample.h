//#pragma once
#ifndef CAST_EXAMPLE_H
#define CAST_EXAMPLE_H
#include<iostream>

class PrivateType final
{
public:
	PrivateType(int aValue) : value(aValue) {}
private:
	int value;

};

class PublicType
{
public:
	PublicType(int aValue) : Value(aValue) {}
	int Value;
};

void CastExample()
{
	int* i = new int(3);
	void* pI = (void*)i;

	PrivateType* obj01 = new PrivateType(1);
	void* pObj01 = static_cast<void*>(obj01);
	PrivateType* obj02 = static_cast<PrivateType*>(pObj01);

	PublicType* publicObj01 = reinterpret_cast<PublicType*>(obj01);
	std::cout << publicObj01->Value << std::endl;

	delete i;
	delete obj01;
	
}




#endif // !CAST_EXAMPLE_H
