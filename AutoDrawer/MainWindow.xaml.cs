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
        Bitmap imageFile;
        Bitmap image;
        Bitmap processedImage;
        public static Bitmap imagePreview;
        bool PreviosulyDrawn = false;
        bool LockedLast = false;
        bool FreeDraw2 = false;
        bool MDown = false;
        int LastX;
        int LastY;
        bool CursorOffset = false;
        int xOffset = 0;
        int yOffset = 0;
        int width;
        int height;
        int interval;
        int clickdelay;
        int blackThreshold;
        int transparencyThreshold;
        int[,] pixelArray;
        ArrayList stack;
        //also if image transparent, it goes black bkg
        //Doesnt list. I generated property but the thing itself doesnt work. it doesnt error tho. see the pathintegers file for more
        public static int pathInt;
        public static bool pathIntAllowed = true;
        bool Started;
        bool finished;

        public void SetCursorPos(int posX, int posY)
        {
            SimWinInput.SimMouse.Act(SimWinInput.SimMouse.Action.MoveOnly, posX + xOffset, posY + yOffset);
        }
        public void LeftClick(SimWinInput.SimMouse.Action Action, int posX, int posY)
        {
            SimWinInput.SimMouse.Act(Action, posX + xOffset, posY + yOffset);
        }
        public const SimWinInput.SimMouse.Action MOUSEEVENTF_LEFTDOWN = SimWinInput.SimMouse.Action.LeftButtonDown;
        public const SimWinInput.SimMouse.Action MOUSEEVENTF_LEFTUP = SimWinInput.SimMouse.Action.LeftButtonUp;

        public System.Drawing.Color TransparencyKey { get; private set; }
        public RectangleF DisplayRectangle { get; private set; }

        public MainWindow()
        {
            InitializeComponent();
            blackThreshold = Convert.ToInt32(blackThreshNumeric.Text);
            blackThreshold = int.Parse(blackThreshNumeric.Text);
            transparencyThreshold = Convert.ToInt32(transThreshNumeric.Text);
            transparencyThreshold = int.Parse(transThreshNumeric.Text);
            interval = Convert.ToInt32(intervalInput.Text);
            interval = int.Parse(intervalInput.Text);
            clickdelay = Convert.ToInt32(clickdelayInput.Text);
            clickdelay = int.Parse(clickdelayInput.Text);
            pathList.SelectedIndex = 2;
            refreshDir();
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
        
        public void refreshDir()
        {
            Configs.Items.Clear();
            var fpath = "";
            fpath = @"%AppData%\AutoDraw\dir.txt";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            string[] lines;
            try
            {
                lines = File.ReadAllLines(fpath); //make if not exist
            }
            catch
            {
                Directory.CreateDirectory(@"%AppData%\AutoDraw\");
                StreamWriter sw = File.CreateText(fpath);
                sw.Close();
                lines = File.ReadAllLines(fpath); 
            }
            int i = 1;
            string dir = "";
            try
            {
                dir = lines[0];
            }
            catch
            {
                i = 0;
            }
            if (i == 1)
            {
                string[] files = Directory.GetFiles(dir);

                foreach (string file in files)
                {
                    if (file.EndsWith(".autodrawconfig"))
                    {
                        Configs.Items.Add(file.Replace(dir, "").Replace("\\", "").Replace("/", "").Replace(".autodrawconfig", ""));
                    }
                }
            }
        }
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            refreshDir();
        }
        private void setDirectory(object sender, RoutedEventArgs e)
        {
            using (var dialog = new FolderBrowserDialog())
            {
                DialogResult result = dialog.ShowDialog();
                var folder = dialog.SelectedPath;
                if (folder != "")
                {
                    var fpath = @"%AppData%\AutoDraw\dir.txt";
                    fpath = Environment.ExpandEnvironmentVariables(fpath);
                    File.WriteAllText(fpath, folder);
                    refreshDir();
                }
            }
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.SaveFileDialog();
            dialog.Title = "Where do you want to save your current settings?";
            dialog.Filter = "Config (*.autodrawconfig)|*.autodrawconfig";
            if (dialog.ShowDialog() == true)
            {
                var fileName = dialog.FileName;
                File.WriteAllText(fileName, intervalInput.Text.ToString() + "\n"+clickdelayInput.Text.ToString() + "\n"+blackThreshNumeric.Text.ToString() + "\n"+transThreshNumeric.Text.ToString());
                refreshDir();
            }
        }
        private void ListBoxConfig(object sender, RoutedEventArgs e)
        {
            var fpath = @"%AppData%\AutoDraw\dir.txt";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            string[] lines = File.ReadAllLines(fpath);
            int val = 0;
            Int32.TryParse((string)Configs.SelectedItem, out val);
            string text = Configs.Items[val].ToString();
            var name = lines[0];
            var path = name + "\\" + text + ".autodrawconfig";
            string[] theFile = File.ReadAllLines(path);
            intervalInput.Text = theFile[0];
            clickdelayInput.Text = theFile[1];
            blackThreshNumeric.Text = theFile[2];
            transThreshNumeric.Text = theFile[3];
            Configs.UnselectAll();

        }
        private void Button_Click2(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.OpenFileDialog();
            dialog.Title = "Choose your config";
            dialog.Filter = "Config (*.autodrawconfig)|*.autodrawconfig";
            if (dialog.ShowDialog() == true)
            {
                var fileName = dialog.FileName;
                string[] lines = File.ReadAllLines(fileName);
                intervalInput.Text = lines[0];
                clickdelayInput.Text = lines[1];
                blackThreshNumeric.Text = lines[2];
                transThreshNumeric.Text = lines[3];
            }
        }

        private void uploadButton_Click(object sender, RoutedEventArgs e)
        {
            upload();
        }
        private void upload()
        {
            // Show the Open File dialog. If the user clicks OK, load the
            // picture that the user chose.
            var dialog = new Microsoft.Win32.OpenFileDialog();
            if (dialog.ShowDialog() == true)
            {
                imageFile = new Bitmap(dialog.FileName);
                pictureBox1.Source = ConvertBitmap(imageFile);
                width = imageFile.Width;
                height = imageFile.Height;
                widthInput.Text = width.ToString();
                heightInput.Text = height.ToString();
                image = imageFile;
                imagePreview = image;
            }
        }

        private void clearButton_Click(object sender, RoutedEventArgs e)
        {
            clear();
        }

        private void clear()
        {
            // Clear the picture.
            pictureBox1.Source = null;
            imageFile = null;
            image = null;
            imagePreview = null;
        }
        private void widthInput_TextChanged(object sender, EventArgs e)
        {
            // Change in width of image
            try
            {
                width = Convert.ToInt32(widthInput.Text);
                width = int.Parse(widthInput.Text);
                image = resizeImage(imageFile, new System.Drawing.Size(width, height));
            }
            catch (Exception)
            {
                width = image.Width;
            }
            pictureBox1.Source = ConvertBitmap(image);
            imagePreview = image;
        }

        private void heightInput_TextChanged(object sender, EventArgs e)
        {
            // Change in height of image
            try
            {
                height = Convert.ToInt32(heightInput.Text);
                height = int.Parse(heightInput.Text);
                image = resizeImage(imageFile, new System.Drawing.Size(width, height));
            }
            catch (Exception)
            {
                height = image.Height;
            }
            pictureBox1.Source = ConvertBitmap(image);
            imagePreview = image;
        }
        private Bitmap resizeImage(Bitmap imgToResize, System.Drawing.Size size)
        {
            // Resizes image
            return new Bitmap(imgToResize, size);
        }

        private void blackThresh_TextChanged(object sender, EventArgs e)
        {
            // Threshold at which a pixel is deemed black;
            try
            {
                blackThreshold = Convert.ToInt32(blackThreshNumeric.Text);
                blackThreshold = int.Parse(blackThreshNumeric.Text);
            }
            catch{}
        }

        private void transThresh_TextChanged(object sender, EventArgs e)
        {
            try
            {
                // Threshold at which a pixel is deemed transparent
                transparencyThreshold = Convert.ToInt32(transThreshNumeric.Text);
                transparencyThreshold = int.Parse(transThreshNumeric.Text);
            }
            catch{}
        }

        private void interval_TextChanged(object sender, EventArgs e)
        {
            // Delay interval between the drawing of each pixel
            try
            {
                interval = Convert.ToInt32(intervalInput.Text);
                interval = int.Parse(intervalInput.Text);
            }
            catch (Exception)
            {
                interval = 0;
            }
        }

        private void clickDelay_TextChanged(object sender, EventArgs e)
        {
            // Delay interval between the drawing of each pixel
            try
            {
                clickdelay = Convert.ToInt32(clickdelayInput.Text);
                clickdelay = int.Parse(clickdelayInput.Text);
            }
            catch (Exception)
            {
                clickdelay = 0;
            }
        }
        private void pathList_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (!Started)
                {
                    if (pathList.SelectedIndex.ToString() == "0")
                    {
                        pathInt = 12345678;
                    }else
                    if (pathList.SelectedIndex.ToString() == "1")
                    {
                        pathInt = 14627358;
                    }else
                    if (pathList.SelectedIndex.ToString() == "2")
                    {
                        pathInt = 26573481;
                    }
                }
            }
            catch (Exception){}
        }

        private void processButton_Click(object sender, EventArgs e)
        {
            // Converts image to grayscale and applies thresholds
            try
            {
                Bitmap greyImage = MakeGrayscale3(image);
                processedImage = scan(greyImage, blackThreshold, transparencyThreshold);
                pictureBox1.Source = ConvertBitmap(processedImage);
                imagePreview = processedImage;
            }
            catch (Exception)
            {
                System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "No image was found\nMake sure you extracted the file.", "Process Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
        }
        private void startButton_Click(object sender, EventArgs e)
        {
            // Starts drawing
            Started = true;
            try
            {
                int imageTest = imagePreview.Width;
                PreviewForm m = new PreviewForm();
                m.Show();
                WindowState = (WindowState)FormWindowState.Minimized;
                while (true)
                {
                    System.Windows.Forms.Application.DoEvents();
                    if (System.Windows.Forms.Control.ModifierKeys == Keys.Alt)
                    {
                        m.Close();
                        break;
                    }
                    if (System.Windows.Forms.Control.ModifierKeys == Keys.Shift)
                    {
                        PreviosulyDrawn = true;
                        if (!LockedLast)
                        {
                            LastX = System.Windows.Forms.Cursor.Position.X;
                            LastY = System.Windows.Forms.Cursor.Position.Y;
                        }
                        m.Close();
                        start();
                        break;
                    }
                    if (System.Windows.Forms.Control.ModifierKeys == Keys.Control)
                    {
                        if (PreviosulyDrawn)
                        {
                            LockedLast = !LockedLast;
                            NOP(1000000);
                        }
                    }
                    if (LockedLast)
                    {
                        //m.Location() = new System.Drawing.Point((int)(LastX - m.Width / 2), (int)(LastY - m.Height / 2));
                        m.Top = (int)(LastY - m.Height / 2);
                        m.Left = (int)(LastX - m.Width / 2);
                    }
                    else
                    {
                        //m.Location = new System.Drawing.Point(xpos, ypos);

                        m.Top = (int)(System.Windows.Forms.Cursor.Position.Y - m.Height / 2);
                        m.Left = (int)(System.Windows.Forms.Cursor.Position.X - m.Width / 2);
                    }
                }
            }
            catch (Exception)
            {
                System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "No image was found\nMake sure you extracted the file.", "Image Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
        }

        private void start()
        {
            Window3 mw = new Window3();
            CursorOffset = mw.CursorOffset;
            FreeDraw2 = mw.FreeDraw;
            if (CursorOffset)
            {
                xOffset = mw.xOffset;
                yOffset = mw.yOffset;
            }
            else
            {
                xOffset = 0;
                yOffset = 0;
            }
            try
            {
                finished = draw();
                if (finished == true)
                {
                    System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Drawing Complete", "Done", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    Started = false;
                }
                else
                {
                    System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Drawing halted", "Incomplete", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    Started = false;
                }
            }
            catch (Exception)
            {
                System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "No image was found\nMake sure you extracted the file.", "Drawing Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                //Console.WriteLine("path: {0}", pathInt);
            }
        }
        private Bitmap MakeGrayscale3(Bitmap original)
        {
            //create a blank bitmap the same size as original\
            Bitmap newBitmap = new Bitmap(original.Width, original.Height);
            //get a graphics object from the new image
            Graphics g = Graphics.FromImage(newBitmap);

            //create the grayscale ColorMatrix
            ColorMatrix colorMatrix = new ColorMatrix(
            new float[][]
            {
                new float[] {.3f, .3f, .3f, 0, 0},
                new float[] {.59f, .59f, .59f, 0, 0},
                new float[] {.11f, .11f, .11f, 0, 0},
                new float[] {0, 0, 0, 1, 0},
                new float[] {0, 0, 0, 0, 1}
            });

            //create some image attributes
            ImageAttributes attributes = new ImageAttributes();

            //set the color matrix attribute
            attributes.SetColorMatrix(colorMatrix);

            //draw the original image on the new image
            //using the grayscale color matrix
            g.DrawImage(original, new System.Drawing.Rectangle(0, 0, original.Width, original.Height),
               0, 0, original.Width, original.Height, GraphicsUnit.Pixel, attributes);

            //dispose the Graphics object
            g.Dispose();
            return newBitmap;
        }

        private Bitmap scan(Bitmap image, int blackThreshold, int transparencyThreshold)
        {
            // Scans each pixel in image and gives it a black or white value
            pixelArray = new int[image.Width, image.Height];
            for (int y = 0; y < image.Height; y++)
            {
                for (int x = 0; x < image.Width; x++)
                {
                    System.Drawing.Color pixel = image.GetPixel(x, y);
                    if ((pixel.R < blackThreshold | pixel.G < blackThreshold | pixel.B < blackThreshold) && pixel.A > transparencyThreshold)
                    {
                        image.SetPixel(x, y, System.Drawing.Color.Black);
                        pixelArray[x, y] = 1;
                    }
                    else
                    {
                        image.SetPixel(x, y, System.Drawing.Color.White);
                        pixelArray[x, y] = 0;
                    }
                }
            }
            return image;
        }
        private bool draw()
        {
            System.Drawing.Point mouseCenter = System.Windows.Forms.Cursor.Position;
            int xorigin = mouseCenter.X - (image.Width / 2);
            int yorigin = mouseCenter.Y - (image.Height / 2);
            if (LockedLast)
            {
                xorigin = LastX - (image.Width / 2);
                yorigin = LastY - (image.Height / 2);
            }
            int xpos = xorigin;
            int ypos = yorigin;
            bool cont = true;

            // Draw all the areas
            stack = new ArrayList();
            for (int y = 0; y < image.Height; y++)
            {
                for (int x = 0; x < image.Width; x++)
                {
                    System.Windows.Forms.Application.DoEvents();
                    if (System.Windows.Forms.Control.ModifierKeys == Keys.Alt)
                        return false;
                    if (pixelArray[x, y] == 1)
                    {
                        xpos = xorigin + x;
                        ypos = yorigin + y;
                        SetCursorPos(xpos, ypos);
                        NOP(clickdelay * 10000);
                        SetCursorPos(xpos, ypos + 1);
                        LeftClick(MOUSEEVENTF_LEFTDOWN, xpos, ypos);
                        cont = drawArea(stack, x, y, xorigin, yorigin);
                        LeftClick(MOUSEEVENTF_LEFTUP, xpos, ypos);
                        if (System.Windows.Forms.Control.ModifierKeys == Keys.Alt)
                            return false;
                    }
                    if (!cont)
                    {
                        resetPixels();
                        return false;
                    }
                }
            }
            resetPixels();
            return true;
        }

        private bool drawArea(ArrayList stack, int x, int y, int xorigin, int yorigin)
        {
            bool cont;
            var path = pathInt.ToString().Select(t => int.Parse(t.ToString())).ToArray();

            while (true)
            {
                System.Windows.Forms.Application.DoEvents();
                if (System.Windows.Forms.Control.ModifierKeys == Keys.Alt)
                    return false;
                NOP(interval);
                SetCursorPos(xorigin + x, yorigin + y);
                pixelArray[x, y] = 2;
                /*
		        +---+---+---+
		        | 1 | 2 | 3 |
		        +---+---+---+
		        | 4 |   | 5 |
		        +---+---+---+
		        | 6 | 7 | 8 |
		        +---+---+---+
                */
                cont = false;
                foreach (int i in Enumerable.Range(0, 7))
                {
                    switch (path[i])
                    {
                        case 1:
                            if ((x > 0) && (y > 0))
                            {
                                if (pixelArray[x - 1, y - 1] == 1)
                                {
                                    push(stack, x, y);
                                    x -= 1;
                                    y -= 1;
                                    cont = true;
                                }
                            }
                            break;
                        case 2:
                            if (y > 0)
                            {
                                if (pixelArray[x, y - 1] == 1)
                                {
                                    push(stack, x, y);
                                    y -= 1;
                                    cont = true;
                                }
                            }
                            break;
                        case 3:
                            if ((x > 0) && (y < 0))
                            {
                                if (pixelArray[x + 1, y - 1] == 1)
                                {
                                    push(stack, x, y);
                                    x += 1;
                                    y += 1;
                                    cont = true;
                                }
                            }
                            break;
                        case 4:
                            if (x > 0)
                            {
                                if (pixelArray[x - 1, y] == 1)
                                {
                                    push(stack, x, y);
                                    x -= 1;
                                    cont = true;
                                }
                            }
                            break;
                        case 5:
                            if (x < (image.Width - 1))
                            {
                                if (pixelArray[x + 1, y] == 1)
                                {
                                    push(stack, x, y);
                                    x += 1;
                                    cont = true;
                                }
                            }
                            break;
                        case 6:
                            if ((x < 0) && (y > 0))
                            {
                                if (pixelArray[x - 1, y + 1] == 1)
                                {
                                    push(stack, x, y);
                                    x -= 1;
                                    y -= 1;
                                    cont = true;
                                }
                            }
                            break;
                        case 7:
                            if (y < (image.Height - 1))
                            {
                                if (pixelArray[x, y + 1] == 1)
                                {
                                    push(stack, x, y);
                                    y += 1;
                                    cont = true;
                                }
                            }
                            break;
                        case 8:
                            if ((x < (image.Width - 1)) && (y < (image.Height - 1)))
                            {
                                if (pixelArray[x + 1, y + 1] == 1)
                                {
                                    push(stack, x, y);
                                    x += 1;
                                    y += 1;
                                    cont = true;
                                }
                            }
                            break;
                    }
                }
                if (cont)
                    continue;
                if (!pop(stack, ref x, ref y))
                    break;
            }
            return true;
        }

        private void push(ArrayList stack, int x, int y)
        {
            stack.Add(new Position { x = x, y = y });
        }

        private bool pop(ArrayList stack, ref int x, ref int y)
        {
            if (stack.Count < 1)
                return false;

            Position pos = (Position)stack[stack.Count - 1];

            x = pos.x;
            y = pos.y;

            stack.Remove(pos);
            return true;
        }

        private void resetPixels()
        {
            // Reset the pixels statuses
            for (int y = 0; y < image.Height; y++)
            {
                for (int x = 0; x < image.Width; x++)
                {
                    if (pixelArray[x, y] == 2)
                        pixelArray[x, y] = 1;
                }
            }
        }

        private static void NOP(long durationTicks)
        {
            // Static method to initialize and start stopwatch
            var sw = Stopwatch.StartNew();

            while (sw.ElapsedTicks < durationTicks)
            {

            }
        }

        public static void Print2DArray(int[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    Console.Write(matrix[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            var hb = new HatchBrush(HatchStyle.Percent50, this.TransparencyKey);

            e.Graphics.FillRectangle(hb, this.DisplayRectangle);
        }
        private void InfoButton_Click_1(object sender, RoutedEventArgs e)
        {
            Window2 m = new Window2();
            m.Show();
        }

        private void SettingsButton_Click(object sender, RoutedEventArgs e)
        {
            Window3 m = new Window3();
            m.Show();
        }

        private void customButton_Click(object sender, RoutedEventArgs e)
        {
            PathSeqForm m = new PathSeqForm();
            m.Show();
        }
    }
    class Position
    {
        public int x { get; set; }
        public int y { get; set; }
    }
}