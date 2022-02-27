using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace AutoDrawer
{
    /// <summary>
    /// Interaction logic for ConsoleWindow.xaml
    /// </summary>
    public partial class ConsoleWindow : Window
    {
        public static bool IsOpen;
        public static string LogText;

        private void UpdateLogs(object _, string text)
        {
            ListConsole.Text = LogText;
        }
        public ConsoleWindow()
        {
            InitializeComponent();
            ListConsole.Text = LogText;
            LogHandler.LogSent += UpdateLogs;
            IsOpen = true;
        }

        private void ConsoleClosed(object sender, EventArgs e)
        {
            LogHandler.LogSent -= UpdateLogs;
            IsOpen = false;
        }

        private void SaveConsole_Click(object sender, RoutedEventArgs e)
        {

        }

        private void CloseConsole_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void ClearConsole_Click(object sender, RoutedEventArgs e)
        {
            LogText = "";
            ListConsole.Text = LogText;
        }

        private void OpenConsole_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
