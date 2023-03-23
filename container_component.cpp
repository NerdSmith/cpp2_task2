#include "container_component.h"

void ContainerComponent::addChild(Component *comp)
{
	if (comp)
	{
		if (comp->getParent())
		{
			ContainerComponent *pComp = comp->getParent();
			pComp->removeChild(comp);
		}
		this->children.push_back(comp);
	}
}

void ContainerComponent::removeChild(Component *comp)
{
	this->children.remove(comp);
}

list<Component *> ContainerComponent::getChildren()
{
	return this->children;
}

string ContainerComponent::getTypeString()
{
	return "ContainerComponent";
}

string ContainerComponent::toString()
{
	stringstream ss;
	ss
		<< Component::toString() << " with "
		<< this->children.size() << " children";
	return ss.str();
}

void ContainerComponent::printWithTree(int level)
{
	Component::printWithTree(level);
	for (auto &child : this->children)
	{
		child->printWithTree(level + 1);
	}
}

Component *ContainerComponent::getCompByCoord(int posX, int posY)
{
	list<Component *>::reverse_iterator iter = this->children.rbegin();
	int realX = posX - this->x;
	int realY = posY - this->y;
	for (; iter != this->children.rend(); ++iter)
	{
		Component *c = (*iter)->getCompByCoord(realX, realY);
		if (c)
		{
			return c;
		}
		// if (dynamic_cast<ContainerComponent *>(*iter))
		// {
		// 	ContainerComponent *cc = dynamic_cast<ContainerComponent *>(*iter);
		// 	Component *c = cc->getCompByCoord(realX, realY);
		// 	if (c)
		// 	{
		// 		return c;
		// 	}
		// }
		// else
		// {
		// 	Component *c = (*iter)->getCompByCoord(realX, realY);
		// 	if (c)
		// 	{
		// 		return c;
		// 	}
		// }
	}
	return nullptr;
}

ContainerComponent::~ContainerComponent()
{
	// cout << "CC destr \n";
	for (auto &child : this->children)
	{
		delete child;
	}
}