#include "pch.h"
#include "App.xaml.h"
#include "Program.h"

#include <chrono>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace
{
    using StartupClock = std::chrono::steady_clock;

    StartupClock::time_point startupTimerStart;
    bool startupTimerRunning = false;
}

namespace winrt::App_WinUICpp::Program
{
    void StartStopWatch()
    {
        startupTimerStart = StartupClock::now();
        startupTimerRunning = true;
    }

    int64_t StopStopWatch()
    {
        if (!startupTimerRunning)
        {
            return 0;
        }

        startupTimerRunning = false;
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            StartupClock::now() - startupTimerStart).count();
    }
}

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    winrt::App_WinUICpp::Program::StartStopWatch();
    winrt::init_apartment(winrt::apartment_type::single_threaded);
    Application::Start(
        [](auto&&)
        {
            winrt::make<winrt::App_WinUICpp::implementation::App>();
        });

    return 0;
}
