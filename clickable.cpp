#include "clickable.h"

Clickable::Clickable(function<void()> func)
{
	this->func = func;
}

Clickable::Clickable()
{
}

void Clickable::setFunc(function<void()> func)
{
	this->func = func;
}

function<void()> Clickable::getFunction()
{
	return this->func;
}

void Clickable::click()
{
	if (this->func)
	{
		func();
	}
}
