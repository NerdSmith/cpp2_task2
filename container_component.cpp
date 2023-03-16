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

ContainerComponent::~ContainerComponent()
{
	cout << "CC destr \n";
	for (auto &child : this->children)
	{
		delete child;
	}
}