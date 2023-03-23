#pragma once

#include "container_component.h"
#include "component.h"

class Panel : public ContainerComponent
{
public:
	Panel(ContainerComponent *parent);
	Panel(ContainerComponent *parent,
		  int x,
		  int y,
		  int width,
		  int height);

	virtual string getTypeString();
	virtual string toString();
	virtual ~Panel();
};