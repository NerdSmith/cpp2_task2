#pragma once

#include <list>
#include <string>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <iostream>
#include "component.h"
using namespace std;

class Component;

class ContainerComponent : public Component
{
protected:
	list<Component *> children;

public:
	// ContainerComponent(Component *parent);
	using Component::Component;

	void addChild(Component *comp);
	void removeChild(Component *comp);
	list<Component *> getChildren();

	virtual string getTypeString();
	virtual string toString();
	virtual void printWithTree(int level);
	virtual Component *getCompByCoord(int posX, int posY);
	virtual ~ContainerComponent();
};