#pragma once

// Includes
#include <cstdint>

// Forward declarations
class GLFWmonitor;
class GLFWwindow;

namespace Window
{
    namespace Device
    {
        /* 
            Important Notes
            -----------------
            - In an ideal world, we'd have a class below that maps to whatever
              our Graphics API (OpenGl, Vulkin, etc) deems as a 'monitor' and 
              extend this functionality to our own Window Devices. Seeing as
              I have a very close coupling with my Graphics API (OPENGL), I'll typedef
              these away for now, but in production, we ought to have some 
              macros that resolve these 'types' to their respective Graphics API
        */

        typedef GLFWmonitor MonitorObject;
        typedef GLFWwindow WindowObject;

        // This could be handled more gracefully, say actually have some intelligence
        // about what platform I'm porting too and whether this is deemed 'acceptaple' memory wise
        typedef uint16_t WindowDimensionsType;
        typedef uint8_t UuidType;

        class Base
        {
            public:
                Base(WindowDimensionsType width, WindowDimensionsType height,
                     const char* name, MonitorObject* monitor = nullptr);
                virtual ~Base();
                
                // With more time, I probably create a common device of some sorts..
                virtual void PrimeDevice() = 0;
                virtual bool StartDevice() = 0;
                virtual void StopDevice() = 0;

                virtual void HandleWindowResize(WindowObject* window, int width, int height) = 0;

                // This is done intentionally to save time. In production, you'd stub out
                // any other functions, but seeing as I won't be using all of them, will
                // leave raw pointer accessible publically so I can get this assignment finish
                // and not over design this given it's scope.
                WindowObject* m_windowObj;

            protected:
                bool m_deviceRunning;
                WindowDimensionsType m_winWidth;
                WindowDimensionsType m_winHeight;
                const char* m_winName;
                MonitorObject* m_monitorObj;
            private:
                virtual bool ExitPolicySatisfied() = 0;
        };
    }
}