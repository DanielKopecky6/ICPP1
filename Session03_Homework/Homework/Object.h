#pragma once
#ifndef OBJECT_H
#define OBJECT_H

struct Object{
public:
	int id;
	double x;
	double y;
public:
	Object(int aId); 
	virtual ~Object() {};

	void SetX(double aX); 
	double GetX();
	void SetY(double aY); 	
	double GetY(); 
	int GetId(); 
		
	

};




#endif // !OBJECT_H
