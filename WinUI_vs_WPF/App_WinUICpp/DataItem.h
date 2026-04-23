#pragma once

#include "DataItem.g.h"

namespace winrt::App_WinUICpp::implementation
{
    struct DataItem : DataItemT<DataItem>
    {
        DataItem() = default;

        winrt::hstring Name();
        void Name(winrt::hstring const& value);

    private:
        winrt::hstring m_name;
    };
}

namespace winrt::App_WinUICpp::factory_implementation
{
    struct DataItem : DataItemT<DataItem, implementation::DataItem>
    {
    };
}
