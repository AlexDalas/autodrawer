using System.Drawing;
using System.Windows.Forms;

namespace AutoDrawer
{
    public partial class PreviewForm : Form
    {
        Bitmap imagePreview = MainForm.imagePreview;

        public PreviewForm()
        {
            InitializeComponent();
            if (imagePreview.Width < 300)
            {
                pictureBox1.Anchor = AnchorStyles.None;
                CenterPictureBox(pictureBox1, imagePreview);

            }
            else
            {
                pictureBox1.Image = imagePreview;
            }
        }

        private void CenterPictureBox(PictureBox picBox, Bitmap picImage)
        {
            picBox.Image = picImage;
            picBox.Location = new Point((picBox.Parent.ClientSize.Width / 2) - (picImage.Width / 2),
                                        (picBox.Parent.ClientSize.Height / 2) - (picImage.Height / 2));
            picBox.Refresh();
        }
    }
}
