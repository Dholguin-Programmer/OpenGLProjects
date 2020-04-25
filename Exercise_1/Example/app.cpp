// C++ standard includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <thread>

// GLUT includes
#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Devices
// #include "DiegofiedWindow.h"

int main() 
{
    // Setup a static profile for now
    // I would probably try to set these values more with more intelligence 
    // vs just setting some static values here. Probably tie this into our build
    // system where based upon whichever target we are building against, we set
    // these values accordingly. 
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE); 

    // Open a window and create its OpenGL context
    GLFWwindow* window; // (In the accompanying source code, this variable is global for simplicity)
    window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    if (glfwInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do{
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear( GL_COLOR_BUFFER_BIT );

        // Draw nothing, see you in tutorial 2 !

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

}
    /* 
    In production, we would want to be doing a number of things concurrently
    although this isn't really needed given the limited scope of the assignment
    this is implemented to showcase that I am aware of the bottlenecks here.
    
    Some thinks we might want to fix going forward
        1) Do we want some sort of 'Device Manager' to handle the
           execution steps of each individual device on the hardware 

           Ex: SpecificDevice_1
            Launch Window Device first (hogs all cycles on thread 1)
            Launch Device_2 second (shares cycles on thread 2)
            Launch Device_3 third  (shared cycles on thread 2)

           Ex: SpecificDevice_2
            Launch Window Device first (hogs all cycles on thread 1)
            Launch Device_2 second (hogs all cycles on thread 2)
            Launch Device_3 third  (hogs all cycles on thread 3) 
    */

        // // Let's get our Diegofied window going!
        // std::unique_ptr<Window::Device::Diegofied> diegoWindow (new Window::Device::Diegofied());
        // diegoWindow->PrimeDevice();

        // // Blocking call
        // diegoWindow->StartDevice();

    // std::thread windowParallelThread ([]()
    // {
    //     // Let's get our Diegofied window going!
    //     std::unique_ptr<Window::Device::Diegofied> diegoWindow (new Window::Device::Diegofied());
    //     diegoWindow->PrimeDevice();

    //     // Blocking call
    //     diegoWindow->StartDevice();
    // });

    // windowParallelThread.detach();

    // // We'd start up over  devices here and then wait for everybody to either finish
    // // togather or wait for specific one's to finish up execution via stopping the device

    // windowParallelThread.join();

//     return 0;
// }