#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>
struct IObject {
	virtual std::string toString() const = 0;
	virtual ~IObject() { };


};


#endif // !IOBJECT_H
