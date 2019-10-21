#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
# include "IObject.h"

struct IComparable : IObject {
	virtual int compareTo(IComparable* obj) const { return 0; };

};


#endif // !ICOMPARABLE_H
