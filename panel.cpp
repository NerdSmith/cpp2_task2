#include "panel.h"

Panel::Panel(ContainerComponent *parent) : ContainerComponent(parent) {}

Panel::Panel(ContainerComponent *parent, int x, int y, int width, int height) : ContainerComponent(parent, x, y, width, height) {}

string Panel::getTypeString()
{
	return "Panel";
}

string Panel::toString()
{
	return ContainerComponent::toString();
}

Panel::~Panel()
{
	cout << "P destr \n";
}
