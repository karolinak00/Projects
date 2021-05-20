#include "Menu.h"

int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Menu menu;
	while (menu.is_running())
	{
		menu.update();
		menu.render();
	}

	return 0;
}
