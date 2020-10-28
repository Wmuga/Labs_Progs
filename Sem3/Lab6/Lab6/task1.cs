using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void ConvertButton_Click(object sender, EventArgs e)
        {
            var inputText = InputTextBox.Text;
            char[] delims =
            {
                '.',' ','!','?',',',':','\'','\"','@','#','№','$',';','%','^',
                '&','*','(',')','-','+','_','=','[','{',']','}','|','\\','/','\t','\r','\n','<','>',
                '~','`'
            };
            var words = inputText.Split(delims, StringSplitOptions.RemoveEmptyEntries);

            if (words.Length == 0) OutputTextBox.Text = "Нет последовательности символов, определяемых как слово";
            else
            {
                var newOut = new StringBuilder();
                foreach (var word in words)
                {
                    newOut.Append(new string(word.ToCharArray().Reverse().ToArray()) + " ");
                }

                OutputTextBox.Text = newOut.ToString();
            }
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            OutputTextBox.Text = "";
            InputTextBox.Text = "";
        }
    }
}