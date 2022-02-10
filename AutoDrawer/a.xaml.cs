using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;
using System.Windows.Media.Imaging;

namespace AutoDrawer
{
    public partial class PreviewForm : Form
    {
        Bitmap imagePreview = MainWindow.imagePreview;
        public PreviewForm()
        {
            //InitializeComponent();
            App.Current.MainWindow.Topmost = true; 
            //This errors out for some reason, need fix
            if (imagePreview.Width < 300)
            {
                //pictureBox1.Anchor = AnchorStyles.None;
                //CenterPictureBox(pictureBox1, imagePreview);

            }
            else
            {
                //pictureBox1.Source = ConvertBitmap(imagePreview);
            }
        }
        private void Window_Deactivated(object sender, EventArgs e)
        {
            // The Window was deactivated 
            App.Current.MainWindow.Topmost = false; 
            App.Current.MainWindow.Topmost = true; 
        }
        private void CenterPictureBox(PictureBox picBox, Bitmap picImage)
        {
            picBox.Image = picImage;
            picBox.Location = new System.Drawing.Point((picBox.Parent.ClientSize.Width / 2) - (picImage.Width / 2),
                                        (picBox.Parent.ClientSize.Height / 2) - (picImage.Height / 2));
            picBox.Refresh();
        }
        public BitmapImage ConvertBitmap(System.Drawing.Bitmap bitmap)
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