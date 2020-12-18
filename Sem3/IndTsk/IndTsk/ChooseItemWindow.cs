using System;
using System.Windows.Forms;
using IndividualTask;
using TDim;

namespace IndTsk
{
    public partial class ChooseItemWindow : Form
    {
        public ChooseItemWindow()
        {
            InitializeComponent();
        }
        //Создание нового объекта на основе выбора пользователя
        private void buttonH_Click(object sender, EventArgs e)
        {
            if (_isMolecule) Program.f.NewParticle = new MHydrogen();
            else Program.f.NewParticle = new AHydrogen();
            Close();
        }

        private void buttonCl_Click(object sender, EventArgs e)
        {
            if (_isMolecule) Program.f.NewParticle = new MChlorine();
            else Program.f.NewParticle = new AChlorine();
            Close();
        }

        private void buttonO_Click(object sender, EventArgs e)
        {
            if (_isMolecule) Program.f.NewParticle = new MOxygen();
            else Program.f.NewParticle = new AOxygen();
            Close();
        }

        private void buttonK_Click(object sender, EventArgs e)
        {
            Program.f.NewParticle = new APotassium();
            Close();
        }

        private void buttonW_Click(object sender, EventArgs e)
        {
            Program.f.NewParticle = new MHOH();
            Close();
        }

        private void buttonHCl_Click(object sender, EventArgs e)
        {
            Program.f.NewParticle = new MHCl();
            Close();
        }

        private void buttonKCl_Click(object sender, EventArgs e)
        {
            Program.f.NewParticle = new MKCl();
            Close();
        }

        private void buttonKOH_Click(object sender, EventArgs e)
        {
            Program.f.NewParticle = new MKOH();
            Close();
        }
        

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            _isMolecule = !_isMolecule;
        }

        private bool _isMolecule = false;
    }
}