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
            _molecules = new List<IMolecule>();
            _graphics = field.CreateGraphics();
            _drawState = 0;
            _update = true;
        }
        //Функция на обновление и отрисовку частиц
        public void UpdateContains()
        {
            while (_update)
            {
                foreach (var molecule in _molecules)
                {
                    molecule.Clear(_graphics,_drawState);
                    molecule.Tick(1);
                    molecule.Draw(_graphics,_drawState);
                }
                foreach (var particle in _particles)
                {
                    particle.Tick(1);
                    particle.Clear(_graphics,_drawState);
                    particle.Draw(_graphics,_drawState);
                }
                Thread.Sleep(10);
            }
        }
        private int _drawState;
        private delegate void coveredtsk();
        private bool _update;
        private List<IAtom> _particles;
        private List<IMolecule> _molecules;
        private Graphics _graphics;
        //Рисовать электроны или нет
        private void ChangeDrawingState()
        {
            foreach (var molecule in _molecules) molecule.Clear(_graphics, _drawState);

            foreach (var particle in _particles)
            {
                particle.Tick(1);
                particle.Clear(_graphics, _drawState);
            }
            
            if ((_drawState & 1) == 1) _drawState -= 1;
            else _drawState += 1;
        }
        //Добавление частиц
        private void AddParticle()
        {
            var r = new Random();
            IAtom p;
            int x = r.Next()%field.Width/2 - field.Width/4;
            int y = r.Next()%field.Width/2 - field.Width/4;
            int z = r.Next() % (field.Height-(int)((x+y)*Math.Sin(Math.PI/6)))-r.Next()&field.Height/4;
            if (r.Next()%2==0) p = new APotassium(x,y,z);
            else p = new AChlorine(x,y,z);

            _particles.Add(p);
        }

        private void AddMolecule()
        {
            var r = new Random();
            IMolecule p;
            int x = r.Next()%field.Width/2 - field.Width/4;
            int y = r.Next()%field.Width/2 - field.Width/4;
            int z = r.Next() % (field.Height-(int)((x+y)*Math.Sin(Math.PI/6)))-r.Next()&field.Height/4;
            _molecules.Add(new MChlorine(x,y,z));
        }
        //Вызов нужных функций
        private void button1_Click(object sender, EventArgs e)
        {
            DoWithStoppingThread(AddMolecule);
        }
        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            DoWithStoppingThread(ChangeDrawingState);
        }
        //Обложка на приостановку потока и выполнение самой функции
        private void DoWithStoppingThread(coveredtsk tsk)
        {
            _update = false;
            Program.t.Join();
            tsk();
            _update = true;
            Program.t = new Thread(UpdateContains);
            Program.t.Start();
        }
        
    }
}