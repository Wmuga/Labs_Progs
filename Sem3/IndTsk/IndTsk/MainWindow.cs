using System;
using System.Collections.Generic;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;
using IndTsk;
using Tree;

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
            _tree = new QuadTree(new Rectangle(0,0,field.Width,field.Height));
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
                _tree.DrawBoundaries(_graphics,Color.White);
                _tree.ClearContents(_graphics,_drawState);
                _tree.Tick(1);
                _tree.DrawContents(_graphics,_drawState);
                Thread.Sleep(10);
            }
        }
        private int _drawState;
        private delegate void coveredtsk();
        private bool _update;
        private QuadTree _tree;
        private Graphics _graphics;
        public IParticle NewParticle;
        //Рисовать электроны или нет
        private void ChangeDrawingState()
        {
            _tree.ClearContents(_graphics,_drawState);
            
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

            _tree.Append(NewParticle);
            
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