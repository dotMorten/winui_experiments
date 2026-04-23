using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace App_WinUI
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            Items = Enumerable.Range(0,100000).Select(i => new DataItem { Name = $"Item {i + 1}" }).ToArray();
            InitializeComponent();
        }
        public DataItem[] Items { get; }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            var ms = Program.StopStopWatch();
            status.Text = "Launch time: " + TimeSpan.FromMilliseconds(ms).ToString();
        }
    }

    public partial class DataItem
    {
        public string? Name { get; set; }
    }
}
