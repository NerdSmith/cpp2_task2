#pragma once

#include "component.h"
#include "container_component.h"

class Line : protected Component
{
	Line(ContainerComponent *parent);
	Line(
		ContainerComponent *parent,
		int x,
		int y,
		int width,
		int height);

	virtual string getTypeString();
	virtual string toString();
	virtual ~Line();
};