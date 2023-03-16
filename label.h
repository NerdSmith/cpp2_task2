#pragma once

#include "component.h"
#include "container_component.h"

class Label : public Component
{
protected:
	string text;

public:
	using Component::Component;

	Label(ContainerComponent *parent, string text);
	Label(ContainerComponent *parent,
		  int x,
		  int y,
		  int width,
		  int height,
		  string text);

	string getText();
	void setText(string text);

	virtual string getTypeString();
	virtual string toString();
	virtual ~Label();
};