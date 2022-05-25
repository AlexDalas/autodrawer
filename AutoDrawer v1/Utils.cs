using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutoDrawer
{
    public class Utils
    {
        public static event EventHandler refTheme;

        public static void UpdateUI()
        {
            EventHandler handler = refTheme;
            handler?.Invoke(null, null);
        }
    }
}
