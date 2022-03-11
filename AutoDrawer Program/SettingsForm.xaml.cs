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
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

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
            var windowcount = 0;
            foreach (var window in System.Windows.Application.Current.Windows)
                if (window.ToString() == "AutoDrawer.SettingsWindow") windowcount++;
            if (windowcount > 1) this.Close();
            InitializeComponent();
            refTheme();
            additemstolistbox();
            string cpath = Environment.ExpandEnvironmentVariables("%AppData%\\AutoDraw");
            var thm = File.ReadAllLines(cpath + "\\themes\\theme.txt");
            foreach (object item in Combox.Items)
            {
                if (item.ToString() == thm[0])
                {
                    Combox.SelectedItem = (item);
                }
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
        public void refTheme()
        {
            BrushConverter bc = new BrushConverter();
            string cpath = Environment.ExpandEnvironmentVariables("%AppData%\\AutoDraw");
            var thm = File.ReadAllLines(cpath + "\\themes\\theme.txt");
            string jsonFile = cpath + "\\themes\\" + thm[0] + ".drawtheme";
            using (StreamReader file = File.OpenText(jsonFile))
            using (JsonTextReader reader = new JsonTextReader(file))
            {
                JObject json = (JObject)JToken.ReadFrom(reader);
                if (json["light-icons"].ToString() == "true")
                {
                    img.Source = new BitmapImage(new Uri("/Assets/RefreshIcon_Light.png", UriKind.Relative));
                }
                else
                {
                    img.Source = new BitmapImage(new Uri("/Assets/RefreshIcon.png", UriKind.Relative));
                }
                BKG.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["background"].ToString());
                Title.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                SendLogs.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                OpenThemes.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                Themetext.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                offsetText1.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                OpenConsole.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                ManageTheme.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                OpenLogs.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                GH.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                LR.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                DC.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                Scc.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                xNumeric.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                yNumeric.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                xT.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                yT.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                cursorBox.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                LogsText.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                CloseB.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["text"].ToString());
                CloseB.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                DC.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                LR.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                GH.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                OpenLogs.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                ManageTheme.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                OpenConsole.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                SendLogs.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["buttons"].ToString());
                LogsText.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["textbox"].ToString());
                cursorBox.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["checkbox-box"].ToString());
                xNumeric.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["textbox"].ToString());
                yNumeric.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["settings"]["textbox"].ToString());
            }
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
            try { 
                ConsoleWindow cw = new ConsoleWindow();
                cw.Show();
                this.Close();
            }catch{}
        }

        private void OpenLogs_Click(object sender, RoutedEventArgs e)
        {
            var fpath = @"%AppData%\AutoDraw\logs\";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            Process.Start("explorer.exe", fpath);
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var cpath = @"%AppData%\AutoDraw\themes\";
            cpath = Environment.ExpandEnvironmentVariables(cpath);
            string selectedText = (string)Combox.SelectedItem;
            Console.WriteLine(selectedText);
            File.WriteAllText(cpath + "\\theme.txt", selectedText);
            RefreshAllThemes();
        }
        void additemstolistbox()
        {
            string fpath = Environment.ExpandEnvironmentVariables("%AppData%\\AutoDraw\\themes");
            string[] allfiles = Directory.GetFiles(fpath, "*.*", SearchOption.AllDirectories);
            foreach (var file in allfiles)
            {
                if (file.EndsWith(".drawtheme"))
                if (file.EndsWith(".drawtheme"))
                    Combox.Items.Add(file.Replace(fpath, "").Replace(".drawtheme", "").Replace("\\", ""));
            }
        }
        void RefreshAllThemes()
        {
            refTheme();
            (System.Windows.Application.Current.MainWindow as MainWindow).refreshTheme();
        }

        private void OpenThemesEX(object sender, RoutedEventArgs e)
        {
            var fpath = @"%AppData%\AutoDraw\themes\";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            Process.Start("explorer.exe", fpath);
        }

        private void OpenThemes_Copy_Click(object sender, RoutedEventArgs e)
        {
            RefreshAllThemes();
        }

        private void ManageTheme_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
            Process.Start("https://media.discordapp.net/attachments/849108988753870848/951468516719087656/giphy_-_2020-08-11T154625.780.gif");
        }
    }
}
