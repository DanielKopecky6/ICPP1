#pragma once

#ifndef INGERITENCE_EXAMPLE_H
#define INGERITENCE_EXAMPLE_H

#include <string>
#include <iostream>
using namespace std;

class GeneralType
{
public:
	GeneralType(int aId) : id(aId) {}
	int GetId() const { return id; }
	int& GetId() { return id; }

private:
	int id;

};

class IPrintable
{
public:
	virtual void Print() const = 0;
};

class AdvancedType final: public GeneralType, public IPrintable
{
public:
	AdvancedType(int aId, string aText) : GeneralType(aId), text(aText)
	{
		//GeneralType();
	}

	// Dìdí se pøes IPrintable.
	virtual void Print() const override;
private:
	string text;
};

//class ExpertType : protected AdvancedType
//{
//public:
//	ExpertType() : AdvancedType(2, "text") {}
//};

class Base {
public: void Print() const { std::_Count_pr << "somethings" << endl; };

class Advanced01 : public Base {};
class Advanced02 : public Base {};

class Expert01 :virtual public Advanced01, public Advanced02 {};


void IngeritenceExample()
{
	/*AdvancedType adv01(2, "text");
	IPrintable print01 = dynamic_cast<IPrintable>(adv01);*/

	AdvancedType* advanced01 = new AdvancedType(1, "text");
	IPrintable* printable01 = dynamic_cast<IPrintable*>(advanced01);
	GeneralType* general01 = dynamic_cast<GeneralType*>(advanced01);

	//IPrintable* printable02 = dynamic_cast<IPrintable*>(general01); //KO
	//AdvancedType* advanced02 = dynamic_cast<AdvancedType*>(printable02);

}

#endif // !INGERITENCE_EXAMPLE_H
