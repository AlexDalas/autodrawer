using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;

namespace AutoDrawer
{
    /// <summary>
    /// Interaction logic for Window3.xaml
    /// </summary>
    public partial class Window3 : Window
    {
        public static bool CursorOffset = false;
        public static bool CheckBoxCom = false;
        public static int xOffset = 0;
        public static int yOffset = 0;

        public Window3()
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
            CheckBoxCom = true;
            LogHandler.LogFile("\n----\nStarted Log\n----");
        }

        private void CheckBox_unChecked_2(object sender, RoutedEventArgs e)
        {
            MainWindow.CheckBoxCom = false;
            CheckBoxCom = false;
            LogHandler.LogFile("\n----\nEnded Log\n----");
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            MainWindow m = new MainWindow();
            m.LogFile("Opening Log Folder");
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
            Scc.IsChecked = CheckBoxCom;
            cursorBox.IsChecked = CursorOffset;
        }
    }
}
