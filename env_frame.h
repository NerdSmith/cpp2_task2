#pragma once

#include "frame.h"
#include "component.h"

#define DEFAULT_WIDTH 1920
#define DEFAULT_HEIGHT 1080

class EnvFrame
{
private:
	Frame *rootFrame;

public:
	EnvFrame();
	EnvFrame(int width, int height);
	Frame *getRoot();
	~EnvFrame();
};