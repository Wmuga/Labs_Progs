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
            bool[] allSymb = {false,false,false,false};
            var getFile = new OpenFileDialog();
            if (getFile.ShowDialog() == DialogResult.OK)
            {
                PrintWait("Открытие файла "+ getFile.FileName);
                var readFile = new StreamReader(getFile.FileName);
                string line;
                while ((line = readFile.ReadLine()) != null)
                {
                    PrintWait("Прочитано: " + line);
                    if (!allSymb[0] && line.Split(new[] {'Д', 'д'}).Length != 1)
                    {
                        allSymb[0] = true;
                        PrintWait("Найден д");
                    }

                    if (!allSymb[1] && line.Split(new[] {'Е', 'е'}).Length != 1)
                    {
                        allSymb[1] = true;
                        PrintWait("Найден е");
                    }

                    if (!allSymb[2] && line.Split(new[] {'Н', 'н'}).Length != 1)
                    {
                        allSymb[2] = true;
                        PrintWait("Найден н");
                    }
                    if (!allSymb[3] && line.Split(new[] {'Ь', 'ь'}).Length != 1)
                    {
                        allSymb[3] = true;
                        PrintWait("Найден ь");
                    }

                    if (debugMode)
                    {
                        var msg = "";
                        foreach (var b in allSymb) msg += b.ToString();
                        PrintWait(msg);
                    }
                    
                    if (allSymb[0] && allSymb[1] && allSymb[2] && allSymb[3])
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