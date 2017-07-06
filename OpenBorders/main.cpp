#include "Application.h"
#include "Component.h"
#include "System.h"
#include <iostream>
#include <Box2D.h>

class subComp : public ob::Component<subComp>
{
public:
	subComp() {};
	~subComp() {};
};

class subSystem : public ob::System<subComp>
{
public:
	subSystem() {};
	~subSystem() {};

	void update() {};
	void coutComps() { std::cout << "Count:" << components.size() << std::endl; };
};

int main()
{
	//FreeConsole();
	std::shared_ptr<subSystem> subSys = std::make_shared<subSystem>();
	std::vector<ob::Application> apps;
	bool done = false;
	while (!done)
	{
		char in;
		std::cin >> in;
		if (in == 'n')
		{
			apps.push_back(ob::Application{});
			apps.back().addComponent(std::make_shared<subComp>());
		}
		std::cout << std::endl;
		subSys->coutComps();
	}
	return 0;
}