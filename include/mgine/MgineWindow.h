#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace mgine
{
	class MgineWindow
	{
		public:
			MgineWindow(int width, int height, std::string name);
			~MgineWindow();

			MgineWindow(const MgineWindow&) = delete;
			MgineWindow& operator=(const MgineWindow&) = delete;

			bool shouldClose() { return glfwWindowShouldClose(window); }

		private:
			void InitWindow();

			const int width;
			const int height;


			std::string name;
			GLFWwindow* window;
	};
}
