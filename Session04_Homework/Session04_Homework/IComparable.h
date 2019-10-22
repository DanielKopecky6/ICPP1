#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
# include "IObject.h"

struct IComparable : IObject {
	virtual int compareTo(IComparable* obj) const=0;
	virtual std::string IObject::toString() const override = 0;
	virtual ~IComparable() { };
};


#endif // !ICOMPARABLE_H
