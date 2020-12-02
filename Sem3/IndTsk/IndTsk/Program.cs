using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IndividualTask
{
    static class Program
    {
        public static Thread t;
        public static Form1 f;
        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            f = new Form1();
            t = new Thread(f.UpdateContains);
            t.Start();
            Application.Run(f);
            t.Abort();
        }
    }
}