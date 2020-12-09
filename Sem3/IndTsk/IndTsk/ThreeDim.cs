using System;
using System.Drawing;

namespace TDim
{
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

        public static TPoint operator +(TPoint lhs, TPoint rhs) => new TPoint(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z);
        public static TPoint operator -(TPoint lhs) => new TPoint(-lhs.x, -lhs.y, -lhs.z);
        public static TPoint operator -(TPoint lhs, TPoint rhs) => lhs+(-rhs);
        public static TPoint operator *(TPoint lhs, double rhs) => new TPoint((int)(lhs.x*rhs),(int)(lhs.y*rhs),(int)(lhs.z*rhs));
        public static TPoint operator /(TPoint lhs, double rhs) => lhs * (1 / rhs);

    }
    public class TTT
    {
        public static Point Projection(TPoint tDim)
        {
            double x = (tDim.x - tDim.y) * Math.Cos(Math.PI/6);
            double y = (tDim.x + tDim.y) * Math.Sin(Math.PI/6) - tDim.z;
            return new Point((int)x+401,(int)y+183);
        }

        public static TPoint RotateZ(TPoint startVector,double angle)
        {
            return  new TPoint((int)(startVector.x*Math.Cos(angle)-startVector.y*Math.Sin(angle)),
                (int)(startVector.x*Math.Sin(angle)+startVector.y*Math.Cos(angle)),
                startVector.z
                );
        }
        public static TPoint RotateX(TPoint startVector,double angle)
        {
            return  new TPoint(startVector.x,
                (int)(startVector.y*Math.Cos(angle)-startVector.z*Math.Sin(angle)),
                (int)(startVector.y*Math.Sin(angle)+startVector.z*Math.Cos(angle))
            );
        }
        public static TPoint RotateY(TPoint startVector,double angle)
        {
            return  new TPoint((int)(startVector.x*Math.Cos(angle)-startVector.z*Math.Sin(angle)),
                startVector.y,
                (int)(startVector.x*Math.Sin(angle)+startVector.z*Math.Cos(angle))
            );
        }

        public static double Radius(TPoint lhs, TPoint rhs)
        {
            return Math.Sqrt(Math.Pow((lhs.x - rhs.x), 2) + Math.Pow((lhs.y - rhs.y), 2) + Math.Pow((lhs.z - rhs.z), 2));
        }
    } 
}