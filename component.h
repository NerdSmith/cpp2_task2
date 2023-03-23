#pragma once

#include <list>
#include <string>
#include <stdexcept>
#include <sstream>
using namespace std;

class ContainerComponent;

class Component
{
protected:
	int x;
	int y;
	int width;
	int height;
	ContainerComponent *parent = nullptr;
	bool active = true;

public:
	Component(ContainerComponent *parent);
	Component(
		ContainerComponent *parent,
		int x,
		int y,
		int width,
		int height);

	ContainerComponent *getParent();
	void setParent(ContainerComponent *newParent);
	bool isPointIn(int x, int y);

public:
	virtual string getTypeString();
	virtual string toString();
	virtual void printWithTree(int level);
	string getPos();

	void move(int newX, int newY);
	void resize(int newWidth, int newHeight);

	int getX();
	int getY();
	int getWidth();
	int getHeight();

	void enable();
	void disable();
	bool isActive();
	virtual Component *getCompByCoord(int posX, int posY);

	// bool operator==(Component &comp)
	// {
	// 	return (comp.getX() == this->x) && (comp.getY() == this->y) &&
	// 		   (comp.getWidth() == this->width) && (comp.getHeight() == this->height) &&
	// 		   (comp.getParent() == this->parent);
	// }

	virtual ~Component();
};