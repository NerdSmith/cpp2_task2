#pragma once
#include "env_frame.h"
#include <functional>

class WindowsService
{
private:
	EnvFrame *envFrame;
	Component *currComponent;

public:
	WindowsService(EnvFrame *envFrame);
	void printTree();
	string getCurrCompStr();
	void addButton(string text, int x, int y, int width, int height, function<void(Component *)> func);
	void addPanel(int x, int y, int width, int height);
	void userClick(int posX, int posY);
	void backToParent();
	void toChild(int idx);
	void moveComponent(int newX, int newY);
	~WindowsService();
};