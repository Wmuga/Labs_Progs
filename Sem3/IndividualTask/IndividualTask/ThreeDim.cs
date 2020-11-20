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
    }

    public class Matrix
    {
        #region parameters

        private int _w;
        private int _h;

        #endregion
        
        public Matrix(int w, int h)
        {
            
        }

        public double[][] matrix;
        
        public static Matrix operator*(Matrix rhs, Matrix lhs)
        {
            return new Matrix(0,0);
        }

        public TVector ToTVector()
        {
            return new TVector();
        }
    }
}