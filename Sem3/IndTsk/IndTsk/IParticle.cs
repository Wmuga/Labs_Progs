using System;
using System.ComponentModel;
using System.Drawing;
using System.Security.Cryptography.X509Certificates;
using System.Windows.Forms;
using Projection;

namespace IndividualTask
{
    public abstract class IParticle
    {

        public abstract void Tick(double Coeff);

        public abstract void Draw(Graphics e);
        
        public void SetCoords(int x, int y, int z)
        {
            BasePoint= new TPoint(x,y,z);
        }
        
        public void SetCoords(TPoint p)
        {
            BasePoint= p;
        }

        public TPoint GetCoords()
        {
            return BasePoint;
        }

        #region Parameters

        protected TPoint BasePoint;
        protected int Width;
        protected int Height;
        
        #endregion
    }

    public class Electron : IParticle
    {
        public Electron()
        {
            SetParameters();
        }

        public Electron(int x, int y, int z,double angle =0)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            _angle = angle;

        }

        private void SetParameters()
        {
            Width = 1;
            Height = 1;
            _radius = new TPoint(20,0,0);
            _angle = 0;
            BasePoint = new TPoint(0,0,0);
            _baseRadSpeed = Math.PI / 180;
        }

        public override void Tick(double Coeff)
        {
            _angle += _baseRadSpeed * Coeff;
            if (_angle >= Math.PI * 2) _angle = 0;
            _prevLocation = new Point(_location.X,_location.Y);
            _location = TTT.Projection(BasePoint + TTT.RotateZ(_radius, _angle));
        }

        public override void Draw(Graphics e)
        {
            e.DrawRectangle(new Pen(Color.White),_location.X,_location.Y,1,1);
            e.DrawRectangle(new Pen(Color.Black),_prevLocation.X,_prevLocation.Y,1,1);
        }

        #region AdditionalParameters
        
        private double _baseRadSpeed;
        private double _angle;
        private Point _location;
        private Point _prevLocation;
        private TPoint _radius;

        #endregion
    }
}