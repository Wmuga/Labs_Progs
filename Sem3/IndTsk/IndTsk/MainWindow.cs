using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
using IndTsk;
using TDim;
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
            _tree = new QuadTree(new Rectangle(0, 0, field.Width, field.Height));
            _graphics = field.CreateGraphics();
            _drawState = 0;
            _tempCoeff = 0;
            _update = true;
            NewParticle = null;
            field.MouseClick += field_Click;
        }
        

        //Функция на обновление и отрисовку частиц
        public void UpdateContains()
        {
            while (_update)
            {
                var tStart = DateTime.Now;
                var drawBoundaries = (_drawState & 2) == 2;
                if (drawBoundaries) _tree.DrawBoundaries(_graphics, Color.Black);
                RebuildTree();
                _tree.ClearContents(_graphics,_drawState);
                if (drawBoundaries) _tree.DrawBoundaries(_graphics, Color.Aquamarine);
                _tree.Tick(_tempCoeff);
                _tree.DrawContents(_graphics, _drawState);
                Thread.Sleep(10);
                var tPassed = DateTime.Now.Subtract(tStart);
                if (tPassed.TotalSeconds!=0) FPSLabel.Text = (int)(1.0 / tPassed.TotalSeconds) + " FPS";
            }
        }

        private int _drawState;

        private delegate void coveredtsk();

        private bool _update;
        private QuadTree _tree;
        private Graphics _graphics;
        private double _tempCoeff;

        public IParticle NewParticle;

        //Рисовать электроны или нет
        private void ChangeDrawingState()
        {
            if (!showElectronsCheckBox.Checked && (_drawState & 1) == 1)
            {
                _tree.ClearContents(_graphics, _drawState);
                _drawState -= 1;
            }

            if (showElectronsCheckBox.Checked) _drawState |= 1;

            if (!changeDrawTreeBox.Checked && (_drawState & 2) == 2)
            {
                _tree.DrawBoundaries(_graphics, Color.Black);
                _drawState -= 2;
            }

            if (changeDrawTreeBox.Checked)
            {
                _drawState |= 0b10;
            }
        }

        //Добавление частиц
        private static void Run(object o)
        {
            Application.Run((Form) o);
        }
        
        
        private void AddParticleCoords(TPoint coords)
        {
            var choose = new ChooseItemWindow();
            var t = new Thread(new ParameterizedThreadStart(Run));
            t.Start(choose);
            t.Join();

            if (NewParticle != null)
            {
                DebugLabel.Text = "Создано:" + NewParticle.GetType().ToString().Split('.')[1];
                NewParticle.SetCoords(coords);
                _tree.Append(NewParticle);
            }

            NewParticle = null;
        }
        //Вызов нужных функций

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            DoWithStoppingThread(ChangeDrawingState);
        }
        private void field_Click(object sender, MouseEventArgs e)
        {
            _update = false;
            Program.t.Join();
            var particleCoords = new TPoint(((e.X-field.Width/2)/Math.Cos(Math.PI/6)),0,-e.Y+field.Height/2+(e.X-field.Width/2)*Math.Cos(Math.PI/6));
            AddParticleCoords(particleCoords);
            _update = true;
            Program.t = new Thread(UpdateContains);
            Program.t.Start();
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

        //Дерево необходимо перестраивать, т.к. элементы меняют свою позицию
        private void RebuildTree()
        {
            var newTree = new QuadTree(new Rectangle(0, 0, field.Width, field.Height));
            var contents = new List<IParticle>();
            _tree.GetContents(contents);
            ApplyForce(contents);
            SetReactions(contents);
            foreach (var element in contents) newTree.Append(element);
            _tree = newTree;
        }

        private void ClearAll()
        {
            _tree.DrawBoundaries(_graphics,Color.Black);
            _tree.ClearContents(_graphics,_drawState);
            _tree = new QuadTree(new Rectangle(0, 0, field.Width, field.Height));
        }
        
        private void clearButton_Click(object sender, EventArgs e)
        {
            DoWithStoppingThread(ClearAll);
            DebugLabel.Visible = true;
            DebugLabel.Text = "";
        }

        private void TemperatureControl_Scroll(object sender, ScrollEventArgs e)
        {
            _tempCoeff = TempertureControl.Value / 10.0;
            DebugLabel.Text = _tempCoeff.ToString();
        }

        private void DebugLabel_Click(object sender, EventArgs e)
        {
            DebugLabel.Visible = false;
        }
    }
}