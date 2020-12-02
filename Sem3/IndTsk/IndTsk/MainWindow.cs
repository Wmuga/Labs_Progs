using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
using IndTsk;

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
            _atoms = new List<IParticle>();
            _molecules = new List<IParticle>();
            _graphics = field.CreateGraphics();
            _drawState = 0;
            _update = true;
            NewParticle = null;
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
                foreach (var particle in _atoms)
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
        private List<IParticle> _atoms;
        private List<IParticle> _molecules;
        private Graphics _graphics;
        public IParticle NewParticle;
        public bool IsMolecule;
        //Рисовать электроны или нет
        private void ChangeDrawingState()
        {
            foreach (var molecule in _molecules) molecule.Clear(_graphics, _drawState);

            foreach (var particle in _atoms)
            {
                particle.Tick(1);
                particle.Clear(_graphics, _drawState);
            }
            
            if ((_drawState & 1) == 1) _drawState -= 1;
            else _drawState += 1;
        }

        //Добавление частиц
        private static void Run(object o)
        {
            Application.Run((Form)o);
        }
        private void AddParticle()
        {
            var choose = new ChooseItemWindow();
            var t = new Thread(new ParameterizedThreadStart(Run));
            t.Start(choose);
            t.Join();

            if (IsMolecule) _molecules.Add(NewParticle);
            else _atoms.Add(NewParticle);
            
            NewParticle = null;
        }
        
        //Вызов нужных функций
        private void button1_Click(object sender, EventArgs e)
        {
            DoWithStoppingThread(AddParticle);
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