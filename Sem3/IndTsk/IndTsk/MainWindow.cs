using System;
using System.Collections.Generic;
using System.Drawing;
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
            _tree = new QuadTree(new Rectangle(0, 0, field.Width, field.Height));
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
                var drawBoundaries = (_drawState & 2) == 2;
                if (drawBoundaries) _tree.DrawBoundaries(_graphics, Color.Black);
                RebuildTree();
                if (drawBoundaries) _tree.DrawBoundaries(_graphics, Color.Aquamarine);
                _tree.ClearContents(_graphics, _drawState);
                _tree.Tick(1);
                _tree.DrawContents(_graphics, _drawState);
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

            if (changeDrawTreeBox.Checked) _drawState |= 0b10;
        }

        //Добавление частиц
        private static void Run(object o)
        {
            Application.Run((Form) o);
        }

        private void AddParticle()
        {
            var choose = new ChooseItemWindow();
            var t = new Thread(new ParameterizedThreadStart(Run));
            t.Start(choose);
            t.Join();

            if (NewParticle != null)
            {
                DebugLabel.Text = NewParticle.GetType().ToString().Split('.')[1];
                _tree.Append(NewParticle);
            }

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

        //Дерево необходимо перестраивать, т.к. элементы меняют свою позицию
        private void RebuildTree()
        {
            var newTree = new QuadTree(new Rectangle(0, 0, field.Width, field.Height));
            var contents = new List<IParticle>();
            _tree.GetContents(contents);
            SetReactions(contents);
            foreach (var element in contents) newTree.Append(element);
            _tree = newTree;
        }

        private void SetReactions(List<IParticle> reagents)
        {
            var newContents = new List<IParticle>();
            int i = 0;
            while (i < reagents.Count)
            {
                var thisReagent = reagents[i];
                var thisReagentLocation = TDim.TTT.Projection(thisReagent.GetCoords());
                var closestReagents = new List<IParticle>();
                _tree.GetContentsLimited(closestReagents,
                    new Rectangle(thisReagentLocation.X - 8, thisReagentLocation.Y - 8, 16, 16));
                i++;
                foreach (var anotherReagent in closestReagents)
                {
                    if (!thisReagent.Equals(anotherReagent))
                    {
                        var thisType = thisReagent.GetType().ToString().Split('.')[1];
                        var anotherType = anotherReagent.GetType().ToString().Split('.')[1];
                        if (thisType[0] == anotherType[0])
                        {
                            if (thisType[0] == 'A')
                            {
                                if (thisType == anotherType && thisType[1]!='P')
                                {
                                    var thisLocation = thisReagent.GetCoords();
                                    var anotherLocation = anotherReagent.GetCoords();
                                    var center = (thisLocation + anotherLocation) / 2;
                                    i--;
                                    reagents.Remove(thisReagent);
                                    reagents.Remove(anotherReagent);
                                    thisReagent.Clear(_graphics,_drawState);
                                    anotherReagent.Clear(_graphics,_drawState);
                                    switch (thisType[1])
                                    {
                                        case ('H'):
                                            newContents.Add(new MHydrogen(center.x,center.y,center.z));
                                            break;
                                        case ('O'):
                                            newContents.Add(new MOxygen(center.x,center.y,center.z));
                                            break;
                                        case ('C'):
                                            newContents.Add(new MChlorine(center.x,center.y,center.z));
                                            break;
                                    }
                                    break;
                                }
                            }
                            else
                            {
                                ///Not Implemented yet
                            }
                        }
                    }
                }
            }

            foreach (var item in newContents)
            {
                reagents.Add(item);
            }
        }
    }
}