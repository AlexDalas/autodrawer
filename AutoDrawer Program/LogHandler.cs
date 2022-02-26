using System;
using System.IO;

namespace AutoDrawer
{
    public class LogHandler
    {
        public static bool LogsEnabled;

        public static void LogFile(string str)
        {
            str = str + " (" + DateTime.Now.ToString("hh:mm:ss") + ")";
            //ConsoleWindow.ListConsole.Text = str + "\n" + ConsoleWindow.ListConsole.Text;
            Console.WriteLine(str);
            Window3 win = new Window3();
            if (LogsEnabled)
            {
                var spath = @"%AppData%\AutoDraw\logs\";
                spath = Environment.ExpandEnvironmentVariables(spath);
                if (!Directory.Exists(spath)) Directory.CreateDirectory(spath);
                spath = @"%AppData%\AutoDraw\logs\" + DateTime.Now.ToString("yyyyMMdd") + ".log";
                spath = Environment.ExpandEnvironmentVariables(spath);
                using (FileStream fs = new FileStream(spath, FileMode.Append, FileAccess.Write))
                using (StreamWriter sw = new StreamWriter(fs))
                {
                    sw.WriteLine(str+"\n");
                }
            }
        }
    }
}
