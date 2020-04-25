#include "WindowBase.h"

using namespace Window::Device;

////////////////////////////////////////////////////////////////////////////////
Base::Base(WindowDimensionsType width, WindowDimensionsType height,
           const char* name, MonitorObject* monitor)
: m_deviceRunning(false),
  m_winWidth(width),
  m_winHeight(height),
  m_winName(name),
  m_monitorObj(monitor),
  m_windowObj(nullptr)
{
    // Nothing common for now.. 
}

////////////////////////////////////////////////////////////////////////////////
Base::~Base()
{
    // Maybe we might want to come some common behavior here?
    // For now I'm treating this class more like a light-weight
    // struct that is enforcing behavior via inheritance
}
