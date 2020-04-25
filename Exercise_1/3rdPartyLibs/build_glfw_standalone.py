# Imports
import shutil
import shlex
import subprocess
import getopt
import os
import sys

LABEL=os.path.basename(__file__)
CWD = os.getcwd()
GLFW_SRC_DIR = CWD + '/glfw'
GLFW_BUILD_DIR = CWD + '/glfw-build-tree'

def create_directory_if_not_exist(dirName):
     if not os.path.exists(dirName):
          os.makedirs(dirName)  

def build_glfw_build_tree_linux():
    print(LABEL + ' ------> Install GLFW')
    process = subprocess.run(["make"], shell=True, cwd=GLFW_BUILD_DIR)

def create_glfw_build_tree():
    # Right now we only are only ever going to create a single build tree, but in
    # case we'd like to try a number of different build tree using a number of specifc
    # build definitions that GLFW provides, we can think about extending python's
    # subprocess module to define different arguments with different build dirs
    #
    # Think: glfw-debug-build-tree -> Installs a version of GLFW with debug enabled
    #        glfw-test-build-tree  -> Install a version of GLFW with extensive debug

    create_directory_if_not_exist(GLFW_BUILD_DIR)

    # Specify different build configurations
    # TODO: Create a series of environment variable and import them here
    glfw_build_definitions = "-DBUILD_SHARED_LIBS=ON"

    cmake_arguments = glfw_build_definitions
    cmake_arguments += " -S" + str(GLFW_SRC_DIR)    # Specify Source Tree
    cmake_arguments += " -B" + str(GLFW_BUILD_DIR)  # Specify Buiild Tree
    # Don't specify toolchain, Use Native System Compiler (GCC/G++)

    # Note that 'run' will wait for process to end...
    print(LABEL + ' ------> Generating GLFW out-of-source build tree')
    process = subprocess.run(["cmake " + cmake_arguments], shell=True, cwd=CWD)

    # How would we want to handle this? How about we shoot an email to the last
    # person who touched the file :) 
    if process.returncode == 0:
        print ('Successfully generated GLFW build tree')
    else:
        print('Failed to generated GLFW build tree')

if __name__ == "__main__":
    create_glfw_build_tree()
    build_glfw_build_tree_linux()