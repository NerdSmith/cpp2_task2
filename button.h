#pragma once

#include "clickable.h"
#include "label.h"
#include "container_component.h"

class Button : public Clickable, public Label
{
public:
	Button(ContainerComponent *parent, function<void()> func);
	Button(ContainerComponent *parent,
		   string text,
		   function<void()> func);
	Button(ContainerComponent *parent,
		   string text,
		   function<void()> func,
		   int x,
		   int y,
		   int width,
		   int height);

	virtual void click();

	virtual string getTypeString();
	virtual string toString();
	virtual ~Button();
};