using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
/*
	Лабораторная работа #6
	Выполнил Черкасов.А.А А-08-19 
	Вариант 1
	1)Ввести текст, состоящий из нескольких предложений. Вывести каждое слово в обратном порядке
	2)Дан текстовый файл. Вывести все слова, состоящие только из цифр.
*/
namespace Lab6
{
    static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.SetHighDpiMode(HighDpiMode.SystemAware);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
            Application.Run(new task2());
        }
    }
}