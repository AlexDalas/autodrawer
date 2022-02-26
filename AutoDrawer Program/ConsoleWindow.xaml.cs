using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
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

        public ConsoleWindow()
        {
            InitializeComponent();
            IsOpen = true;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void ConsoleClosed(object sender, EventArgs e)
        {
            IsOpen = false;
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {

            LogHandler.LogFile("Opening Log Folder");
            var fpath = @"%AppData%\AutoDraw\logs\";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            Process.Start(fpath);
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.SaveFileDialog();
            dialog.Title = "Where do you want to save your logs?";
            dialog.Filter = "Log File (*.log)|*.log";
            if (dialog.ShowDialog() == true)
            {
                var fileName = dialog.FileName;
                LogHandler.LogFile("Saving " + dialog.FileName);
                File.WriteAllText(fileName, ListConsole.Text.Replace("Welcome to the Console! This is a live feed of your logs.", ""));
            }
        }
    }
}
