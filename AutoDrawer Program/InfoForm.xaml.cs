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
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace AutoDrawer
{
    /// <summary>
    /// Interaction logic for Window2.xaml
    /// </summary>
    public partial class Window2 : Window
    {
        public Window2()
        {
            InitializeComponent();
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
                t1.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["info"]["text"].ToString());
                t2.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["info"]["text"].ToString());
                t3.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["info"]["text"].ToString());
                t4.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["info"]["text"].ToString());
                close.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["info"]["text"].ToString());
                close.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["info"]["close"].ToString());
                grid.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["info"]["background"].ToString());
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
