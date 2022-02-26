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
    public partial class PreviewWindow : Window
    {
        readonly Bitmap imagePreview = MainWindow.imagePreview;


        public PreviewWindow()
        {
            //This errors out for some reason, need fix
            //this one errors because the class names are not the same. When they are the same, it all breaks
            InitializeComponent();
            this.Topmost = true;
            CenterPictureBox(pictureBox1, imagePreview);
        }
        private void CenterPictureBox(System.Windows.Controls.Image picBox, Bitmap picImage)
        {
            picBox.Source = ConvertBitmap(picImage);
            picBox.Height = picImage.Height + 22;
            this.Height = picImage.Height + 22;
            if (picImage.Width > 300)
            {
                this.Width = picImage.Width;
            }
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
