
#pragma once

#include <functional>
using namespace std;

class Clickable
{
private:
	function<void()> func;

public:
	Clickable();
	Clickable(function<void()> func);

	void setFunc(function<void()> func);
	function<void()> getFunction();

	virtual void click();
};