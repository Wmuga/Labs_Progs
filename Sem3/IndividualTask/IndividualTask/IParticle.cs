using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace IndividualTask
{
    public partial class IParticle : Control
    {
        public IParticle()
        {
            InitializeComponent();
            SetDefaults();
        }

        public IParticle(IContainer container)
        {
            container.Add(this);

            InitializeComponent();
            SetDefaults();
        }

        public IParticle(int x, int y)
        {
            InitializeComponent();
            SetDefaults();
            this.Location = new Point(x,y);
        }

        private void SetDefaults()
        {
            this.Width = 1;
            this.Height = 1;
            this.BackColor = Color.White;
        }
        

        public virtual void Tick()
        {
            
        }
    }

    public class Atom : IParticle
    {
        
    }

    public class Molecule: IParticle
    {
        
    }

}