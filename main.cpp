#include "component.h"
#include "container_component.h"
#include "frame.h"
#include "label.h"
#include "button.h"
#include <iostream>
using namespace std;

void testFunc()
{
	cout << "heloooooooooo" << endl;
}

int main(int argc, char *argv[])
{
	ContainerComponent *cc = new ContainerComponent(nullptr);
	cc->resize(200, 200);
	Component *c1 = new Component(cc, 100, 100, 200, 200);
	ContainerComponent *c2 = new ContainerComponent(cc, 100, 100, 200, 200);
	c2->addChild(c1);
	// cc->addChild(cc);
	// cc->removeChild(c1);
	// delete c1;
	cout << cc->toString() << endl;
	cout << c2->toString() << endl;
	delete cc;

	Frame *f = new Frame(nullptr);

	Label *l = new Label(f, "hello");
	Button *b = new Button(f, &testFunc);

	cout << b->toString() << endl;
	b->disable();
	b->click();
	delete f;
	return 0;
}