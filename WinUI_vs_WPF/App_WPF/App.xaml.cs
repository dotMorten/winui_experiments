using System.Configuration;
using System.Data;
using System.Diagnostics;
using System.Windows;

namespace App_WPF
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }


    public static class Program
    {
        private static Stopwatch startupTimer = new Stopwatch();

        [System.STAThreadAttribute()]
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "10.0.6.0")]
        public static void Main()
        {
            startupTimer.Start();
            App_WPF.App app = new App_WPF.App();
            app.InitializeComponent();
            app.Run();
        }

        public static long StopStopWatch()
        {
            startupTimer.Stop();
            return startupTimer.ElapsedMilliseconds;
        }
    }

}
