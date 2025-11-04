#pragma once

#include "mgine/MginePipeline.h"
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
			// TODO: fixed absolute pathes
			MginePipeline mginePipeline{"D:/Projects/mgine/src/shaders/simple_shader.vert.spv", "D:/Projects/mgine/src/shaders/simple_shader.frag.spv"};
	};
}