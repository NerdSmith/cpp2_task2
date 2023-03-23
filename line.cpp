#include "line.h"

Line::Line(ContainerComponent *parent) : Component(parent) {}

Line::Line(ContainerComponent *parent, int x, int y, int width, int height) : Component(parent, x, y, width, height) {}

string Line::getTypeString()
{
	return Component::toString();
}

string Line::toString()
{
	return Component::toString();
}

Line::~Line()
{
}
