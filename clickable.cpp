#include "clickable.h"

Clickable::Clickable(function<void(Component *)> func)
{
	this->func = func;
}

Clickable::Clickable()
{
}

void Clickable::setFunc(function<void(Component *)> func)
{
	this->func = func;
}

function<void(Component *)> Clickable::getFunction()
{
	return this->func;
}

void Clickable::click(Component *obj)
{
	if (this->func)
	{
		func(obj);
	}
}
