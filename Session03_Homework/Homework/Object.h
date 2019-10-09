#pragma once
#ifndef OBJECT_H
#define OBJECT_H

struct Object{
public:
	int id;
	double x;
	double y;
public:
	//Object() {}; bezparametricky konstruktor dle zadani nevytvaret
	Object(int aId); 
	virtual ~Object() {};

	void SetX(double aX); 
	double GetX();
	void SetY(double aY); 	
	double GetY(); 
	int GetI(); 
		
	

};




#endif // !OBJECT_H
