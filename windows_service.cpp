#include "windows_service.h"
#include "frame.h"
#include "panel.h"
#include <iostream>
#include "container_component.h"
#include "button.h"

WindowsService::WindowsService(EnvFrame *envFrame) : envFrame(envFrame), currComponent(envFrame->getRoot())
{
}

void WindowsService::printTree()
{
	this->currComponent->printWithTree(0);
}

string WindowsService::getCurrCompStr()
{
	return this->currComponent->getTypeString();
}

void WindowsService::addButton(string text, int x, int y, int width, int height, function<void(Component *)> func)
{
	new Button(dynamic_cast<ContainerComponent *>(this->currComponent), text, func, x, y, width, height);
}

void WindowsService::addPanel(int x, int y, int width, int height)
{
	new Panel(dynamic_cast<ContainerComponent *>(this->currComponent), x, y, width, height);
}

void WindowsService::userClick(int posX, int posY)
{
	ContainerComponent *c = dynamic_cast<ContainerComponent *>(this->currComponent);
	if (c)
	{
		Component *fc = c->getCompByCoord(posX, posY);
		if (fc && dynamic_cast<Button *>(fc) != nullptr)
		{
			Button *btn = dynamic_cast<Button *>(fc);
			btn->click();
		}
	}
}

void WindowsService::backToParent()
{
	if (this->currComponent->getParent())
	{
		this->currComponent = this->currComponent->getParent();
	}
}

void WindowsService::toChild(int idx)
{
	ContainerComponent *c = dynamic_cast<ContainerComponent *>(this->currComponent);
	if (c)
	{
		auto l_front = c->getChildren().begin();
		advance(l_front, idx);
		this->currComponent = *l_front;
	}
}

void WindowsService::moveComponent(int newX, int newY)
{
	this->currComponent->move(newX, newY);
}

WindowsService::~WindowsService()
{
	if (envFrame)
	{
		delete this->envFrame;
	}
}