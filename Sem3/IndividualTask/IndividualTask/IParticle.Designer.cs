using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace IndividualTask
{
    partial class IParticle
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
        }

        #endregion

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            Draw(e);
        }

        public void Draw(PaintEventArgs e)
        {
            var graphTool = e.Graphics;
            graphTool.DrawRectangle(new Pen(BackColor),Location.X,Location.Y,Width,Height);
        }
        
        #region Parameters

        private TPoint BasePoint;
        private double RadSpeed;

        #endregion
    }
}