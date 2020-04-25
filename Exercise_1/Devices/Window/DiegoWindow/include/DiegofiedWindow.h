#pragma once

#include "WindowBase.h"

namespace Window
{
    namespace Device
    {
        class Diegofied : public Window::Device::Base
        {
            public:
                Diegofied();
                ~Diegofied() = default;

                // From Window::Device::Base
                void PrimeDevice() override;
                bool StartDevice() override;
                void StopDevice()  override;
                void HandleWindowResize(WindowObject* window, int width, int height) override;

            private:
                bool ExitPolicySatisfied();
        };
    }
}