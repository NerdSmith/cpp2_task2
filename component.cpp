#include "component.h"
#include <iostream>
using namespace std;

Component::Component(Component *parent) : Component(parent, 0, 0, 100, 100){};

Component::Component(
	Component *parent,
	int x,
	int y,
	int width,
	int height) : x{x}, y{y}, width{width}, height{height}
{
	setParent(parent);
}

void Component::setParent(Component *newParent)
{
	if (this == newParent)
	{
		throw invalid_argument("You can't set the parent of a component to the component itself!");
	}
	this->parent = newParent;
}

string Component::getTypeString()
{
	return "BaseComponent";
}

string Component::getPos()
{
	stringstream ss;
	ss
		<< "x = " << this->x << ", "
		<< "y = " << this->y << ", "
		<< "width = " << this->width << ", "
		<< "height = " << this->height;
	return ss.str();
}

string Component::toString()
{
	stringstream ss;
	ss
		<< this->getTypeString() << " in "
		<< this->getPos();
	return ss.str();
}

Component::~Component()
{
}