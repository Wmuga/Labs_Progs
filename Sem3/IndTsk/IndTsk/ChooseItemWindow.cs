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

        private void buttonH_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = _isMolecule;
            if (_isMolecule) Program.f.NewParticle = new MHydrogen(nCoords.x,nCoords.y,nCoords.z);
            else Program.f.NewParticle = new AHydrogen(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private void buttonCl_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = _isMolecule;
            if (_isMolecule) Program.f.NewParticle = new MChlorine(nCoords.x,nCoords.y,nCoords.z);
            else Program.f.NewParticle = new AChlorine(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private void buttonO_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = _isMolecule;
            if (_isMolecule) Program.f.NewParticle = new MOxygen(nCoords.x,nCoords.y,nCoords.z);
            else Program.f.NewParticle = new AOxygen(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private void buttonK_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = false;
            Program.f.NewParticle = new APotassium(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private void buttonW_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = true;
            Program.f.NewParticle = new MHOH(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private void buttonHCl_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = true;
            Program.f.NewParticle = new MHCl(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private void buttonKCl_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = true;
            Program.f.NewParticle = new MKCl(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private void buttonKOH_Click(object sender, EventArgs e)
        {
            var nCoords = GetRandCoords();
            Program.f.IsMolecule = true;
            Program.f.NewParticle = new MKOH(nCoords.x,nCoords.y,nCoords.z);
            Close();
        }

        private TDim.TPoint GetRandCoords()
        {
            var r = new Random();
            const int fw = 802;
            const int fh = 367;
            int x = r.Next()%fw/2 - fw/4;
            int y = r.Next()%fw/2 - fw/4;
            int z = r.Next() % (fh-(int)((x+y)*Math.Sin(Math.PI/6)))-r.Next()&fh/4;
            return new TPoint(x,y,z);
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            _isMolecule = !_isMolecule;
        }

        private bool _isMolecule = false;
    }
}