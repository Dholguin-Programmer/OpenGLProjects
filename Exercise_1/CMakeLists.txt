cmake_minimum_required(VERSION 3.11)
project(OpenGL_Project_1 VERSION 1.0 LANGUAGES C CXX)
string(TOUPPER ${CMAKE_PROJECT_NAME} UPPER_PROJECT_NAME)
string(TOLOWER ${CMAKE_PROJECT_NAME} LOWER_PROJECT_NAME)

################################################################################
# Fetch toolchain from environment variable (TODO: Provide different toolchains)
set(CMAKE_CXX_COMPILER $ENV{TARGET_COMPILER_CXX})
set(CMAKE_C_COMPILER $ENV{TARGET_COMPILER_C})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

################################################################################
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include(AssureOutOfSourceBuild)
include(install-helpers)

################################################################################
add_subdirectory(3rdPartyLibs/glfw)
add_subdirectory(Devices/Window)
add_subdirectory(Example)