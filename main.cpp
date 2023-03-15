#include "component.h"
#include "container_component.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	ContainerComponent cc(nullptr);
	Component *c = &cc;
	cout << c->toString() << endl;
	return 0;
}