#include "env_frame.h"

EnvFrame::EnvFrame(int width, int height)
{
	this->rootFrame = new Frame(0, 0, width, height);
}

Frame *EnvFrame::getRoot()
{
	return rootFrame;
}

EnvFrame::EnvFrame() : EnvFrame(DEFAULT_WIDTH, DEFAULT_HEIGHT)
{
}

EnvFrame::~EnvFrame()
{
	if (this->rootFrame)
	{
		delete this->rootFrame;
	}
}
