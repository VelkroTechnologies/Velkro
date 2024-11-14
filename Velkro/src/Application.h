#pragma once

#include <iostream>
#include <string>

#include "Log.h"

namespace Velkro
{
    enum ExitCode
    {
        Success, Exit, Error
    };

    typedef ExitCode (*EntrypointFunction)();
    typedef ExitCode (*LoopFunction)();
    typedef ExitCode (*ExitpointFunction)();

    class Application
    {
    public:
        void Initialize(EntrypointFunction entrypoint, LoopFunction loop, ExitpointFunction exitpoint);

    private:
        bool m_Running = true;
    };
}