find_package(OpenGL REQUIRED)
set(target_name myapp)

add_executable(${target_name} app.cpp)

target_link_libraries(${target_name}
	# Window::Diegofied
	glfw 
	OpenGL::GL)

assignment_install(${target_name})