Quick comparisons of a simple WinUI app with WPF.

Both C++ and .NET versions of WinUI available. Make sure you run in Release build with debugging disabled. When testing startup time, ignore first run to skip  and run it a few times.

Also note that if running on ARM64, that [there's a memory issue for WPF](https://github.com/dotnet/wpf/issues/8306) making it look even worse for WPF.
