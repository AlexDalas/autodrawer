using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AutoDrawer
{
    public partial class SettingsForm : Form
    {
        public static bool CursorOffset = false;
        public static bool FreeDraw = false;
        public static int xOffset = 0;
        public static int yOffset = 0;
        public SettingsForm()
        {
            InitializeComponent();
        }

        private void cursorOffsetCheck_CheckedChanged(object sender, EventArgs e)
        {
            CursorOffset = cursorOffsetCheck.Checked;
        }

        private void xNumeric_ValueChanged(object sender, EventArgs e)
        {
            xOffset = (int)xNumeric.Value;
        }

        private void yNumeric_ValueChanged(object sender, EventArgs e)
        {
            yOffset = (int)yNumeric.Value;
        }

        private void FreeDrawCheck_CheckedChanged(object sender, EventArgs e)
        {
            FreeDraw = FreeDrawCheck.Checked;
        }

        private void Form4_Load(object sender, EventArgs e)
        {
            FreeDrawCheck.Checked = FreeDraw;
            cursorOffsetCheck.Checked = CursorOffset;
            yNumeric.Value = yOffset;
            xNumeric.Value = xOffset;
        }
    }
}
