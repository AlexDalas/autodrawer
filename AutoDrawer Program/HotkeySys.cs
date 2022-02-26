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
        public delegate void CharEventHandler(object sender, Keys e);
        public static event CharEventHandler KeyPress;

        private static IKeyboardMouseEvents m_GlobalHook;

        private static void KeyPressed(object sender, KeyEventArgs e)
        {
            LogHandler.LogFile("Key Pressed: "+e.KeyCode.ToString());
            KeyPress?.Invoke(null, e.KeyCode);
        }
        public static void Subscribe()
        {
            m_GlobalHook = Hook.GlobalEvents();
            m_GlobalHook.KeyDown += KeyPressed;
        }
        
        public static void Unsubscribe()
        {
            m_GlobalHook.KeyDown -= KeyPressed;
            m_GlobalHook.Dispose();
        }
    }
}
