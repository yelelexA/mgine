#include "mgine/MgineWindow.h"

namespace mgine
{
	MgineWindow::MgineWindow(int width, int height, std::string name) : width{ width }, height{ height }, name{ name }
	{
		InitWindow();
	}

	MgineWindow::~MgineWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void MgineWindow::InitWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
	}
}