#include "frame.h"

void Frame::rememberBounds()
{
	this->remX = this->x;
	this->remY = this->y;
	this->remWidth = this->width;
	this->remHeight = this->height;
}

void Frame::loadBounds()
{
	this->x = this->remX;
	this->y = this->remY;
	this->width = this->remWidth;
	this->height = this->remHeight;
}

Frame::Frame() : ContainerComponent(nullptr, 0, 0, 100, 100) {}

Frame::Frame(int x, int y, int width, int height) : ContainerComponent(nullptr, x, y, width, height) {}
string Frame::getStateString()
{
	switch (this->state)
	{
	case (FrameState::MINIMIZED):
		return "Minimized";
	case (FrameState::NORMAL):
		return "Normal";
	case (FrameState::MAXIMIZED):
		return "Maximized";
	default:
		return "Unknown";
	}
}
void Frame::setMaximized()
{
	switch (this->state)
	{
	case (FrameState::MINIMIZED):
		break;
	case (FrameState::NORMAL):
		this->rememberBounds();
		// this->state
		break;
	case (FrameState::MAXIMIZED):
		break;
	}
}
string Frame::getTypeString()
{
	return "Frame";
}
string Frame::toString()
{
	return ContainerComponent::toString();
}
Frame::~Frame()
{
	cout << "F destr \n";
};