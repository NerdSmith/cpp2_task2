#include "frame.h"

Frame::Frame(ContainerComponent *parent) : ContainerComponent(parent, 0, 0, 100, 100) {}

Frame::Frame(ContainerComponent *parent, int x, int y, int width, int height) : ContainerComponent(parent, x, y, width, height) {}
string Frame::getTypeString()
{
	return "Frame";
}
string Frame::toString()
{
	return ContainerComponent::toString();
}
Frame::~Frame(){
	cout << "F destr \n";
};