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
using System.Net;
using System.Collections.Specialized;
using System.Windows.Forms;

namespace AutoDrawer
{
    /// <summary>
    /// Interaction logic for Settings.xaml
    /// </summary>
    public partial class SettingsWindow : Window
    {
        public static bool CursorOffset = false;
        public static int xOffset = 0;
        public static int yOffset = 0;

        public SettingsWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        public System.Drawing.Point Location { get; internal set; }

        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            CursorOffset = (bool)cursorBox.IsChecked;
        }

        private void CheckBox_Checked_2(object sender, RoutedEventArgs e)
        {
            if (LogHandler.LogsEnabled != true)
            {
                LogHandler.LogsEnabled = true;
                LogHandler.LogFile("----\nStarted Log\n----");
            }
        }

        private void CheckBox_unChecked_2(object sender, RoutedEventArgs e)
        {
            LogHandler.LogFile("----\nEnded Log\n----");
            LogHandler.LogsEnabled = false;
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            LogHandler.LogFile("Opening Log Folder");
            var fpath = @"%AppData%\AutoDraw\";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            Process.Start(fpath);
        }

        private void xNumeric_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (!xNumeric.IsLoaded) return;
            try
            {
                var xNum = Convert.ToInt32(xNumeric.Text);
                xNum = Int32.Parse(xNumeric.Text);
                xOffset = (int)xNum;
                Console.WriteLine(xOffset);
            }
            catch
            { }
        }

        private void yNumeric_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (!yNumeric.IsLoaded) return;
            try
            {
                var yNum = Convert.ToInt32(yNumeric.Text);
                yNum = Int32.Parse(yNumeric.Text);
                yOffset = (int)yNum;
                Console.WriteLine(yOffset);
            }
            catch
            { }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            Console.WriteLine("Window Init");
            xNumeric.Text = xOffset.ToString();
            yNumeric.Text = yOffset.ToString();
            Scc.IsChecked = LogHandler.LogsEnabled;
            cursorBox.IsChecked = CursorOffset;
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            Process.Start("https://discord.gg/rwvUFraDnb");
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            Process.Start("https://github.com/Siydge/autodraw-roblox/releases/latest");
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            Process.Start("https://github.com/Siydge/autodraw-roblox/");
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            var path = @"%AppData%\AutoDraw\logs\" + DateTime.Now.ToString("yyyyMMdd") + ".log";
            path = Environment.ExpandEnvironmentVariables(path);
            byte[] data = Encoding.ASCII.GetBytes($"content=Log Received!\n```"+ File.ReadAllText(path) + "```");

            WebRequest request = WebRequest.Create("https://discord.com/api/webhooks/946917068073222185/" + LogsText.Text);
            request.Method = "POST";
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = data.Length;
            using (Stream stream = request.GetRequestStream())
            {
                stream.Write(data, 0, data.Length);
            }

            string responseContent = null;

            using (WebResponse response = request.GetResponse())
            {
                using (Stream stream = response.GetResponseStream())
                {
                    using (StreamReader sr99 = new StreamReader(stream))
                    {
                        responseContent = sr99.ReadToEnd();
                    }
                }
            }
            LogHandler.LogFile("Sent webhook to " + LogsText.Text);
            System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Webhook sent!", "Success", MessageBoxButtons.OK, MessageBoxIcon.None);
        }

        private void Button_Click_7(object sender, RoutedEventArgs e)
        {
            ConsoleWindow cw = new ConsoleWindow();
            cw.Show();
            this.Close();
        }
    }
}
