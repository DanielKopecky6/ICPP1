#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>
struct IObject {
	virtual std::string toString() const { return 0; };


};


#endif // !IOBJECT_H
