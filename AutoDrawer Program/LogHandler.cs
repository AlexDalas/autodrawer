using System;
using System.IO;

namespace AutoDrawer
{
    public class LogHandler
    {
        public static bool LogsEnabled;

        public delegate void LogEventHandler(object sender, string NewLog);
        public static event LogEventHandler LogSent;
        public static void LogFile(string str)
        {
            str = str + " (" + DateTime.Now.ToString("hh:mm:ss") + ")";
            //ConsoleWindow.ListConsole.Text = str + "\n" + ConsoleWindow.ListConsole.Text;
            LogSent?.Invoke(null, str + "\n");
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
