#pragma once

#include "component.h"

class ContainerComponent : public Component
{
private:
	list<Component *> children;

public:
	// ContainerComponent(Component *parent);
	using Component::Component;

	void addChild(Component *comp);
	void removeChild(Component *comp);

	virtual string getTypeString();
	virtual ~ContainerComponent();
};