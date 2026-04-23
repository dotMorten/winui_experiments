#include "pch.h"
#include "DataItem.h"
#if __has_include("DataItem.g.cpp")
#include "DataItem.g.cpp"
#endif

namespace winrt::App_WinUICpp::implementation
{
    winrt::hstring DataItem::Name()
    {
        return m_name;
    }

    void DataItem::Name(winrt::hstring const& value)
    {
        m_name = value;
    }
}
