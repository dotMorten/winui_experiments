using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace App_WPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            DataContext = Enumerable.Range(0, 100000).Select(i => new DataItem { Name = $"Item {i + 1}" }).ToArray();
            InitializeComponent();
        }

        public class DataItem
        {
            public string? Name { get; set; }
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            var ms = Program.StopStopWatch();
            status.Text = "Launch time: " + TimeSpan.FromMilliseconds(ms).ToString();
        }
    }
}