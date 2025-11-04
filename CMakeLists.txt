cmake_minimum_required(VERSION 4.1)
set(PROJECT_NAME mgine)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

# set cpp std=c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# //////////////////////////////////////////////////////
# external_libs
# //////////////////////////////////////////////////////

# including Vulkan
find_package(Vulkan REQUIRED)

add_subdirectory(modules)

# //////////////////////////////////////////////////////
# main library
# //////////////////////////////////////////////////////

add_library(${PROJECT_NAME} STATIC
	include/mgine/MgineWindow.h
	src/mgine/MgineWindow.cpp
	include/mgine/MginePipeline.h
	src/mgine/MginePipeline.cpp
)

target_include_directories(${PROJECT_NAME}
	PUBLIC include
	PUBLIC ${Vulkan_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
	${Vulkan_LIBRARY}
	glfw
	glm
)

set(EDITOR_EXE_NAME ${PROJECT_NAME}_editor)

add_executable(${EDITOR_EXE_NAME}
	src/main.cpp
	include/mgine/app/App.h
	src/mgine/app/App.cpp
)

target_link_libraries(${EDITOR_EXE_NAME} ${PROJECT_NAME})