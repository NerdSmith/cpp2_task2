#include "button.h"

Button::Button(ContainerComponent *parent, function<void()> func) : Label(parent), Clickable(func) {}

Button::Button(ContainerComponent *parent, string text, function<void()> func) : Label(parent, text), Clickable(func) {}

Button::Button(ContainerComponent *parent, string text, function<void()> func, int x, int y, int width, int height) : Label(parent, x, y, width, height, text), Clickable(func) {}

void Button::click()
{
	if (this->active)
	{
		Clickable::click();
	}
}

string Button::getTypeString()
{
	return "Button";
}

string Button::toString()
{
	return Label::toString();
}

Button::~Button()
{
	cout << "B destr \n";
}
