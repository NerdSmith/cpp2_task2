#pragma once

#include "container_component.h"

class Frame : public ContainerComponent
{
public:
	Frame(ContainerComponent *parent);
	Frame(
		ContainerComponent *parent,
		int x,
		int y,
		int width,
		int height);

	virtual string getTypeString();
	virtual string toString();
	virtual ~Frame();
};