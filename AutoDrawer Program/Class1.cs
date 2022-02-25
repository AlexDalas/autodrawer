using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Gma.System.MouseKeyHook;

namespace AutoDrawer
{
    class HotkeySystem
    {
        private IKeyboardMouseEvents m_GlobalHook;

        public void Subscribe()
        {
            m_GlobalHook = Hook.GlobalEvents();
            m_GlobalHook.KeyPress += KeyPressed;
        }

        public static void KeyPressed(object sender, KeyPressEventArgs e)
        {

        }

        public void Unsubscribe()
        {
            m_GlobalHook.KeyPress -= KeyPressed;
            m_GlobalHook.Dispose();
        }
    }
}
