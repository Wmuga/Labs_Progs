using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace IndividualTask
{
    partial class IParticle
    {
        private IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            base.Dispose(disposing);
        }
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
        }
        

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            var loc = Projection.TTT.Projection(this.basePoint);
            e.Graphics.DrawRectangle(new Pen(BackColor),loc.X,loc.Y-10,3,10);
            Draw(e);
        }

        private void Draw(PaintEventArgs e)
        {
            var graphTool = e.Graphics;
            graphTool.DrawRectangle(new Pen(BackColor),Location.X,Location.Y,Width,Height);

        }
        
        #region Parameters

        private TPoint basePoint;
        private double baseRadSpeed;
        private double angle;
        private TPoint radius = new TPoint(10,0,0);

        #endregion
    }
}