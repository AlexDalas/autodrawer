using System;
using System.Drawing;
using System.IO;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Media.Imaging;

namespace AutoDrawer
{
    /// <summary>
    /// Interaction logic for PreviewForm.xaml
    /// </summary>
    public partial class PreviewForm : Window
    {
        Bitmap imagePreview = MainWindow.imagePreview;


        public PreviewForm()
        {
            //This errors out for some reason, need fix
            //this one errors because the class names are not the same. When they are the same, it all breaks
            InitializeComponent();
            App.Current.MainWindow.Topmost = true;
            if (imagePreview.Width < 300)
            {
                CenterPictureBox(pictureBox1, imagePreview, true);
            }
            else
            {
                CenterPictureBox(pictureBox1, imagePreview, false);
            }
        }
        private void CenterPictureBox(System.Windows.Controls.Image picBox, Bitmap picImage, bool u3)
        {
            picBox.Source = ConvertBitmap(picImage);
            picBox.Height = picImage.Height+21;
            this.Height = picImage.Height + 21;
            if (!u3)
            {
                this.Width = picImage.Width;
            }
            //picBox.Location = new System.Drawing.Point((picBox.Parent.ClientSize.Width / 2) - (picImage.Width / 2),
            //(picBox.Parent.ClientSize.Height / 2) - (picImage.Height / 2));
            // picBox.Refresh();
        }
        public BitmapImage ConvertBitmap(Bitmap bitmap)
        {
            MemoryStream ms = new MemoryStream();
            bitmap.Save(ms, System.Drawing.Imaging.ImageFormat.Bmp);
            BitmapImage image = new BitmapImage();
            image.BeginInit();
            ms.Seek(0, SeekOrigin.Begin);
            image.StreamSource = ms;
            image.EndInit();

            return image;
        }
    }
}
