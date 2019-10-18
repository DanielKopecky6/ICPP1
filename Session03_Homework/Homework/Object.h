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
	double GetX() const;
	void SetY(double aY); 	
	double GetY() const;
	int GetId() const; 
		
	

};




#endif // !OBJECT_H
