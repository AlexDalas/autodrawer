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

        [DllImport("kernel32.dll")]
        public static extern IntPtr GetModuleHandle(string moduleName);
        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        static extern IntPtr GetProcAddress(IntPtr hModule, string procName);
        // stinky pinvoke GetModuleHandle was changed to a wrong answer.

        public static void RunChecks() // Runs the checks for Wine.
        {
            IntPtr ntdllHandle = GetModuleHandle("ntdll.dll");
            Console.WriteLine(ntdllHandle);
            RunningNT = (int)ntdllHandle != 0;
            if (RunningNT)
            {
                IntPtr WineVersion = GetProcAddress(ntdllHandle, "wine_get_version");

                WineDetected = (int)WineVersion != 0;
                Console.WriteLine(WineVersion);

                /* For later, if I add more functions
                if ((int)WineVersion != 0) { WineDetected = true; }
                else { WineDetected = false; }
                */
            }
            else { WineDetected = false; }
            HasChecked = true;
        }

        public static void FakeWine(bool Toggle) // Just for debugging only!
        {
            WineDetected = Toggle;
        }
    }
}
