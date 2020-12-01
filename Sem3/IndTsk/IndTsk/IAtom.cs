using System;
using System.Drawing;
using TDim;

namespace IndividualTask
{
    //База для атомов, основана на частица
    public abstract class IAtom: IParticle
    {
        #region AdditionalParameters

        protected Electron[] Electrons;
        protected Point Location;
        protected Point PrevLocation;
        protected Color AtomColor;

        #endregion

        public override void Tick(double Coeff)
        {
            foreach (var electron in Electrons)
            {
                electron.Tick(Coeff);
            }
            Wander();
        }
        //"Шевеление" атома
        private void Wander()
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

        public override void Clear(Graphics e,int state)
        {
            if((state&1)==1) foreach (var el in Electrons) el.Clear(e,state);
            var pr = new Rectangle(PrevLocation.X,PrevLocation.Y,Width,Height);
            e.DrawEllipse(new Pen(Color.Black), pr);
            e.FillEllipse(new SolidBrush(Color.Black), pr);
        }
        public override void Draw(Graphics e,int state)
        {
            if((state&1)==1) foreach (var el in Electrons) el.Draw(e,state);
            
            var r = new Rectangle(Location.X,Location.Y,Width,Height);
            e.DrawEllipse(new Pen(AtomColor), r);
            e.FillEllipse(new SolidBrush(AtomColor), r);
        }
    }
    //Сами электроны
    public class AHydrogen : IAtom
    {
        public AHydrogen()
        {
            SetParameters();
        }
        public AHydrogen(int x, int y, int z)
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
            AtomColor = Color.Blue;
        }
    }

    public class AOxygen : IAtom
    {
        public AOxygen()
        {
            SetParameters();
        }
        public AOxygen(int x, int y, int z)
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
            AtomColor = Color.Red;
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
        
    }
    public class AChlorine : IAtom
    {
        public AChlorine()
        {
            SetParameters();
        }
        public AChlorine(int x, int y, int z)
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
            Electrons = new Electron[17];
            AtomColor = Color.Yellow;
            for (var i = 0; i < 17; i++)
            {
                if (i < 2)
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,1,Math.PI*i);
                }
                else if (i<10)
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,2,2*Math.PI/8*(i-2));
                }
                else
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,3,2*Math.PI/7*(i-10));
                }
                
            }
        }
    }
    public class APotassium : IAtom
    {
        public APotassium()
        {
            SetParameters();
        }
        public APotassium(int x, int y, int z)
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
            Electrons = new Electron[19];
            AtomColor = Color.Gray;
            for (var i = 0; i < 19; i++)
            {
                if (i < 2)
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,1,Math.PI*i);
                }
                else if (i<10)
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,2,2*Math.PI/8*(i-2));
                }
                else
                {
                    Electrons[i] = new Electron(BasePoint.x,BasePoint.y,BasePoint.z,3,2*Math.PI/9*(i-10));
                }
                
            }
        }
    }
}