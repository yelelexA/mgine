#pragma once

#include "mgine/MgineWindow.h"

namespace mgine
{
	class App
	{
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			void run();
		private:
			MgineWindow mgineWindow{WIDTH, HEIGHT, "Vulkan window"};
	};
}