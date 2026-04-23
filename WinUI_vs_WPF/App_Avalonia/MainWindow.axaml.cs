using System;
using System.Linq;
using Avalonia.Controls;
using Avalonia.Interactivity;

namespace App_Avalonia;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        DataContext = Enumerable.Range(0, 100000).Select(i => new DataItem { Name = $"Item {i + 1}" }).ToArray();
        InitializeComponent();
    }

    private void Grid_Loaded(object? sender, RoutedEventArgs e)
    {
        var ms = Program.StopStopWatch();
        status.Text = "Launch time: " + TimeSpan.FromMilliseconds(ms).ToString();
    }
}

public class DataItem
{
    public string? Name { get; set; }
}