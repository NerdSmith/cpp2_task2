#include "component.h"
#include "container_component.h"
#include <iostream>
using namespace std;

Component::Component(ContainerComponent *parent) : Component(parent, 0, 0, 100, 100){};

Component::Component(
	ContainerComponent *parent,
	int x,
	int y,
	int width,
	int height) : x{x}, y{y}, width{width}, height{height}
{
	setParent(parent);
}

ContainerComponent *Component::getParent()
{
	return this->parent;
}

void Component::setParent(ContainerComponent *newParent)
{
	if (!newParent)
	{
		return;
	}
	if (this == newParent)
	{
		throw invalid_argument("You can't set the parent of a component to the component itself!");
	}
	if (this->parent)
	{
		this->parent->removeChild(this);
	}
	if (!newParent->isPointIn(this->x, this->y))
	{
		throw invalid_argument("Can't set component outside parent component");
	}
	newParent->addChild(this);
	this->parent = newParent;
}

bool Component::isPointIn(int x, int y)
{
	return (0 < x < this->width) && (0 < y < this->height);
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

void Component::move(int newX, int newY)
{
	if (!parent)
	{
		this->x = newX;
		this->y = newY;
		return;
	}
	if (parent->isPointIn(newX, newY))
	{
		this->x = newX;
		this->y = newY;
	}
	else
	{
		throw invalid_argument("Can't move component outside parent component");
	}
}

void Component::resize(int newWidth, int newHeight)
{
	this->width = newWidth;
	this->height = newHeight;
}

int Component::getX()
{
	return this->x;
}

int Component::getY()
{
	return this->y;
}

int Component::getWidth()
{
	return this->width;
}

int Component::getHeight()
{
	return this->height;
}

void Component::enable()
{
	this->active = true;
}

void Component::disable()
{
	this->active = false;
}

bool Component::isActive()
{
	return this->active;
}

Component *Component::getCompByCoord(int posX, int posY)
{
	int realX = posX - this->x;
	int realY = posY - this->y;
	if (((0 < realX) && (realX < this->width)) && ((0 < realY) && (realY < this->height)))
	{
		return this;
	}
	return nullptr;
}

string Component::toString()
{
	stringstream ss;
	ss
		<< this->getTypeString() << " ("
		<< (this->active ? "active" : "disable") << ") in "
		<< this->getPos();
	return ss.str();
}

void Component::printWithTree(int level)
{
	cout << string(level, '\t') << this->toString() << endl;
}

Component::~Component()
{
	// cout << "C destr \n";
}