
#pragma once
#include "component.h"
#include <functional>
using namespace std;

class Component;
class Clickable
{
private:
	function<void(Component *)> func;

public:
	Clickable();
	Clickable(function<void(Component *)> func);

	void setFunc(function<void(Component *)> func);
	function<void(Component *)> getFunction();

	virtual void click(Component *obj);
};