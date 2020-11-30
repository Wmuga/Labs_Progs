using System;
using System.Drawing;
using Projection;

namespace IndividualTask
{
    public abstract class IAtom: IParticle
    {
        #region AdditionalParameters

        protected Electron[] Electrons;
        protected Point Location;
        protected Point PrevLocation;

        #endregion

        public override void Tick(double Coeff)
        {
            foreach (var electron in Electrons)
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
            PrevLocation = Location;
            Location = TTT.Projection(BasePoint);

            foreach (var electron in Electrons)
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
            Width = 4;
            Height = 4;
            BasePoint = new TPoint(0,0,0);
            Location = TTT.Projection(BasePoint);
            Electrons = new Electron[1];
            Electrons[0] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z);
        }
        public override void Draw(Graphics e)
        {
            Electrons[0].Draw(e);
            var r = new Rectangle(Location.X,Location.Y,Width,Height);
            var pr = new Rectangle(PrevLocation.X,PrevLocation.Y,Width,Height);
            e.DrawEllipse(new Pen(Color.Black), pr);
            e.FillEllipse(new SolidBrush(Color.Black), pr);
            e.DrawEllipse(new Pen(Color.Blue), r);
            e.FillEllipse(new SolidBrush(Color.Blue), r);
        }
    }

    public class Oxygen : IAtom
    {
        public Oxygen()
        {
            SetParameters();
        }
        public Oxygen(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);

        }

        private void SetParameters()
        {
            Width = 4;
            Height = 4;
            BasePoint = new TPoint(0,0,0);
            Location = TTT.Projection(BasePoint);
            Electrons = new Electron[8];
            for (var i = 0; i < 8; i++)
            {
                if (i < 2)
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,1,Math.PI*i);
                }
                else
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,2,2*Math.PI/6*(i-2));
                }
                
            }
        }
        public override void Draw(Graphics e)
        {
            foreach (var el in Electrons) el.Draw(e);
            
            var r = new Rectangle(Location.X,Location.Y,Width,Height);
            var pr = new Rectangle(PrevLocation.X,PrevLocation.Y,Width,Height);
            e.DrawEllipse(new Pen(Color.Black), pr);
            e.FillEllipse(new SolidBrush(Color.Black), pr);
            e.DrawEllipse(new Pen(Color.Red), r);
            e.FillEllipse(new SolidBrush(Color.Red), r);
        }
    }
}