#include "pch.h"
#include "MainWindow.xaml.h"
#include "DataItem.h"
#include "Program.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include <iomanip>
#include <sstream>
#include <string>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace
{
    std::wstring FormatDuration(int64_t milliseconds)
    {
        bool const negative = milliseconds < 0;
        if (negative)
        {
            milliseconds = -milliseconds;
        }

        int64_t const days = milliseconds / 86400000;
        milliseconds %= 86400000;
        int64_t const hours = milliseconds / 3600000;
        milliseconds %= 3600000;
        int64_t const minutes = milliseconds / 60000;
        milliseconds %= 60000;
        int64_t const seconds = milliseconds / 1000;
        int64_t const fractionTicks = (milliseconds % 1000) * 10000;

        std::wostringstream result;
        result << std::setfill(L'0');
        if (negative)
        {
            result << L'-';
        }
        if (days > 0)
        {
            result << days << L'.';
        }
        result << std::setw(2) << hours
               << L':' << std::setw(2) << minutes
               << L':' << std::setw(2) << seconds;
        if (fractionTicks != 0)
        {
            result << L'.' << std::setw(7) << fractionTicks;
        }

        return result.str();
    }
}

namespace winrt::App_WinUICpp::implementation
{
    MainWindow::MainWindow()
    {
        for (int32_t i = 0; i < 100000; ++i)
        {
            auto item = winrt::make<App_WinUICpp::implementation::DataItem>();
            item.Name(winrt::hstring{ std::wstring{ L"Item " } + std::to_wstring(i + 1) });
            m_items.Append(item);
        }
    }

    Windows::Foundation::Collections::IObservableVector<App_WinUICpp::DataItem> MainWindow::Items()
    {
        return m_items;
    }

    void MainWindow::Grid_Loaded([[maybe_unused]] Windows::Foundation::IInspectable const& sender, [[maybe_unused]] RoutedEventArgs const& e)
    {
        auto const milliseconds = App_WinUICpp::Program::StopStopWatch();
        std::wstring text = L"Launch time: ";
        text += FormatDuration(milliseconds);
        status().Text(winrt::hstring{ text });
    }
}
