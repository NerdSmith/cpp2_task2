#include "label.h"

Label::Label(ContainerComponent *parent, string text) : Component(parent)
{
	this->text = text;
}

Label::Label(ContainerComponent *parent, int x, int y, int width, int height, string text) : Component(parent, x, y, width, height)
{
	this->text = text;
}

string Label::getText()
{
	return this->text;
}

void Label::setText(string text)
{
	this->text = text;
}

string Label::getTypeString()
{
	return "Label";
}

string Label::toString()
{
	return Component::toString();
}

Label::~Label()
{
	// cout << "L destr \n";
}
