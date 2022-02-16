using System;
using System.Collections.Generic;
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
            if (!MainWindow.pathIntAllowed)
            {
                submitButton.Content = "Submit / Enable";
            }
            else
            {
                submitButton.Content = "Submit";
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
                    
                }
                else
                {
                    System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Please enter a sequence of 8 integers from 1-8", "Input Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    MainWindow.pathIntAllowed = true;
                }
            }
        }
        public void enableDrawP()
        {
            System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Enabled the drawing pattern!", "Enabled!", MessageBoxButtons.OK, MessageBoxIcon.None);
            MainWindow.pathIntAllowed = true;
            submitButton.Content = "Submit";
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
