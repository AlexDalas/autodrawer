using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Drawing;
using System.IO;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Media;
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
            InitializeComponent();
            this.Topmost = true;
            CenterPictureBox(pictureBox1, imagePreview);
            refTheme();
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
                Grid1.Color = (System.Windows.Media.Color)System.Windows.Media.ColorConverter.ConvertFromString(json["preview"]["background"].ToString());
                TextLabel.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["preview"]["text"].ToString());
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
