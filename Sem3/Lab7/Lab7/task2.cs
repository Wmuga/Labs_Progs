using System;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace Lab7
{
    partial class Form1
    {
        private void getFileButton_Click(object sender, EventArgs e)
        {
            byte allSymb = 0;
            var getFile = new OpenFileDialog();
            if (getFile.ShowDialog() == DialogResult.OK)
            {
                PrintWait("Открытие файла "+ getFile.FileName);
                var readFile = new StreamReader(getFile.FileName);
                string line;
                while ((line = readFile.ReadLine()) != null)
                {
                    PrintWait("Прочитано: " + line);
                    if ((allSymb&1)==0 && line.Split(new[] {'Д', 'д'}).Length != 1)
                    {
                        allSymb|=1;
                        PrintWait("Найден д");
                    }

                    if ((allSymb&2)==0 && line.Split(new[] {'Е', 'е'}).Length != 1)
                    {
                        allSymb|=2;
                        PrintWait("Найден е");
                    }

                    if ((allSymb&4)==0 && line.Split(new[] {'Н', 'н'}).Length != 1)
                    {
                        allSymb|=4;
                        PrintWait("Найден н");
                    }
                    if ((allSymb&8)==0 && line.Split(new[] {'Ь', 'ь'}).Length != 1)
                    {
                        allSymb|=8;
                        PrintWait("Найден ь");
                    }

                    if (debugMode)
                    {
                        var msg = ((allSymb & 1) != 0).ToString() + ((allSymb & 2) != 0) + ((allSymb & 4) != 0) +
                                  ((allSymb & 8) != 0);
                        PrintWait(msg);
                    }
                    
                    if ((allSymb&0b1111)==0b1111)
                    {
                        PrintWait("Найдены все символы");
                        secondOutBox.Text = "Найдены все символы слова \"ДЕНЬ\"";
                        break;
                    }
                }
                if (secondOutBox.Text == "") secondOutBox.Text = "Не найдено достаточно символов слова \"ДЕНЬ\"";
            }
        }
    }
}