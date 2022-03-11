using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace AutoDrawer
{
    /// <summary>
    /// Interaction logic for PathSeqForm.xaml
    /// </summary>
    public partial class PathSeqForm : Window
    {
        public static int pathInt;
        string input;
        public bool allowed;

        public PathSeqForm()
        {
            InitializeComponent();
            refTheme();
            if (!MainWindow.pathIntAllowed)
            {
                submitButton.Content = "Submit / Enable";
            }
            else
            {
                submitButton.Content = "Submit";
            }
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
                label.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                pathInput.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["textbox"].ToString());
                pathInput.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                submitButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                submitButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["button"].ToString());
                CloseBox.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["close"].ToString());
                CloseBox.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                BKG.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["background"].ToString());
                BKG2.Fill = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["image-background"].ToString());
                textOuter.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t1.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t2.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t3.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t4.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t5.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t6.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t7.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
                t8.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["pattern"]["text"].ToString());
            }
        }

        private void pathInput_TextChanged(object sender, EventArgs e)
        {
            input = pathInput.Text;
        }

        private void enterButton_Click(object sender, EventArgs e)
        {
            try
            {
                try
                {
                    pathInt = Convert.ToInt32(input);
                    pathInt = int.Parse(input);
                }
                catch{
                    throw new Exception();
                }
                if (pathInt.ToString().Length < 8)
                    throw new Exception();
                var digits = pathInt.ToString().Select(t => int.Parse(t.ToString())).ToArray();
                foreach (int item in digits)
                {
                    if (item == 9 | item == 0)
                    {
                        throw new Exception();
                    }
                }
                MainWindow.pathInt = pathInt;
                MainWindow.pathIntAllowed = false;
                Close();
            }
            catch (Exception)
            {
                if (!MainWindow.pathIntAllowed)
                {
                    enableDrawP();
                    MainWindow m = new MainWindow();
                    LogHandler.LogFile("Enabled custom drawing pattern "+pathInput.Text);
                }
                else
                {
                    System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Please enter a sequence of 8 integers from 1-8", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    MainWindow m = new MainWindow();
                    LogHandler.LogFile("User did not enter a sequence from 8 integers.");
                    MainWindow.pathIntAllowed = true;
                }
            }
        }
        public void enableDrawP()
        {
            System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Enabled the drawing pattern!", "Enabled!", MessageBoxButtons.OK, MessageBoxIcon.None);
            MainWindow m = new MainWindow();
            LogHandler.LogFile("Enabled Drawing Pattern!");
            MainWindow.pathIntAllowed = true;
            submitButton.Content = "Submit";
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
