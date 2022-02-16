using System;
using System.Collections.Generic;
using System.Diagnostics;
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
    /// Interaction logic for Window3.xaml
    /// </summary>
    public partial class Window3 : Window
    {
        public bool CursorOffset = false;
        public int xOffset = 0;
        public int yOffset = 0;
        public bool CheckBoxCom = false;
        public Window3()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
        int yNum = 0;
        int xNum = 0;

        public System.Drawing.Point Location { get; internal set; }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            //y
            try { 
                yNum = Convert.ToInt32(yNumeric.Text);
                yNum = int.Parse(yNumeric.Text);
                yOffset = yNum;
            }
            catch
            {}
        }

        private void TextBox_TextChanged_1(object sender, TextChangedEventArgs e)
        {
            //x
            try
            {
                xNum = Convert.ToInt32(xNumeric.Text);
                xNum = int.Parse(xNumeric.Text);
                xOffset = xNum;
            }
            catch
            {}
        }

        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {
            CursorOffset = (bool)cursorBox.IsChecked;
        }

        private void CheckBox_Checked_2(object sender, RoutedEventArgs e)
        {
            CheckBoxCom = (bool)Scc.IsChecked;
            if (CheckBoxCom) {
                MainWindow m = new MainWindow();
                m.LogFile("Started Log");
            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            var fpath = @"%AppData%\AutoDraw\";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            Process.Start(fpath);
        }
    }
}
