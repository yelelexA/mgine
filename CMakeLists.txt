cmake_minimum_required(VERSION 4.1)
set(PROJECT_NAME mgine)
project (${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

# //////////////////////////////////////////////////////
# external_libs
# //////////////////////////////////////////////////////

find_package(Vulkan REQUIRED)

add_subdirectory(modules)

# //////////////////////////////////////////////////////
# main library
# //////////////////////////////////////////////////////

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
		PUBLIC include
		PUBLIC ${Vulkan_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME}
		${Vulkan_LIBRARY}
		glfw
		glm
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)