using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
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
        public static string LogText;

        private void UpdateLogs(object _, string text)
        {
            ListConsole.Text = LogText;
        }
        public ConsoleWindow()
        {
            var windowcount = 0;
            foreach (var window in System.Windows.Application.Current.Windows)
                if (window.ToString() == "AutoDrawer.ConsoleWindow") windowcount++;
            if (windowcount > 1) this.Close();
            InitializeComponent();
            ListConsole.Text = LogText;
            LogHandler.LogSent += UpdateLogs;
            IsOpen = true;
            refTheme();
        }

        public void refTheme()
        {
            string cpath = Environment.ExpandEnvironmentVariables("%AppData%\\AutoDraw");
            var thm = File.ReadAllLines(cpath + "\\themes\\theme.txt");
            string jsonFile = cpath + "\\themes\\" + thm[0] + ".drawtheme";
            using (StreamReader file = File.OpenText(jsonFile))
            using (JsonTextReader reader = new JsonTextReader(file))
            {
                JObject json = (JObject)JToken.ReadFrom(reader);
                BrushConverter bc = new BrushConverter();
                label.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["text"].ToString());
                ListConsole.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["text"].ToString());
                //close.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["close"].ToString());
                BKG.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["background"].ToString());
                BKG2.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["console-background"].ToString());
                save.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["button"].ToString());
                clear.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["button"].ToString());
                open.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["button"].ToString());
                save.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["text"].ToString());
                clear.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["text"].ToString());
                open.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["text"].ToString());
                close.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["console"]["text"].ToString());

            }
        }

        private void ConsoleClosed(object sender, EventArgs e)
        {
            LogHandler.LogSent -= UpdateLogs;
            IsOpen = false;
        }

        private void SaveConsole_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.SaveFileDialog
            {
                Title = "Where do you want to save your log?",
                Filter = "Log (*.log)|*.log"
            };
            if (dialog.ShowDialog() == true)
            {
                var fileName = dialog.FileName;
                LogHandler.LogFile("Saving " + dialog.FileName);
                File.WriteAllText(fileName, ListConsole.Text);
            }
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
            var fpath = @"%AppData%\AutoDraw\logs\";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            Process.Start("explorer.exe", fpath);
        }
    }
}
