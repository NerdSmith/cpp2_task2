#pragma once

#include "container_component.h"

enum FrameState
{
	MINIMIZED,
	NORMAL,
	MAXIMIZED
};

class Frame : public ContainerComponent
{
private:
	FrameState state = FrameState::NORMAL;
	int remX = 0;
	int remY = 0;
	int remWidth = 0;
	int remHeight = 0;

	void rememberBounds();
	void loadBounds();

public:
	Frame();
	Frame(
		int x,
		int y,
		int width,
		int height);

	// Component *getParent();
	// void setParent(Component *comp);

	string getStateString();
	void setMinimized();
	void setNormal();
	void setMaximized();

	virtual string getTypeString();
	virtual string toString();
	virtual ~Frame();
};