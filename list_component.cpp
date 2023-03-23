#include "list_component.h"

ListComponent::ListComponent(ContainerComponent *parent) : Component(parent) {}

ListComponent::ListComponent(ContainerComponent *parent, int x, int y, int width, int height) : Component(parent, x, y, width, height) {}

list<string> ListComponent::getItems()
{
	return this->items;
}

void ListComponent::setItems(list<string> newItems)
{
	this->items = newItems;
}

void ListComponent::addItem(string s)
{
	this->items.push_back(s);
}

void ListComponent::removeItem(string s)
{
	this->items.remove(s);
}

void ListComponent::printItems()
{
	stringstream ss;
	ss << "ListComponent items: \n";
	for (auto &i : this->items)
	{
		ss << "- " << i << "\n";
	}
	cout << ss.str();
}

string ListComponent::getTypeString()
{
	return "ListComponent";
}

string ListComponent::toString()
{
	return Component::toString();
}

ListComponent::~ListComponent()
{
	cout << "LC destr \n";
}
