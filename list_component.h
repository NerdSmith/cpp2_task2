#pragma once

#include "component.h"
#include "container_component.h"
#include <list>

using namespace std;

class ListComponent : Component
{
protected:
	list<string> items;

public:
	ListComponent(ContainerComponent *parent);
	ListComponent(ContainerComponent *parent,
				  int x, int y, int width, int height);

	list<string> getItems();
	void setItems(list<string> newItems);
	void addItem(string s);
	void removeItem(string s);
	void printItems();

	virtual string getTypeString();
	virtual string toString();
	virtual ~ListComponent();
};