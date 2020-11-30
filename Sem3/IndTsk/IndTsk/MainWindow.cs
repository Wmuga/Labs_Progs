using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;

namespace IndividualTask
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Additional();
        }

        private void Additional()
        {
            _particles = new List<IAtom>();
            _graphics = field.CreateGraphics();
        }
        
        public void UpdateContains()
        {
            while (true)
            {
                foreach (var particle in _particles)
                {
                    particle.Tick(1);
                    particle.Draw(_graphics);
                }
                Thread.Sleep(10);
            }
        }
        

        private void button1_Click(object sender, EventArgs e)
        {
            Program.t.Abort();
            var r = new Random();
            IAtom p;
            if (r.Next()%2==0) p = new Oxygen((r.Next()%field.Width/2-field.Width/4),(r.Next()%field.Width/2-field.Width/4),(int)(r.Next()%field.Height-field.Height/5.5));
            else p = new Hydrogen((r.Next()%field.Width/2-field.Width/4),(r.Next()%field.Width/2-field.Width/4),(int)(r.Next()%field.Height-field.Height/5.5));

            _particles.Add(p);
            Program.t = new Thread(UpdateContains);
            Program.t.Start();
        }

        private List<IAtom> _particles;
        private Graphics _graphics;
    }
}