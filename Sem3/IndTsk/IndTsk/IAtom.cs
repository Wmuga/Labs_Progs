using System;
using System.Drawing;
using Projection;

namespace IndividualTask
{
    public abstract class IAtom: IParticle
    {
        #region AdditionalParameters

        protected Electron[] _electrons;
        protected Point location;
        protected Point prev_location;

        #endregion

        public override void Tick(double Coeff)
        {
            foreach (var electron in _electrons)
            {
                electron.Tick(Coeff);
            }
            Wander();
        }

        protected virtual void Wander()
        {
            var rnd = new Random();
            var speed = new TPoint(rnd.Next()%3-1,rnd.Next()%3-1,rnd.Next()%3-1);
            BasePoint += speed;
            prev_location = location;
            location = TTT.Projection(BasePoint);

            foreach (var electron in _electrons)
            {
                electron.SetCoords(BasePoint);
            }
        }
    }

    public class Hydrogen : IAtom
    {
        public Hydrogen()
        {
            SetParameters();
        }
        public Hydrogen(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);

        }

        private void SetParameters()
        {
            Width = 1;
            Height = 1;
            BasePoint = new TPoint(0,0,0);
            location = TTT.Projection(BasePoint);
            _electrons = new Electron[1];
            _electrons[0] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z);
        }
        public override void Draw(Graphics e)
        {
            _electrons[0].Draw(e);
            var r = new Rectangle(location.X,location.Y,4,4);
            var pr = new Rectangle(prev_location.X,prev_location.Y,4,4);
            e.DrawEllipse(new Pen(Color.Black), pr);
            e.FillEllipse(new SolidBrush(Color.Black), pr);
            e.DrawEllipse(new Pen(Color.Blue), r);
            e.FillEllipse(new SolidBrush(Color.Blue), r);
        }
    }
}