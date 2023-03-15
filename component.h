#pragma once

#include <list>
#include <string>
#include <stdexcept>
#include <sstream>
using namespace std;

class Component
{
private:
	int x;
	int y;
	int width;
	int height;
	Component *parent = nullptr;

public:
	Component(Component *parent);
	Component(
		Component *parent,
		int x,
		int y,
		int width,
		int height);

	Component *getParent();
	void setParent(Component *newParent);

public:
	virtual string getTypeString();
	virtual string toString();
	string getPos();

	virtual ~Component();
};