#ifndef PIPE_H
#define PIPE_H

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>

struct APipeElement;
struct IPipe {
	virtual ~IPipe() {};
	virtual const APipeElement* GetElement(int aX, int aY)const = 0;
	virtual bool IsPipeOK()const = 0;
	virtual void insertElement(const int aX, const int aY, APipeElement* aElement) = 0;
};

struct APipeElement {
	virtual ~APipeElement() { };
	virtual bool IsConnectionOk(const IPipe* aPipe)const = 0;
	int _x;
	int _y;

};

struct Pipe : IPipe {
private:
	int size;
	std::vector<std::vector<APipeElement*>> matrix = std::vector<std::vector<APipeElement*>>();

public:
	Pipe(const int aSize);
	~Pipe() {};
	void insertElement(const int aX, const int aY, APipeElement* aElement);
	const APipeElement* GetElement(int aX, int aY)const;
	bool IsPipeOK()const;
};
struct PipeElement : APipeElement {
private:
	char sign;
public:
	PipeElement(int _aX, int _aY, char aSign) {_x = _aX, _y = _aY , sign = aSign; }
	bool IsConnectionOk(const IPipe* aPipe) const;
};


#endif // !PIPE_H
