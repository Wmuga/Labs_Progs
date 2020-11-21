using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using Projection;

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

        public IParticle(int x, int y,int z)
        {
            InitializeComponent();
            SetDefaults();
            basePoint = new TPoint(x,y,z);
            this.Location = TTT.Projection(basePoint);
        }

        private void SetDefaults()
        {
            Width = 1;
            Height = 1;
            BackColor = Color.White;
            baseRadSpeed = 0.01745;
            angle = 0;
        }
        

        public virtual void Tick(double tCoeff)
        {
            if (angle < 2 * Math.PI) angle += baseRadSpeed * tCoeff;
            else angle = 0;
            Location = TTT.Projection(basePoint + TTT.RotateZ(radius,angle));
        }
/*
        protected void CheckCoordinates()
        {
            const int w = 802;
            const int h = 367;
            var x = Location.X;
            var y =  Location.Y;
            if  (Location.X > w) x = w * 2 - Location.X;
            if (Location.Y > h) y = h * 2 - Location.Y;
            Location = new Point(x,y);
        }*/
    }

    public class Atom : IParticle
    {
        private void Draw(PaintEventArgs e)
        {
            
        }
        
    }

    public class Molecule: IParticle
    {
        
    }

}