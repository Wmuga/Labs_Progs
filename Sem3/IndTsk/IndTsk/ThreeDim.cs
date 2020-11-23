using System;
using System.Drawing;
using IndividualTask;

namespace IndividualTask
{
    public class TVector
    {
        #region parameters

        private int x;
        private int y;
        private int z;

        #endregion

        #region Constructors

        public TVector()
        {
            SetCoords(0,0,0);
        }

        public TVector(int x, int y, int z)
        {
            SetCoords(x,y,z);
        }

        public TVector(TPoint coords)
        {
            SetCoords(coords);
        }

        #endregion
        
        public void SetCoords(TPoint coords)
        {
            this.x = coords.x;
            this.y = coords.y;
            this.z = coords.z;
        }

        public void SetCoords(int x, int y, int z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    public struct TPoint
    {
        public int x;
        public int y;
        public int z;

        public TPoint(int _x, int _y, int _z)
        {
            x = _x;
            y = _y;
            z = _z;
        }

        public static TPoint operator +(TPoint lhs, TPoint rhs)
        {
            return new TPoint(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z);
        }
    }
    
    
}

namespace Projection
{
    public class TTT
    {
        public static Point Projection(TPoint tDim)
        {
            double x = (tDim.x - tDim.y) * Math.Cos(Math.PI/3);
            double y = -(tDim.x + tDim.y) * Math.Sin(Math.PI/3) + tDim.z;
            return new Point((int)x+401,(int)y+183);
        }

        public static TPoint RotateZ(TPoint startVector,double angle)
        {
            return  new TPoint((int)(startVector.x*Math.Cos(angle)-startVector.y*Math.Sin(angle)),
                (int)(startVector.x*Math.Sin(angle)+startVector.y*Math.Cos(angle)),
                startVector.z
                );
        }
    } 
}