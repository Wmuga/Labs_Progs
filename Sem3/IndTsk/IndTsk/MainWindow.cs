using System;
using System.Threading;
using System.Windows.Forms;

namespace IndividualTask
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public void UpdateContains()
        {
            while (true)
            {
                foreach (var particle in field.Controls)
                {
                    ((IParticle) particle).Tick(1);
                }

                Thread.Sleep(10);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var r = new Random();
            var p = new IParticle(r.Next()%field.Width-field.Width/2,r.Next()%field.Width-field.Width/2,r.Next()%field.Height-field.Height/2);
            field.Controls.Add(p);
        }


    }
}