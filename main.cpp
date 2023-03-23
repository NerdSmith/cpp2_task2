#include "component.h"
#include "container_component.h"
#include "frame.h"
#include "label.h"
#include "button.h"
#include "list_component.h"
#include "panel.h"
#include "env_frame.h"
#include "windows_service.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void testFunc(Component *sender)
{
	Button *c = dynamic_cast<Button *>(sender);
	if (c)
	{
		cout << c->getText() << endl;
	}
}

void tokenize(std::string const &str, const char delim,
			  std::vector<std::string> &out)
{
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim))
	{
		out.push_back(s);
	}
}

int main(int argc, char *argv[])
{
	WindowsService *windowsService = new WindowsService(new EnvFrame());
	windowsService->addPanel(100, 100, 500, 500);
	windowsService->toChild(0);
	windowsService->addButton("btext", 50, 50, 100, 50, &testFunc);
	windowsService->backToParent();
	windowsService->moveComponent(50, 50);
	while (1)
	{
		std::string line;
		cout << "{" << windowsService->getCurrCompStr() << "} : ";
		std::getline(std::cin, line);

		if (line == "exit")
		{
			break;
		}
		else if (line == "tree")
		{
			windowsService->printTree();
		}
		else if (line.rfind("cd", 0) == 0)
		{
			vector<string> out;
			tokenize(line, ' ', out);
			if (out.at(1) == "..")
			{
				windowsService->backToParent();
			}
			else
			{
				windowsService->toChild(stoi(out.at(1)));
			}
		}
		else if (line.rfind("add", 0) == 0)
		{
			vector<string> out;
			tokenize(line, ' ', out);
			if (out.at(1) == "button")
			{
				windowsService->addButton(out.at(2), stoi(out.at(3)), stoi(out.at(4)), stoi(out.at(5)), stoi(out.at(6)), &testFunc);
			}
			else if (out.at(1) == "panel")
			{
				windowsService->addPanel(stoi(out.at(2)), stoi(out.at(3)), stoi(out.at(4)), stoi(out.at(5)));
			}
		}
		else if (line.rfind("click", 0) == 0)
		{
			vector<string> out;
			tokenize(line, ' ', out);
			windowsService->userClick(stoi(out.at(1)), stoi(out.at(2)));
		}
		else if (line.rfind("move", 0) == 0)
		{
			vector<string> out;
			tokenize(line, ' ', out);
			windowsService->moveComponent(stoi(out.at(1)), stoi(out.at(2)));
		}
	}

	delete windowsService;
	// ContainerComponent *cc = new ContainerComponent(nullptr);
	// cc->resize(200, 200);
	// Component *c1 = new Component(cc, 100, 100, 200, 200);
	// ContainerComponent *c2 = new ContainerComponent(cc, 100, 100, 200, 200);
	// c2->addChild(c1);
	// // cc->addChild(cc);
	// // cc->removeChild(c1);
	// // delete c1;
	// cout << cc->toString() << endl;
	// cout << c2->toString() << endl;
	// delete cc;

	// Frame *f = new Frame();

	// Label *l = new Label(f, "hello");
	// Button *b = new Button(f, &testFunc);

	// cout << b->toString() << endl;
	// b->disable();
	// b->click();

	// ListComponent *lc = new ListComponent(f);
	// lc->addItem("item1");
	// lc->addItem("item2");
	// lc->addItem("item3");
	// lc->printItems();

	// Panel *p = new Panel(f);
	// cout << p->toString() << endl;
	// Button *b10 = new Button(f, []()
	// 						 { cout << "btn clk"
	// 								<< endl; });
	// b10->click();

	// delete f;
	return 0;
}