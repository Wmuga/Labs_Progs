using System.Drawing;
using TDim;

namespace IndividualTask
{
    //Основа для всех молкул
    public abstract class IMolecule:IParticle
    {
        public override void Tick(double Coeff)
        {
            Wander();
            foreach (var atom in ContainedAtoms)
            {
                atom.Tick(Coeff);
                var atomLocation = atom.GetCoords();
                if (TTT.Radius(atomLocation, BasePoint) > 8) atom.SetCoords(atomLocation - (atomLocation-BasePoint)/8);
                if (TTT.Radius(atomLocation, BasePoint) < 2) atom.SetCoords(atomLocation + (atomLocation-BasePoint)*1.5);
            }
        }

        public override void Clear(Graphics e, int state)
        {
            DrawLineBetweenAtoms(e,Color.Black);
            foreach (var atom in ContainedAtoms)
            {
                atom.Clear(e,state);
            }
        }

        public override void Draw(Graphics e, int state)
        {
            DrawLineBetweenAtoms(e,Color.White);
            foreach (var atom in ContainedAtoms)
            {
                atom.Draw(e,state);
            }
        }
        //Линия, "соединяющая" атомы в молекулы
        protected void DrawLineBetweenAtoms(Graphics e, Color color)
        {
            for (int i = 0; i < ContainedAtoms.Length-1; i++)
            {
                var fLocation = TDim.TTT.Projection(ContainedAtoms[i].GetCoords());
                fLocation = new Point(fLocation.X+3,fLocation.Y+2);
                var sLocation = TDim.TTT.Projection(ContainedAtoms[i+1].GetCoords());
                sLocation = new Point(sLocation.X,sLocation.Y+2);
                e.DrawLine(new Pen(color),fLocation,sLocation);
            }
        }
        
        private void Wander()
        {
            var speed = new TPoint(Program.r.Next()%3-1,Program.r.Next()%3-1,Program.r.Next()%3-1);
            BasePoint += speed;

            foreach (var atom in ContainedAtoms)
            {
                atom.SetCoords(atom.GetCoords()+speed);
            }
            var location = TTT.Projection(BasePoint);
            
            if (location.X>=802)
                BasePoint= new TPoint(BasePoint.x-3,BasePoint.y,BasePoint.z);
            if (location.X<=0)
                BasePoint= new TPoint(BasePoint.x,BasePoint.y-3,BasePoint.z);
            if (location.Y>=367)
                BasePoint= new TPoint(BasePoint.x,BasePoint.y,BasePoint.z+3);
            if (location.Y<=0)
                BasePoint= new TPoint(BasePoint.x,BasePoint.y,BasePoint.z-3);

        }


        #region AdditonalParameters

        protected IAtom[] ContainedAtoms;

        #endregion
    }
    //Молекулы
    public class MHydrogen : IMolecule
    {
        public MHydrogen()
        {
            SetParameters();
            SetAtoms();
        }

        public MHydrogen(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            SetAtoms();
        }
        private void SetParameters()
        {
            BasePoint = new TPoint(0,0,0);
        }

        private void SetAtoms()
        {
            ContainedAtoms = new IAtom[2];
            ContainedAtoms[0]= new AHydrogen(BasePoint.x-10,BasePoint.y,BasePoint.z);
            ContainedAtoms[1]= new AHydrogen(BasePoint.x,BasePoint.y-10,BasePoint.z);
        }
        
    }
    public class MOxygen : IMolecule
    {
        public MOxygen()
        {
            SetParameters();
            SetAtoms();
        }

        public MOxygen(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            SetAtoms();
        }
        private void SetParameters()
        {
            BasePoint = new TPoint(0,0,0);
        }

        private void SetAtoms()
        {
            ContainedAtoms = new IAtom[2];
            ContainedAtoms[0]= new AOxygen(BasePoint.x-10,BasePoint.y,BasePoint.z);
            ContainedAtoms[1]= new AOxygen(BasePoint.x,BasePoint.y-10,BasePoint.z);
        }
    }
    
    public class MChlorine : IMolecule
    {
        public MChlorine()
        {
            SetParameters();
            SetAtoms();
        }

        public MChlorine(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            SetAtoms();
        }
        private void SetParameters()
        {
            BasePoint = new TPoint(0,0,0);
        }

        private void SetAtoms()
        {
            ContainedAtoms = new IAtom[2];
            ContainedAtoms[0]= new AChlorine(BasePoint.x-10,BasePoint.y,BasePoint.z);
            ContainedAtoms[1]= new AChlorine(BasePoint.x,BasePoint.y-10,BasePoint.z);
        }
        
    }
    public class MHCl : IMolecule
    {
        public MHCl()
        {
            SetParameters();
            SetAtoms();
        }

        public MHCl(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            SetAtoms();
        }
        private void SetParameters()
        {
            BasePoint = new TPoint(0,0,0);
        }

        private void SetAtoms()
        {
            ContainedAtoms = new IAtom[2];
            ContainedAtoms[0]= new AHydrogen(BasePoint.x-10,BasePoint.y,BasePoint.z);
            ContainedAtoms[1]= new AChlorine(BasePoint.x,BasePoint.y-10,BasePoint.z);
        }
        
    }
     public class MKCl : IMolecule
    {
        public MKCl()
        {
            SetParameters();
            SetAtoms();
        }

        public MKCl(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            SetAtoms();
        }
        private void SetParameters()
        {
            BasePoint = new TPoint(0,0,0);
        }

        private void SetAtoms()
        {
            ContainedAtoms = new IAtom[2];
            ContainedAtoms[0]= new APotassium(BasePoint.x-10,BasePoint.y,BasePoint.z);
            ContainedAtoms[1]= new AChlorine(BasePoint.x,BasePoint.y-10,BasePoint.z);
        }
    }
    public class MKOH : IMolecule
    {
        public MKOH()
        {
            SetParameters();
            SetAtoms();
        }

        public MKOH(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            SetAtoms();
        }
        private void SetParameters()
        {
            BasePoint = new TPoint(0,0,0);
        }

        private void SetAtoms()
        {
            ContainedAtoms = new IAtom[3];
            ContainedAtoms[0]= new APotassium(BasePoint.x-10,BasePoint.y,BasePoint.z);
            ContainedAtoms[1]= new AOxygen(BasePoint.x,BasePoint.y,BasePoint.z);
            ContainedAtoms[2]= new AHydrogen(BasePoint.x,BasePoint.y-10,BasePoint.z);
        }
    }
    public class MHOH : IMolecule
    {
        public MHOH()
        {
            SetParameters();
            SetAtoms();
        }

        public MHOH(int x, int y, int z)
        {
            SetParameters();
            BasePoint = new TPoint(x,y,z);
            SetAtoms();
        }
        private void SetParameters()
        {
            BasePoint = new TPoint(0,0,0);
        }

        private void SetAtoms()
        {
            ContainedAtoms = new IAtom[3];
            ContainedAtoms[0]= new AHydrogen(BasePoint.x-10,BasePoint.y,BasePoint.z);
            ContainedAtoms[1]= new AOxygen(BasePoint.x,BasePoint.y,BasePoint.z);
            ContainedAtoms[2]= new AHydrogen(BasePoint.x,BasePoint.y-10,BasePoint.z);
        }
    }
     
}