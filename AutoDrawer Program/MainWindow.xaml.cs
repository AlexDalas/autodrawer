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
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.Windows.Controls.Primitives;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using Microsoft.Win32;

namespace AutoDrawer
{

    public partial class MainWindow : Window
    {
        Bitmap imageFile;
        Bitmap image;
        Bitmap processedImage;
        public static Bitmap imagePreview;
        bool PreviosulyDrawn = false;
        bool LockedLast = false;
        //bool FreeDraw2 = false;
        //bool MDown = false;
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
        public static int pathInt;
        public static bool pathIntAllowed = true;
        bool Started;
        bool finished;

        public const SimWinInput.SimMouse.Action MOUSEEVENTF_LEFTDOWN = SimWinInput.SimMouse.Action.LeftButtonDown;
        public const SimWinInput.SimMouse.Action MOUSEEVENTF_LEFTUP = SimWinInput.SimMouse.Action.LeftButtonUp;

        [DllImport("user32.dll")]
        public static extern void mouse_event(int dwFlags, int dx, int dy, int cButtons, int dwExtraInfo); // Used only for WINE/Linux

        public void SetCursorPos(int posX, int posY)
        {
            SimWinInput.SimMouse.Act(SimWinInput.SimMouse.Action.MoveOnly, posX + xOffset, posY + yOffset);
        }
        public void LeftClick(SimWinInput.SimMouse.Action action, int posX, int posY)
        {
            if (true)//!WineDetect.WineDetected)
            {
                SimWinInput.SimMouse.Act(action, posX + xOffset, posY + yOffset);
            }
           /* else
            {
                if (action == SimWinInput.SimMouse.Action.LeftButtonDown)
                {
                    Process.Start("Z:/usr/bin/xdotool", "mousedown 1");
                    SimWinInput.SimMouse.Act(action, posX + xOffset, posY + yOffset);
                }
                else if (action == SimWinInput.SimMouse.Action.LeftButtonUp)
                {
                    Process.Start("Z:/usr/bin/xdotool", "mouseup 1");
                    SimWinInput.SimMouse.Act(action, posX + xOffset, posY + yOffset);
                }
            }*/
        }

        public System.Drawing.Color TransparencyKey { get; private set; }
        public RectangleF DisplayRectangle { get; private set; }

        public MainWindow()
        {
            InitializeComponent();
            if (!WineDetect.HasChecked)
            {
                WineDetect.RunChecks();
                if (WineDetect.WineDetected)
                {
                    System.Windows.Forms.MessageBox.Show("Linux is HIGHLY Experimental, and will most likely not work!", "Wine Detected");
                }
            }
            HotkeySystem.Subscribe();
            blackThreshold = Convert.ToInt32(blackThreshNumeric.Text);
            blackThreshold = int.Parse(blackThreshNumeric.Text);
            transparencyThreshold = Convert.ToInt32(transThreshNumeric.Text);
            transparencyThreshold = int.Parse(transThreshNumeric.Text);
            interval = Convert.ToInt32(intervalInput.Text);
            interval = int.Parse(intervalInput.Text);
            clickdelay = Convert.ToInt32(clickdelayInput.Text);
            clickdelay = int.Parse(clickdelayInput.Text);
            pathList.SelectedIndex = 2;
            LogHandler.LogSent += UpdateLogs;
            Console.WriteLine("Initialized Component.");
            RefreshDir();
            refreshTheme();
        }
        private void UpdateLogs(object _, string text)
        {
            ConsoleWindow.LogText += text;
        }
        public void ToFront()
        {
            // <3 I don't like writing 6 lines over and over
            this.Show();
            this.WindowState = WindowState.Normal;
            this.Activate();
            this.Topmost = true;
            this.Topmost = false;
            this.Focus();
        }
        private void Close_Click(object sender, RoutedEventArgs e)
        {
            //X button
            System.Windows.Application.Current.Shutdown();
        }

        private void Minimize_Click(object sender, RoutedEventArgs e)
        {
            //Minimize button
            WindowState = WindowState.Minimized;
        }

        public BitmapImage ConvertBitmap(Bitmap bitmap)
        {
            MemoryStream ms = new MemoryStream();
            bitmap.Save(ms, ImageFormat.Bmp);
            BitmapImage image = new BitmapImage();
            image.BeginInit();
            ms.Seek(0, SeekOrigin.Begin);
            image.StreamSource = ms;
            image.EndInit();

            return image;
        }

        public void RefreshDir()
        {
            LogHandler.LogFile("Refreshing Directory");
            Configs.Items.Clear();
            string fpath;
            fpath = @"%AppData%\AutoDraw\dir.txt";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            string[] lines;
            try
            {
                lines = File.ReadAllLines(fpath); //make if not exist
                try
                {
                    var cpath = Environment.ExpandEnvironmentVariables(@"%AppData%\AutoDraw\");
                    Directory.CreateDirectory(cpath + "\\logs");
                }
                catch
                { }

            }
            catch
            {
                var cpath = Environment.ExpandEnvironmentVariables(@"%AppData%\AutoDraw\");

                try
                {
                    Directory.CreateDirectory(cpath);
                    Directory.CreateDirectory(cpath + "\\logs");
                }
                catch
                {
                    Directory.CreateDirectory(cpath + "\\logs");
                }
                try
                {
                    StreamWriter sw = File.CreateText(fpath);
                    sw.Close();
                    lines = File.ReadAllLines(fpath);
                }
                catch
                {
                    File.WriteAllText(fpath, "");
                    lines = File.ReadAllLines(fpath);
                }
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
                try
                {
                    string[] files = Directory.GetFiles(dir);
                    foreach (string file in files)
                    {
                        if (file.EndsWith(".drawcfg"))
                        {
                            Configs.Items.Add(file.Replace(dir, "").Replace("\\", "").Replace("/", "").Replace(".drawcfg", ""));
                        }
                        if (file.EndsWith(".autodrawconfig") || file.EndsWith(".autodrawconfi"))
                        {
                            try
                            {
                                File.Move(file, file.Replace(".autodrawconfig", ".drawcfg").Replace(".autodrawconfi", ".drawcfg"));
                                Configs.Items.Add(file.Replace(dir, "").Replace("\\", "").Replace("/", "").Replace(".drawcfg", ""));
                                RefreshDir();
                            }
                            catch { }
                        }
                    }
                }
                catch
                {
                    File.WriteAllText(fpath, "");
                }
            }
        }
        private void RefreshDirectory_Click(object sender, RoutedEventArgs e)
        {
            LogHandler.LogFile("Refreshing directory");
            RefreshDir();
        }
        private void SetDirectory(object sender, RoutedEventArgs e)
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
                    LogHandler.LogFile("Set directory to " + fpath);
                    RefreshDir();
                }
            }
        }
        private void SaveSettings_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.SaveFileDialog
            {
                Title = "Where do you want to save your current settings?",
                Filter = "Config (*.drawcfg)|*.drawcfg|Config (*.autodrawconfig)|*.autodrawconfig|Config (*.autodrawconfi)|*.autodrawconfi"
            };
            if (dialog.ShowDialog() == true)
            {
                var fileName = dialog.FileName;
                LogHandler.LogFile("Saving " + dialog.FileName);
                File.WriteAllText(fileName, intervalInput.Text.ToString() + "\n" + clickdelayInput.Text.ToString() + "\n" + blackThreshNumeric.Text.ToString() + "\n" + transThreshNumeric.Text.ToString());
                RefreshDir();
            }
        }
        private void ListBoxConfig(object sender, RoutedEventArgs e)
        {
            var fpath = @"%AppData%\AutoDraw\dir.txt";
            fpath = Environment.ExpandEnvironmentVariables(fpath);
            string[] lines = File.ReadAllLines(fpath);
            var name = lines[0];
            var path = name + "\\" + Configs.Items[Configs.SelectedIndex].ToString() + ".drawcfg";
            string[] theFile = File.ReadAllLines(path);
            intervalInput.Text = theFile[0];
            clickdelayInput.Text = theFile[1];
            blackThreshNumeric.Text = theFile[2];
            transThreshNumeric.Text = theFile[3];
        }
        private void LoadSettings_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.OpenFileDialog
            {
                Title = "Choose your config",
                Filter = "Draw Config|*.drawcfg;*.autodrawconfig;*.autodrawconfi"
            };
            if (dialog.ShowDialog() == true)
            {
                LogHandler.LogFile("Selected " + dialog.FileName);
                var fileName = dialog.FileName;
                string[] lines = File.ReadAllLines(fileName);
                intervalInput.Text = lines[0];
                clickdelayInput.Text = lines[1];
                blackThreshNumeric.Text = lines[2];
                transThreshNumeric.Text = lines[3];
            }
        }

        private void UploadButton_Click(object sender, RoutedEventArgs e)
        {
            var dialog = new Microsoft.Win32.OpenFileDialog();
            if (dialog.ShowDialog() == true)
            {
                try
                {
                    imageFile = new Bitmap(dialog.FileName);
                }
                catch
                { System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Image error. Is this even an image?", "Image Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk); return; }
                if (dialog.FileName.EndsWith(".png")) FillPngWhite(imageFile);
                PictureBox.Source = ConvertBitmap(imageFile);
                width = imageFile.Width;
                height = imageFile.Height;
                widthInput.Text = width.ToString();
                heightInput.Text = height.ToString();
                image = imageFile;
                imagePreview = image;
                LogHandler.LogFile("Uploaded image " + dialog.FileName + " via Upload Button");
            }
        }
        private void UploadPath(string path)
        {
            LogHandler.LogFile("Uploaded image " + path + " via Drag/Drop");
            imageFile = new Bitmap(path);
            if (path.EndsWith(".png")) FillPngWhite(imageFile);
            PictureBox.Source = ConvertBitmap(imageFile);
            width = imageFile.Width;
            height = imageFile.Height;
            widthInput.Text = width.ToString();
            heightInput.Text = height.ToString();
            image = imageFile;
            imagePreview = image;
        }
        public Bitmap FillPngWhite(Bitmap bmp)
        {
            Bitmap originalBMP = bmp;
            if (ContainsTransparent(originalBMP))
            {
                try
                {
                    if (bmp.PixelFormat != System.Drawing.Imaging.PixelFormat.Format32bppArgb)
                        throw new ApplicationException("Not supported PNG image!");
                }
                catch { }

                // Lock the bitmap's bits.  
                System.Drawing.Rectangle rect = new System.Drawing.Rectangle(0, 0, bmp.Width, bmp.Height);
                BitmapData bmpData = bmp.LockBits(rect, ImageLockMode.ReadWrite, bmp.PixelFormat);

                // Get the address of the first line.
                IntPtr ptr = bmpData.Scan0;

                // Declare an array to hold the bytes of the bitmap.
                int bytes = Math.Abs(bmpData.Stride) * bmp.Height;
                byte[] rgbaValues = new byte[bytes];

                // Copy the RGB values into the array.
                Marshal.Copy(ptr, rgbaValues, 0, bytes);

                // array consists of values RGBARGBARGBA
                int counter;
                for (counter = 0; counter < rgbaValues.Length; counter += 4)
                {
                    double t = rgbaValues[counter + 3] / 255.0; // transparency of pixel between 0 .. 1 , easier to do math with this
                    double rt = 1 - t; // inverted value of transparency

                    // C = C * t + W * (1-t) // alpha transparency for your case C-color, W-white (255)
                    // same for each color
                    rgbaValues[counter] = (byte)(rgbaValues[counter] * t + 255 * rt); // R color
                    rgbaValues[counter + 1] = (byte)(rgbaValues[counter + 1] * t + 255 * rt); // G color
                    rgbaValues[counter + 2] = (byte)(rgbaValues[counter + 2] * t + 255 * rt); // B color

                    rgbaValues[counter + 3] = 255; // A = 255 => no transparency 
                }
                // Copy the RGB values back to the bitmap
                Marshal.Copy(rgbaValues, 0, ptr, bytes);
                bmp.UnlockBits(bmpData);
                return bmp;
            }
            else
            {
                return originalBMP;
            }
        }
        bool ContainsTransparent(Bitmap image)
        {
            for (int y = 0; y < image.Height; ++y)
            {
                for (int x = 0; x < image.Width; ++x)
                {
                    if (image.GetPixel(x, y).A != 255)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        private void ClearButton_Click(object sender, RoutedEventArgs e)
        {
            LogHandler.LogFile("Clearing Image");
            Clear();
        }

        private void Clear()
        {
            // Clear the picture.
            PictureBox.Source = null;
            imageFile = null;
            image = null;
            imagePreview = null;
            GC.Collect();
        }
        public Regex nubmerRegex = new Regex("[^0-9]+");
        public Regex nubmerRegexDec = new Regex("[^0-9.]+");
        public double Scale = 1;
        private void ScaleSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (ScaleInput == null) return;
            Scale = (int)ScaleSlider.Value/100;
            ScaleInput.Text = nubmerRegexDec.Replace(Math.Round(ScaleSlider.Value).ToString(), "");
        }

        private void ScaleSlider_DragCompleted(object sender, DragCompletedEventArgs e)
        {
            if (image != null)
            {
                try
                {
                    Scale = (double)(ScaleSlider.Value / 100);
                    widthInput.Text = Math.Round(imageFile.Size.Width * Scale).ToString();
                    heightInput.Text = Math.Round(imageFile.Size.Height * Scale).ToString();
                    /*image = ResizeImage(imageFile, new System.Drawing.Size(
                        (int)Math.Round(imageFile.Size.Width * Scale),
                        (int)Math.Round(imageFile.Size.Height * Scale)
                    ));*/
                }
                catch (Exception)
                {
                    ScaleInput.Text = "100";
                }
                PictureBox.Source = ConvertBitmap(image);
                imagePreview = image;
                LogHandler.LogFile("Changing Scale to " + ScaleInput.Text);
                GC.Collect();
            }
        }
        private void ScaleInput_TextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                ScaleSlider.Value = Int32.Parse(ScaleInput.Text);
            }catch { }
            if (image != null)
            {
                try
                {
                    Scale = (double)(ScaleSlider.Value / 100);
                    widthInput.Text = Math.Round(imageFile.Size.Width * Scale).ToString();
                    heightInput.Text = Math.Round(imageFile.Size.Height * Scale).ToString();
                    /*image = ResizeImage(imageFile, new System.Drawing.Size(
                        (int)Math.Round(imageFile.Size.Width * Scale),
                        (int)Math.Round(imageFile.Size.Height * Scale)
                    ));*/
                }
                catch (Exception)
                {
                    ScaleInput.Text = "100";
                }
                PictureBox.Source = ConvertBitmap(image);
                imagePreview = image;
                LogHandler.LogFile("Changing Scale to " + ScaleInput.Text);
                GC.Collect();
            }
        }
        private void WidthInput_TextChanged(object sender, EventArgs e)
        {
            // Change in width of image
            if (image != null)
            {
                try
                {
                    widthInput.Text = nubmerRegex.Replace(widthInput.Text, "");
                    width = int.Parse(widthInput.Text);
                    image = ResizeImage(imageFile, new System.Drawing.Size(width, height));
                }
                catch (Exception)
                {
                    width = image.Width;
                }
                PictureBox.Source = ConvertBitmap(image);
                imagePreview = image;
                LogHandler.LogFile("Changing width to " + widthInput.Text);
                GC.Collect();
            }
        }

        private void HeightInput_TextChanged(object sender, EventArgs e)
        {
            // Change in height of image
            if (image != null)
            {
                try
                {
                    height = Convert.ToInt32(heightInput.Text);
                    height = int.Parse(heightInput.Text);
                    image = ResizeImage(imageFile, new System.Drawing.Size(width, height));
                }
                catch (Exception)
                {
                    height = image.Height;
                }
                PictureBox.Source = ConvertBitmap(image);
                imagePreview = image;
                LogHandler.LogFile("Changing height to " + heightInput.Text);
                GC.Collect();
            }
        }
        private Bitmap ResizeImage(Bitmap imgToResize, System.Drawing.Size size)
        {
            // Resizes image
            return new Bitmap(imgToResize, size);
        }

        private void BlackThresh_TextChanged(object sender, EventArgs e)
        {
            // Threshold at which a pixel is deemed black;
            try
            {
                blackThreshold = Convert.ToInt32(blackThreshNumeric.Text);
                blackThreshold = int.Parse(blackThreshNumeric.Text);
            }
            catch { }
        }

        private void TransThresh_TextChanged(object sender, EventArgs e)
        {
            try
            {
                // Threshold at which a pixel is deemed transparent
                transparencyThreshold = Convert.ToInt32(transThreshNumeric.Text);
                transparencyThreshold = int.Parse(transThreshNumeric.Text);
            }
            catch { }
        }

        private void Interval_TextChanged(object sender, EventArgs e)
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

        private void ClickDelay_TextChanged(object sender, EventArgs e)
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
        private void PathList_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (!Started)
                {
                    if (pathList.SelectedIndex.ToString() == "0")
                    {
                        pathInt = 12345678;
                    }
                    else
                    if (pathList.SelectedIndex.ToString() == "1")
                    {
                        pathInt = 14627358;
                    }
                    else
                    if (pathList.SelectedIndex.ToString() == "2")
                    {
                        pathInt = 26573481;
                    }
                    LogHandler.LogFile("Changing Pattern to " + pathInt);
                }
            }
            catch (Exception) { }
        }

        private void ProcessButton_Click(object sender, EventArgs e)
        {
            // Converts image to grayscale and applies thresholds
            LogHandler.LogFile("Processing image");
            try
            {
                Bitmap greyImage = MakeGrayscale3(image);
                processedImage = Scan(greyImage, blackThreshold, transparencyThreshold);
                PictureBox.Source = ConvertBitmap(processedImage);
                imagePreview = processedImage;
                GC.Collect();
                GC.WaitForPendingFinalizers();
            }
            catch (Exception)
            {
                System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "No image was found. Did you upload an image?.", "Processing Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
        }
        private void StartButton_Click(object sender, EventArgs e)
        {
            LogHandler.LogFile("Starting drawing.\n{\n   Width: " + widthInput.Text + "\n   Height: " + heightInput.Text + "\n   Interval: " + intervalInput.Text + "\n   Click Delay: " + clickdelayInput.Text + "\n   Black Threshold: " + blackThreshNumeric.Text + "\n   Transparency Threshold: " + transThreshNumeric.Text + "\n}");
            // Starts drawing
            Started = true;
            try
            {
                int imageTest = imagePreview.Width;
                PreviewWindow m = new PreviewWindow();
                m.Show();
                WindowState = (WindowState)FormWindowState.Minimized;
                bool CloseRequested = false;
                bool StartRequeted = false;
                bool LockToLast = false;
                void KeyRequest(object _sender, Keys key)
                {
                    if (key == Keys.LMenu || key == Keys.Menu || key == Keys.Alt)
                    {
                        CloseRequested = true;
                    }else if (key == Keys.Shift || key == Keys.ShiftKey || key == Keys.LShiftKey)
                    {
                        StartRequeted = true;
                    }
                    else if (key == Keys.Control || key == Keys.ControlKey || key == Keys.LControlKey)
                    {
                        LockToLast = !LockToLast;
                    }
                }
                HotkeySystem.KeyPress += KeyRequest;
                while (true)
                {
                    System.Windows.Forms.Application.DoEvents();
                    if (CloseRequested == true)
                    {
                        m.Close();
                        HotkeySystem.KeyPress -= KeyRequest;
                        break;
                    }
                    if (StartRequeted == true)
                    {
                        PreviosulyDrawn = true;
                        if (!LockedLast)
                        {
                            LastX = System.Windows.Forms.Cursor.Position.X;
                            LastY = System.Windows.Forms.Cursor.Position.Y;
                        }
                        m.Close();
                        HotkeySystem.KeyPress -= KeyRequest;
                        Start();
                        break;
                    }
                    if (LockToLast)
                    {
                        if (PreviosulyDrawn)
                        {
                            LockedLast = !LockedLast;
                        }
                        LockToLast = false;
                    }
                    if (LockedLast)
                    {
                        m.Top = (int)(LastY - m.Height / 2) - 11;
                        m.Left = (int)(LastX - m.Width / 2);
                    }
                    else
                    {
                        m.Top = (int)(System.Windows.Forms.Cursor.Position.Y - m.Height / 2) - 11;
                        m.Left = (int)(System.Windows.Forms.Cursor.Position.X - m.Width / 2);
                    }
                }
            }
            catch (Exception)
            {
                System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "No image was found\nMake sure you extracted the file.", "Image Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                LogHandler.LogFile("No image was found.");
            }
        }

        private async void Start()
        {
            CursorOffset = SettingsWindow.CursorOffset;
            if (CursorOffset)
            {
                xOffset = SettingsWindow.xOffset;
                yOffset = SettingsWindow.yOffset;
            }
            else
            {
                xOffset = 0;
                yOffset = 0;
            }
            try
            {
                finished = await Draw();
                if (finished == true)
                {
                    System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Drawing Complete", "Done", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    Started = false;
                    LogHandler.LogFile("Drawing Complete.");
                }
                else
                {
                    System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "Drawing halted", "Incomplete", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                    Started = false;
                    LogHandler.LogFile("Drawing halted.");
                }
            }
            catch (Exception)
            {
                System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, "No image was found\nMake sure you extracted the file.", "Drawing Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                LogHandler.LogFile("No image was found.");
                //Console.WriteLine("path: {0}", pathInt);
            }
        }
        private Bitmap MakeGrayscale3(Bitmap original)
        {
            //create a blank bitmap the same size as original\
            Bitmap newBitmap;
            try
            {
                newBitmap = new Bitmap(original.Width, original.Height);
            }
            catch
            {
                throw new ArgumentException("unprocessedImage");
            }
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

        private Bitmap Scan(Bitmap image, int blackThreshold, int transparencyThreshold)
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
        private async Task<bool> Draw()
        {
            System.Drawing.Point mouseCenter = System.Windows.Forms.Cursor.Position;
            int xorigin = mouseCenter.X - (image.Width / 2);
            int yorigin = mouseCenter.Y - (image.Height / 2);
            if (LockedLast)
            {
                xorigin = LastX - (image.Width / 2);
                yorigin = LastY - (image.Height / 2);
            }

            bool cont = true;
            
            // Draw all the areas
            stack = new ArrayList();

            bool Paused = false;
            var path = pathInt.ToString().Select(t => int.Parse(t.ToString())).ToArray();

            void KeyRequest(object _sender, Keys e)
            {
                if (e == Keys.F4)
                {
                    Paused = !Paused;
                }
            }
            async Task CheckPauseAsync(int x, int y)
            {
                if (Paused)
                {
                    LeftClick(MOUSEEVENTF_LEFTUP, xorigin + x, yorigin + y);
                    while (Paused)
                    {
                        await Task.Delay(1);
                    }
                    LeftClick(MOUSEEVENTF_LEFTDOWN, xorigin + x, yorigin + y);
                }
            }

            for (int y = 0; y < image.Height; y++)
            {
                for (int x = 0; x < image.Width; x++)
                {
                    System.Windows.Forms.Application.DoEvents();
                    if (System.Windows.Forms.Control.ModifierKeys == Keys.Alt)
                        return false;
                    if (pixelArray[x, y] == 1)
                    {
                        int xpos = xorigin + x;
                        int ypos = yorigin + y;
                        HotkeySystem.KeyPress += KeyRequest;
                        NOP(clickdelay * 5000);
                        await CheckPauseAsync(x,y);
                        SetCursorPos(xpos, ypos + 1);
                        NOP(clickdelay * 5000);
                        await CheckPauseAsync(x, y);
                        HotkeySystem.KeyPress -= KeyRequest;
                        LeftClick(MOUSEEVENTF_LEFTDOWN, xpos, ypos);
                        cont = await DrawArea(stack, x, y, xorigin, yorigin);
                        LeftClick(MOUSEEVENTF_LEFTUP, xpos, ypos);
                        if (System.Windows.Forms.Control.ModifierKeys == Keys.Alt)
                            return false;
                    }
                    if (!cont)
                    {
                        ResetPixels();
                        return false;
                    }
                }
            }
            ResetPixels();
            return true;
        }

        private async Task<bool> DrawArea(ArrayList stack, int x, int y, int xorigin, int yorigin)
        {
            bool cont;
            bool CloseRequested = false;
            bool Paused = false;
            var path = pathInt.ToString().Select(t => int.Parse(t.ToString())).ToArray();

            void KeyRequest(object _sender, Keys e)
            {
                if (e == Keys.LMenu || e == Keys.Alt)
                {
                    CloseRequested = true;
                }
                if (e == Keys.F4)
                {
                    Paused = !Paused;
                }
            }
            HotkeySystem.KeyPress += KeyRequest;

            while (true)
            {
                if (Paused)
                {
                    LeftClick(MOUSEEVENTF_LEFTUP, xorigin + x, yorigin + y);
                    while (Paused)
                    {
                        await Task.Delay(1);
                    }
                    LeftClick(MOUSEEVENTF_LEFTDOWN, xorigin + x, yorigin + y);
                }
                System.Windows.Forms.Application.DoEvents();
                if (CloseRequested == true)
                {
                    HotkeySystem.KeyPress -= KeyRequest;
                    return false;
                }
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
                                    Push(stack, x, y);
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
                                    Push(stack, x, y);
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
                                    Push(stack, x, y);
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
                                    Push(stack, x, y);
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
                                    Push(stack, x, y);
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
                                    Push(stack, x, y);
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
                                    Push(stack, x, y);
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
                                    Push(stack, x, y);
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
                if (!Pop(stack, ref x, ref y))
                    break;
            }
            return true;
        }

        private void Push(ArrayList stack, int x, int y)
        {
            stack.Add(new Position { X = x, Y = y });
        }

        private bool Pop(ArrayList stack, ref int x, ref int y)
        {
            if (stack.Count < 1)
                return false;

            Position pos = (Position)stack[stack.Count - 1];

            x = pos.X;
            y = pos.Y;

            stack.Remove(pos);
            return true;
        }

        private void ResetPixels()
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
            try { 
                Window2 m = new Window2();
                m.Show();
            }
            catch { }
        }

        private void SettingsButton_Click(object sender, RoutedEventArgs e)
        {
            SettingsWindow m = new SettingsWindow();
            try
            {
                m.Show();
            }
            catch { }
        }

        private void CustomButton_Click(object sender, RoutedEventArgs e)
        {
            try { 
                PathSeqForm m = new PathSeqForm();
                m.Show();
            }catch{}
        }

        private void RecDrop(object sender, System.Windows.DragEventArgs e)
        {
            DragInd.Visibility = Visibility.Collapsed;
            string[] files = (string[])e.Data.GetData(System.Windows.DataFormats.FileDrop);
            try
            {
                try
                {
                    if (files[0].EndsWith(".drawcfg") || files[0].EndsWith(".autodrawconfig") || files[0].EndsWith(".autodrawconfi"))
                    {
                        string[] lines = File.ReadAllLines(files[0]);
                        bool result = Int32.TryParse(lines[3], out int number);
                        intervalInput.Text = lines[0];
                        clickdelayInput.Text = lines[1];
                        blackThreshNumeric.Text = lines[2];
                        transThreshNumeric.Text = lines[3];
                        LogHandler.LogFile("Drag/Drop (Config) completed at ");
                    }
                    else if (files[0].EndsWith(".drawtheme"))
                    {
                        string cpath = Environment.ExpandEnvironmentVariables("%AppData%\\AutoDraw");
                        string lines = File.ReadAllText(files[0]);
                        LogHandler.LogFile(cpath + "\\themes\\" + System.IO.Path.GetFileName(files[0]) + ", " + lines);
                        File.WriteAllText(cpath + "\\themes\\" + System.IO.Path.GetFileName(files[0]), lines);
                        File.WriteAllText(cpath + "\\themes\\theme.txt", System.IO.Path.GetFileNameWithoutExtension(files[0]));
                        refreshTheme();
                        //To do: Refresh theme for every window open
                    }
                    else throw new ApplicationException("Invalid file!"); LogHandler.LogFile("Dragged invalid file " + files[0]);
                }
                catch { }
            }
            catch
            {
                UploadPath(files[0]);
                LogHandler.LogFile("Drag/Drop (Image).");
            }
        }
        private void RecOver(object sender, System.Windows.DragEventArgs e)
        {
            DragInd.Visibility = Visibility.Visible;
        }
        private void RecExit(object sender, System.Windows.DragEventArgs e)
        {
            DragInd.Visibility = Visibility.Collapsed;
        }
        void createTheme(string th)
        {
            string cpath = Environment.ExpandEnvironmentVariables(@"%AppData%\AutoDraw");
            using (StreamWriter sw = File.CreateText(cpath + @"\themes\theme.txt"))
            {
                sw.WriteLine(th);
            }
        }
        public void refreshTheme()
        {
            string cpath = Environment.ExpandEnvironmentVariables(@"%AppData%\AutoDraw");
            //0 for dark, 1 for light
            string isLightMode = Registry.GetValue(@"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize", "SystemUsesLightTheme", null).ToString();
            try
            {
                Directory.CreateDirectory(cpath + @"\themes");
            }
            catch { }
            try
            {
                var a = File.ReadLines(cpath + @"\themes\theme.txt").First();
            }
            catch
            {
                if (isLightMode == "1")
                    createTheme("light");
                else
                    createTheme("dark");

            }
            var thm = File.ReadLines(cpath + @"\themes\theme.txt").First();
            if (!File.Exists(cpath + @"\themes\dark.drawtheme"))
            {
                using (StreamWriter sw = File.CreateText(cpath + @"\themes\dark.drawtheme"))
                {
                    sw.WriteLine("{\n    \"ver\": 1.4,\n    \"light-icons\": \"true\",\n    \"main\": {\n        \"text\": \"#FFFFFFFF\",\n        \"background\": \"#FF2C302E\",\n        \"background-1\": \"#FF333735\",\n        \"background-2\": \"#FF2C302E\",\n        \"image-background\": \"#FF3A3D3B\",\n        \"pattern-listbox\": \"#FF484A49\",\n        \"config-listbox\": \"#FF353735\",\n        \"loadconfig-button\": \"#FF3A3D3B\",\n        \"saveconfig-button\": \"#FF3A3D3B\",\n        \"settings-info-buttons\": \"#FF3A3D3B\",\n        \"pattern-button\": \"#FF3A3D3B\",\n        \"directory-buttons\": \"#FF3A3D3B\",\n        \"textbox-backgrounds\": \"#FF474A48\",\n        \"upload-buttons\": \"#FF3A3D3B\",\n        \"clear-buttons\": \"#FF3A3D3B\",\n        \"process-button\": \"#FF3A3D3B\",\n        \"start-button\": \"#FF3A3D3B\",\n        \"scalebar-background\": \"#00000000\",\n        \"scale-textbox\": \"#FF474A48\",\n        \"width-textbox\": \"#FF474A48\",\n        \"height-textbox\": \"#FF474A48\"\n    },\n    \"settings\": {\n        \"text\": \"#FFFFFFFF\",\n        \"background\": \"#FF2C302E\",\n        \"buttons\": \"#FF2C302E\",\n        \"textbox\": \"#FF2C302E\",\n        \"checkbox-box\": \"#FFFFFFFF\",\n        \"close\": \"#FF2C302E\"\n    },\n    \"info\": {\n        \"text\": \"#FFFFFFFF\",\n        \"background\": \"#FF2C302E\",\n        \"close\": \"#EF2C302E\"\n    },\n    \"pattern\": {\n        \"text\": \"#FFFFFFFF\",\n        \"background\": \"#FF2C302E\",\n        \"image-background\": \"#FF3C3C3C\",\n        \"button\": \"#FF2C302E\",\n        \"textbox\": \"#FF2C302E\",\n        \"close\": \"#FF2C302E\"\n    },\n    \"console\": {\n        \"text\": \"#FFFFFFFF\",\n        \"background\": \"#FF2C302E\",\n        \"console-background\": \"#FF333735\",\n        \"button\": \"#FF2C302E\",\n        \"close\": \"#FF2C302E\"\n    },\n    \"preview\": {\n        \"text\": \"#FFFFFFFF\",\n        \"background\": \"#000000\"\n    }\n}\n\n");
                }
            }
            if (!File.Exists(cpath + @"\themes\light.drawtheme"))
            {
                using (StreamWriter sw = File.CreateText(cpath + @"\themes\light.drawtheme"))
                {
                    sw.WriteLine("{\n    \"ver\": 1.4,\n    \"light-icons\": \"false\",\n    \"main\": {\n        \"text\": \"#FF000000\",\n        \"background\": \"#E3E4DB\",\n        \"background-1\": \"#D8D9D4\",\n        \"background-2\": \"#CDCDCD\",\n        \"image-background\": \"#D8D9D4\",\n        \"pattern-listbox\": \"#D8D9D4\",\n        \"config-listbox\": \"#D8D9D4\",\n        \"loadconfig-button\": \"#D8D9D4\",\n        \"saveconfig-button\": \"#D8D9D4\",\n        \"settings-info-buttons\": \"#D8D9D4\",\n        \"pattern-button\": \"#D8D9D4\",\n        \"directory-buttons\": \"#D8D9D4\",\n        \"textbox-backgrounds\": \"#D8D9D4\",\n        \"upload-buttons\": \"#D8D9D4\",\n        \"clear-buttons\": \"#D8D9D4\",\n        \"process-button\": \"#D8D9D4\",\n        \"start-button\": \"#D8D9D4\",\n        \"scalebar-background\": \"#ffffffff\",\n        \"scale-textbox\": \"#FFAEBDB3\",\n        \"width-textbox\": \"#FFAEBDB3\",\n        \"height-textbox\": \"#FFAEBDB3\"\n    },\n    \"settings\": {\n        \"text\": \"#FF000000\",\n        \"background\": \"#FFCED8D3\",\n        \"buttons\": \"#FFCED8D3\",\n        \"textbox\": \"#FFCED8D3\",\n        \"checkbox-box\": \"#ffffffff\",\n        \"close\": \"#FFCED8D3\"\n    },\n    \"info\": {\n        \"text\": \"#FF000000\",\n        \"background\": \"#EFC9D8D0\",\n        \"close\": \"#EFC9D8D0\"\n    },\n    \"pattern\": {\n        \"text\": \"#FF000000\",\n        \"background\": \"#FFCED8D3\",\n        \"image-background\": \"#EFBAC8C1\",\n        \"button\": \"#FFCED8D3\",\n        \"textbox\": \"#FFCED8D3\",\n        \"close\": \"#FFCED8D3\"\n    },\n    \"console\": {\n        \"text\": \"#FF000000\",\n        \"background\": \"#FFCED8D3\",\n        \"console-background\": \"#FFBEC5BE\",\n        \"button\": \"#FFCED8D3\",\n        \"close\": \"#FFCED8D3\"\n    },\n    \"preview\": {\n        \"text\": \"#FF000000\",\n        \"background\": \"#ffffff\"\n    }\n}\n\n\n");
                }
            }
            if (!File.Exists(cpath + @"\themes\" + thm + ".drawtheme"))
            {
                if (isLightMode == "1")
                    createTheme("light");
                else
                    createTheme("dark");
                thm = File.ReadLines(cpath + @"\themes\theme.txt").First();
            }
            string jsonFile = cpath + @"\themes\" + thm + ".drawtheme";
            using (StreamReader file = File.OpenText(jsonFile))
            using (JsonTextReader reader = new JsonTextReader(file))
            {
                try
                {
                    JObject json = (JObject)JToken.ReadFrom(reader);
                    BrushConverter bc = new BrushConverter();
                    if (json["light-icons"].ToString() == "true")
                    {
                        Icon.Source = new BitmapImage(new Uri("/Assets/Icon_Light.ico", UriKind.Relative));
                        icImage.Source = new BitmapImage(new Uri("/Assets/InfoIcon_Light.png", UriKind.Relative));
                        rfImage.Source = new BitmapImage(new Uri("/Assets/RefreshIcon_Light.png", UriKind.Relative));
                    }
                    else
                    {
                        Icon.Source = new BitmapImage(new Uri("/Assets/Icon.ico", UriKind.Relative));
                        icImage.Source = new BitmapImage(new Uri("/Assets/InfoIcon.png", UriKind.Relative));
                        rfImage.Source = new BitmapImage(new Uri("/Assets/RefreshIcon.png", UriKind.Relative));
                    }
                    //This part changes the highlight, it does not work.
                    BKG.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["background"].ToString());
                    BK1.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["background-1"].ToString());
                    BK2.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["background-2"].ToString());
                    BK3.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["background-2"].ToString());
                    customButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    Title.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    label5.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    pathList.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    setDirectoryButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    Configs.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    SaveSettings.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    LoadSettings.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    SettingsButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    Close.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    Minimize.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    heightText.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    widthText.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    scale1.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    ScaleInput.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    startButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    processButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    uploadButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    clearButton.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    BlackThresholdLabel.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    IntervalLabel.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    ClickDelayLabel.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    AlphaThresholdLabel.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    transThreshNumeric.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    blackThreshNumeric.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    intervalInput.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    clickdelayInput.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    bkgPIC.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["image-background"].ToString());
                    pathList.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["pattern-listbox"].ToString());
                    Configs.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["config-listbox"].ToString());
                    SaveSettings.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["saveconfig-button"].ToString());
                    LoadSettings.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["loadconfig-button"].ToString());
                    InfoButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["settings-info-buttons"].ToString());
                    SettingsButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["settings-info-buttons"].ToString());
                    customButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["pattern-button"].ToString());
                    RefreshDirectory.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["directory-buttons"].ToString());
                    setDirectoryButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["directory-buttons"].ToString());
                    transThreshNumeric.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["textbox-backgrounds"].ToString());
                    blackThreshNumeric.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["textbox-backgrounds"].ToString());
                    clickdelayInput.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["textbox-backgrounds"].ToString());
                    intervalInput.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["textbox-backgrounds"].ToString());
                    uploadButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["upload-buttons"].ToString());
                    clearButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["clear-buttons"].ToString());
                    ScaleInput.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["scale-textbox"].ToString());
                    heightInput.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["height-textbox"].ToString());
                    widthInput.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["width-textbox"].ToString());heightInput.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["height-textbox"].ToString());
                    widthInput.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    heightInput.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["text"].ToString());
                    ScaleSlider.Foreground = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["process-button"].ToString());
                    processButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["process-button"].ToString());
                    startButton.Background = (System.Windows.Media.Brush)bc.ConvertFrom(json["main"]["start-button"].ToString());
                }
                catch (Exception e)
                {
                    var showE = System.Windows.Forms.MessageBox.Show(new Form(), "Theme errored, resetting to dark. Do you want to see the error?", "Theme Error", MessageBoxButtons.YesNo, MessageBoxIcon.Asterisk);
                    switch (showE)
                    {
                        case (DialogResult)MessageBoxResult.Yes:
                            System.Windows.Forms.MessageBox.Show(new Form() { TopMost = true }, e.ToString(), "Theme Error", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                            break;
                    }
                    using (StreamWriter sw = File.CreateText(cpath + "\\themes\\theme.txt"))
                    {
                        sw.WriteLine("dark");
                    }
                }
            }
        }
        private void window_sizechanged(object sender, SizeChangedEventArgs e)
        {
            WinChr.CaptionHeight = System.Windows.Application.Current.MainWindow.Height;
        }
    }

    class Position
    {
        public int X { get; set; }
        public int Y { get; set; }
    }
}