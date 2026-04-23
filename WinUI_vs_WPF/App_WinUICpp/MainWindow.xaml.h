#pragma once

#include "DataItem.h"
#include "MainWindow.g.h"

namespace winrt::App_WinUICpp::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        Windows::Foundation::Collections::IObservableVector<App_WinUICpp::DataItem> Items();
        void Grid_Loaded(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        Windows::Foundation::Collections::IObservableVector<App_WinUICpp::DataItem> m_items{
            winrt::single_threaded_observable_vector<App_WinUICpp::DataItem>()
        };
    };
}

namespace winrt::App_WinUICpp::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
