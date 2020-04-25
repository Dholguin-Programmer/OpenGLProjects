import shlex
import subprocess
import getopt
import os
import sys

# Repo Name
PROJECT_NAME = "Assignment_1"

# Directory Relavent Variables
DMATH_ENGINE_SOURCE_DIR = os.path.dirname(os.path.realpath(__file__))
DMATH_ENGINE_BUILD_DIR = DMATH_ENGINE_SOURCE_DIR + "/.build/" + PROJECT_NAME

# TODO: Add linux support

def create_directory_if_not_exist(dirName):
     if not os.path.exists(dirName):
          os.makedirs(dirName)  

def build_windows(toolchain):
     create_directory_if_not_exist(DMATH_ENGINE_BUILD_DIR)
     
     # Right now we only have one target but use subprocess to future
     # proof our build process in a possible future cases where although
     # the target is the same, we might have different 'CARDS' of which
     # our executable will be ran on

     # Setup arguments we'll be passing into CMake
     cmake_arguments += " -S " + str(DMATH_ENGINE_SOURCE_DIR) # Specify Source Tree
     cmake_arguments += " -B " + str(DMATH_ENGINE_BUILD_DIR)  # Specify Buiild Tree

     subprocess.run(["cmake" + cmake_arguments], shell=True, cwd=DMATH_ENGINE_BUILD_DIR)
     # subprocess.run(["ninja"], shell=True, cwd=DMATH_ENGINE_BUILD_DIR)


def build_project(build_arguments):
     try:
          opts, args = getopt.getopt(build_arguments,"h")
     except getopt.GetoptError:
               print(__file__ + ': Failed to parse arguments')
               sys.exit(2)

     for opt, arg in opts:
          if opt == '-h':
               print("TODO: define valid arguments")
               sys.exit()

     # Here we would want to add different toolchains and integrate them into
     # the build process for cross compilation.
     #
     # For now we just assume our native platform (Windows) will be our target
     # as well.
     #
     # DummyToolchain serves to just hit this point home.. doesn't do anything
     build_windows("DummyToolchain.cmake")

if __name__ == "__main__":
     build_project(sys.argv[1:])
