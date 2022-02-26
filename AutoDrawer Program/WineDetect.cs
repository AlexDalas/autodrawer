using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace AutoDrawer
{
    class WineDetect
    {
        // Converted C++ to C#:
        // https://stackoverflow.com/questions/7372388/determine-whether-a-program-is-running-under-wine-at-runtime

        //-- Below is for detection of Wine, just incase user is running under linux, we can check and make it work --\\
        public static bool HasChecked;
        public static bool WineDetected;
        public static bool RunningNT;

        [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        public static extern IntPtr GetModuleHandle([MarshalAs(UnmanagedType.LPWStr)] in string lpModuleName);
        [DllImport("kernel32", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        static extern IntPtr GetProcAddress(IntPtr hModule, string procName);
        // love you pinvoke.net, giving me the dllimports <3

        public static void RunChecks() // Runs the checks for Wine.
        {
            IntPtr ntdllHandle = GetModuleHandle("ntdll.dll");
            RunningNT = (int)ntdllHandle != 0;
            Console.WriteLine(RunningNT);
            if (RunningNT)
            {
                IntPtr WineVersion = GetProcAddress(ntdllHandle, "wine_get_version");

                WineDetected = (int)WineVersion != 0;

                /* For later, if I add more functions
                if ((int)WineVersion != 0) { WineDetected = true; }
                else { WineDetected = false; }
                */
            }
            else { RunningNT = false; }
            HasChecked = true;
        }

        public static void FakeWine(bool Toggle) // Just for debugging only!
        {
            WineDetected = Toggle;
        }
    }
}
