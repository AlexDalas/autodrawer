using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
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
using System.Collections;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace AutoDrawer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            //X button
            System.Windows.Application.Current.Shutdown();
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            //Minimize button
            WindowState = WindowState.Minimized;
        }
        public void setConfig(int whichClicked, bool isRightClick)
        {
            //Config 1
            var env = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutoDraw\\config" + whichClicked.ToString() + ".info";
            var config1 = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutoDraw";
            if (isRightClick == true)
            {
                if (File.Exists(env))
                {
                    File.Delete(env);
                    using (StreamWriter sw = File.CreateText(env))
                    {
                        sw.WriteLine("interval: " + intervalInput.Text);
                        sw.WriteLine("clickdelay: " + clickdelayInput.Text);
                        sw.WriteLine("blackthreshold: " + blackThreshNumeric.Text);
                        sw.WriteLine("transparencythreshold: " + transThreshNumeric.Text);
                        sw.Close();
                    }
                }
                else
                {
                    try
                    {
                        Directory.CreateDirectory(config1);
                    }
                    catch { }
                    using (StreamWriter sw = File.CreateText(env))
                    {
                        sw.WriteLine("interval: " + intervalInput.Text);
                        sw.WriteLine("clickdelay: " + clickdelayInput.Text);
                        sw.WriteLine("blackthreshold: " + blackThreshNumeric.Text);
                        sw.WriteLine("transparencythreshold: " + transThreshNumeric.Text);
                        sw.Close();
                    }
                }

            }
            else
            {
                if (File.Exists(env))
                {
                    string[] a = File.ReadAllLines(env);
                    intervalInput.Text = a[0].Split(' ')[1];
                    clickdelayInput.Text = a[1].Split(' ')[1];
                    blackThreshNumeric.Text = a[2].Split(' ')[1];
                    transThreshNumeric.Text = a[3].Split(' ')[1];
                }
                else
                {
                    try
                    {
                        Directory.CreateDirectory(config1);
                    }
                    catch { }
                    using (StreamWriter sw = File.CreateText(env))
                    {
                        sw.WriteLine("interval: 10000");
                        sw.WriteLine("clickdelay: 1000");
                        sw.WriteLine("blackthreshold: 127");
                        sw.WriteLine("transparencythreshold: 200");
                        sw.Close();
                    }
                }
            }
        }

        private void OneConfigRight(object sender, MouseButtonEventArgs e)
        {//right click
            if (e.ChangedButton == MouseButton.Right) setConfig(1, true);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {//left click
            setConfig(1, false);
        }

        private void TwoConfigRight(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Right) setConfig(2, true);
        }
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            setConfig(2, false);
        }

        private void ThreeConfigRight(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Right) setConfig(3, true);
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            setConfig(3, false);
        }

    }
}
