using System;
using System.ComponentModel;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Lab6
{
    public partial class task2 : Form
    {
        public task2()
        {
            InitializeComponent();
        }

        private void getFile_Click(object sender, EventArgs e)
        {
            var file = new OpenFileDialog();
            file.DefaultExt = ".txt";
            file.Filter = ".txt (*.txt)|*.txt";

            outBox.Text = "";

            if (file.ShowDialog() == DialogResult.OK)
            {
                var fileStream = new StreamReader(file.FileName);

                string line;
                while ((line = fileStream.ReadLine()) != null)
                {
                    var matchedDigitWords = Regex.Matches(line,@"\b(\d+)\b");
                    
                    foreach (Match word in matchedDigitWords)
                    {
                        if (!TwoDigitState) outBox.Text += word.Value + " ";
                        else
                        {
                            var checkWord = word.Value;
                            while (checkWord[0] == '0') checkWord = checkWord.Remove(0,1);
                            if (checkWord.Length==2) outBox.Text += checkWord + " ";
                        }
                    }
                } 
                fileStream.Close();
                if (outBox.Text == "") outBox.Text = "Нет подходящих слов";
            }
            else
            {
                outBox.Text = "Не выбран файл";
            }
        }

        private void twoDigitButton_CheckedChanged(object sender, EventArgs e)
        {
            TwoDigitState = twoDigitButton.Checked;
            outBox.Text = "";
        }
    }
}