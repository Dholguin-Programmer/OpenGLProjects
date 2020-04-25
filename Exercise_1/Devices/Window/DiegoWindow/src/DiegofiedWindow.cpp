// System includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// 3rd Party includes
#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Device includes
#include "DiegofiedWindow.h"

using namespace Window::Device;

////////////////////////////////////////////////////////////////////////////////
Diegofied::Diegofied()
: Base(1024, 1024, "Diegofied Window", nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
void Diegofied::PrimeDevice()
{
    // Setup a static profile for now
    // I would probably try to set these values more with more intelligence 
    // vs just setting some static values here. Probably tie this into our build
    // system where based upon whichever target we are building against, we set
    // these values accordingly. 
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE); 
}

////////////////////////////////////////////////////////////////////////////////
bool Diegofied::StartDevice()
{
    m_deviceRunning = true;

    m_windowObj = glfwCreateWindow(m_winWidth, m_winHeight, m_winName, m_monitorObj, NULL);

    glfwMakeContextCurrent(m_windowObj); // Initialize GLEW
    //glewExperimental = GL_TRUE; // Use core profile
    if( !glfwInit() )
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        m_deviceRunning = false;
        return 0;
    }

    // // This would also be determined at either build time (compiler definition) 
    // // or in source via some intelligence. If more time, I'd probably create a 
    // // 'InputDevice' or something...
    glfwSetInputMode(m_windowObj, GLFW_STICKY_KEYS, GL_TRUE);

    bool keepDrawing = !ExitPolicySatisfied(); 
    while(keepDrawing)
    {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear( GL_COLOR_BUFFER_BIT );

        // Draw nothing, see you in tutorial 2 !
        std::cout << "Drawing something soon!" << std::endl;

        // Swap buffers
        glfwSwapBuffers(m_windowObj);
        glfwPollEvents();

        keepDrawing = !ExitPolicySatisfied(); 
        if (keepDrawing)
        {
            continue;
        }
        else
        {
            std::cout << "Stoping the drawing process" << std::endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void Diegofied::StopDevice()
{
    m_deviceRunning = false;
}

////////////////////////////////////////////////////////////////////////////////
bool Diegofied::ExitPolicySatisfied()
{
    // Here I'd also try to create either some sort of policy for our exit conditions,
    // as this might be something that differs across vendors... Just a thought

    bool exitPolicySatisfied = true;

    exitPolicySatisfied &= glfwWindowShouldClose(m_windowObj) == 0;  // Exit if flag was set
    exitPolicySatisfied &= glfwGetKey(m_windowObj, GLFW_KEY_ESCAPE); // Exit if escape key is pressed
    exitPolicySatisfied &= !m_deviceRunning;                         // Exit if device is not running
}

////////////////////////////////////////////////////////////////////////////////
void Diegofied::HandleWindowResize(WindowObject* window, int width, int height)
{
    m_winWidth = width;
    m_winHeight = height;
}
