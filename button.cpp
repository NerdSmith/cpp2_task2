#include "button.h"

Button::Button(ContainerComponent *parent, function<void(Component *)> func) : Label(parent), Clickable(func) {}

Button::Button(ContainerComponent *parent, string text, function<void(Component *)> func) : Label(parent, text), Clickable(func) {}

Button::Button(ContainerComponent *parent, string text, function<void(Component *)> func, int x, int y, int width, int height) : Label(parent, x, y, width, height, text), Clickable(func) {}

void Button::click()
{
	if (this->active)
	{
		Clickable::click(this);
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
	// cout << "B destr \n";
}
