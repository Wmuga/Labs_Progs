using System.Collections.Generic;
using System.Drawing;
using System.Threading;
using IndividualTask;

namespace Tree
{
    public class QuadTree
    {
        //Дереву передаем его "границы"
        public QuadTree(Rectangle boundaries)
        {
            ul = null;
            ur = null;
            ll = null;
            lr = null;
            _boundaries = boundaries;
            _elements = new List<IParticle>();
        }
        //Элемент добавляем основе. Если превысили лимит - разделяем. Если уже разделен - то листьям
        public void Append(IParticle element)
        {
            if (ul != null) AddToLower(element);
            else
            {
                _elements.Add(element);
                if (_elements.Count > Capacity) Split();
            }
            
        }
        //Разделение корня на 4 ветви
        private void Split()
        {
            ll = new QuadTree(new Rectangle(_boundaries.X,_boundaries.Y,_boundaries.Width/2,_boundaries.Height/2));
            lr = new QuadTree(new Rectangle(_boundaries.X+_boundaries.Width/2,_boundaries.Y,_boundaries.Width/2,_boundaries.Height/2));
            ul = new QuadTree(new Rectangle(_boundaries.X,_boundaries.Y+_boundaries.Height/2,_boundaries.Width/2,_boundaries.Height/2));
            ur = new QuadTree(new Rectangle(_boundaries.X+_boundaries.Width/2,_boundaries.Y+_boundaries.Height/2,_boundaries.Width/2,_boundaries.Height/2));
            foreach (var element in _elements)
            {
                AddToLower(element);
            }
            _elements.Clear();
            _elements = null;
        }
        //Добавление элемента листьям
        private void AddToLower(IParticle element)
        {
            var location = TDim.TTT.Projection(element.GetCoords());
            if (location.X<=_boundaries.X+_boundaries.Width/2 && location.Y<=_boundaries.Y+_boundaries.Height/2) ll.Append(element);
            if (location.X>_boundaries.X+_boundaries.Width/2 && location.Y<=_boundaries.Y+_boundaries.Height/2) lr.Append(element);
            if (location.X<=_boundaries.X+_boundaries.Width/2 && location.Y>_boundaries.Y+_boundaries.Height/2) ul.Append(element);
            if (location.X>_boundaries.X+_boundaries.Width/2 && location.Y>_boundaries.Y+_boundaries.Height/2) ur.Append(element);
        }
        //Отрисовка элемнтов
        public void DrawContents(Graphics gr, int drawstate)
        {
            if (ul==null)
                foreach (var element in _elements)
                {
                    element.Draw(gr, drawstate);
                }
            else
            {
                ul.DrawContents(gr,drawstate);
                ur.DrawContents(gr,drawstate);
                ll.DrawContents(gr,drawstate);
                lr.DrawContents(gr,drawstate);
            }
        }
        public void ClearContents(Graphics gr, int drawstate)
        {
            if (ul==null)
                foreach (var element in _elements)
                {
                    element.Clear(gr, drawstate);
                }
            else
            {
                ul.ClearContents(gr,drawstate);
                ur.ClearContents(gr,drawstate);
                ll.ClearContents(gr,drawstate);
                lr.ClearContents(gr,drawstate);
            }
        }
        //Логика
        public void Tick(double coeff)
        {
            if (ul == null)
            {
                foreach (var element in _elements)
                {
                    element.Tick(coeff);
                }
            }
            else
            {
                ul.Tick(coeff);
                ur.Tick(coeff);
                ll.Tick(coeff);
                lr.Tick(coeff);
            }
        }
        //Границы
        public void DrawBoundaries(Graphics gr, Color color)
        {
            if (ul != null)
            {
                ul.DrawBoundaries(gr,color);
                ur.DrawBoundaries(gr,color);
                ll.DrawBoundaries(gr,color);
                lr.DrawBoundaries(gr,color);
                gr.DrawLine(new Pen(color),_boundaries.X+_boundaries.Width/2,_boundaries.Y,_boundaries.X+_boundaries.Width/2,_boundaries.Y+_boundaries.Height);
                gr.DrawLine(new Pen(color),_boundaries.X,_boundaries.Y+_boundaries.Height/2,_boundaries.X+_boundaries.Width,_boundaries.Y+_boundaries.Height/2);
            }
        }
        //Элементы дерева
        public void GetContents(List<IParticle> array)
        {
            if (array==null) array = new List<IParticle>();
            if (ul == null)
            {
                foreach (var element in _elements) array.Add(element);
            }
            else
            {
                ul.GetContents(array);
                ur.GetContents(array);
                ll.GetContents(array);
                lr.GetContents(array);
            }
        }
        
        //Элементы, ограниченные определенной областью
        public void GetContentsLimited(List<IParticle> array, Rectangle boundaries)
        {
            if (array==null) array = new List<IParticle>();
            if (boundaries.IntersectsWith(_boundaries))
            {
                if (ul == null) foreach (var element in _elements)
                {
                    var location = TDim.TTT.Projection(element.GetCoords());
                    if (location.X<boundaries.X+boundaries.Width && location.X>boundaries.X &&
                        location.Y<boundaries.Y+boundaries.Height && location.Y>boundaries.Y) array.Add(element);
                }
                else
                {
                    ul.GetContentsLimited(array,boundaries);
                    ur.GetContentsLimited(array,boundaries);
                    ll.GetContentsLimited(array,boundaries);
                    lr.GetContentsLimited(array,boundaries);
                }
            }
        }

        #region Leafs

        private QuadTree ul;
        private QuadTree ur;
        private QuadTree ll;
        private QuadTree lr;

        #endregion

        #region Parameters

        private Rectangle _boundaries;
        private List<IParticle> _elements;
        private const int Capacity =4;

        #endregion
    }
}