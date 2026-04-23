using Avalonia;
using System;
using System.Diagnostics;

namespace App_Avalonia;

class Program
{
    private static Stopwatch startupTimer = new Stopwatch();

    // Initialization code. Don't use any Avalonia, third-party APIs or any
    // SynchronizationContext-reliant code before AppMain is called: things aren't initialized
    // yet and stuff might break.
    [STAThread]
    public static void Main(string[] args)
    {
        startupTimer.Start();
        BuildAvaloniaApp()
            .StartWithClassicDesktopLifetime(args);
    }

    // Avalonia configuration, don't remove; also used by visual designer.
    public static AppBuilder BuildAvaloniaApp()
        => AppBuilder.Configure<App>()
            .UsePlatformDetect()
            .WithInterFont()
            .LogToTrace();

    public static long StopStopWatch()
    {
        startupTimer.Stop();
        return startupTimer.ElapsedMilliseconds;
    }
}