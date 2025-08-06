#include "mgine/app/App.h"

namespace mgine
{
	void App::run()
	{
		while (!mgineWindow.shouldClose())
		{
			glfwPollEvents();
		}
	}
}