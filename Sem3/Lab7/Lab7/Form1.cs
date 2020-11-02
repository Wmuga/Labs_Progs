using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab7
{
    public partial class Form1 : Form
    {
        private bool debugMode;
        public Form1()
        {
            InitializeComponent();
            debugMode = false;
        }

        private void PrintWait(string message)
        {
            if (debugMode)
            {
                Console.WriteLine(message);
                Console.ReadKey();
            }
        }
        
        private void createFileButton_Click(object sender, EventArgs e)
        {
            var saveFile = new SaveFileDialog();
            saveFile.Filter = "Бинарный файл (*.bin)|*.bin";
            saveFile.RestoreDirectory = true;
            saveFile.Title = "Сохранения бинарного файла";
            
            if (saveFile.ShowDialog() == DialogResult.OK)
            {
                PrintWait("Открытие " + saveFile.FileName + " на запись");
                try
                {
                    var binaryOut = new BinaryWriter(new FileStream(saveFile.FileName,FileMode.Create));
                    double[] xArray = {0.1, 0.2, 0.25, 0.33, 1.78, 2.05, 2.23};

                    foreach (var x in xArray)
                    {
                        var y = (Math.Sin(x) + 2 * Math.Cos(x));
                        PrintWait("Запись " + y);
                        binaryOut.Write(y);
                    }
                    
                    binaryOut.BaseStream.Close();
                    binaryOut.Close();

                    PrintWait("Открытие " + saveFile.FileName + " на чтение");
                    var binaryIn = new BinaryReader(new FileStream(saveFile.FileName,FileMode.Open));
                    double max = 0;
                    binaryIn.BaseStream.Seek(0, SeekOrigin.Begin);
                    try
                    {
                        while (true)
                        {
                            double current;
                            current = binaryIn.ReadDouble();
                            PrintWait("Прочитали " + current);
                            if (current > max) max = current;
                            firstOutputBox.Text += current + " ";
                        }
                    }
                    catch (EndOfStreamException exc)
                    {
                    }

                    binaryIn.Close();
                    PrintWait("Конец работы с файлом");
                    firstMaxOutBox.Text = max.ToString();
                }
                catch (FileNotFoundException fnfe)
                {
                    firstOutputBox.Text = fnfe.Message;
                }

            }
        }
        private void firstMaxOutBox_TextChanged(object sender, EventArgs e)
        {
            debugMode = (firstMaxOutBox.Text == "Dbg");
        }
    }
}