find_package(OpenGL REQUIRED)

set(target_name Diegofied)
add_library(${target_name} STATIC)
add_library(Window::${target_name} ALIAS ${target_name})

target_include_directories(${target_name}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(${target_name}
	PRIVATE
		src/DiegofiedWindow.cpp
)

target_link_libraries(${target_name}
	glfw 
	OpenGL::GL
	Window::Base
)

assignment_install(${target_name})