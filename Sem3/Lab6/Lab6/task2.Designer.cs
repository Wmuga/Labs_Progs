using System.ComponentModel;

namespace Lab6
{
    partial class task2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.getFile = new System.Windows.Forms.Button();
            this.outBox = new System.Windows.Forms.TextBox();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.twoDigitButton = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(366, 30);
            this.label1.TabIndex = 0;
            this.label1.Text = "Дан текстовый файл. Вывести все слова, состоящие только из цифр.";
            // 
            // getFile
            // 
            this.getFile.Location = new System.Drawing.Point(36, 47);
            this.getFile.Name = "getFile";
            this.getFile.Size = new System.Drawing.Size(141, 32);
            this.getFile.TabIndex = 1;
            this.getFile.Text = "Выбрать файл\r\n";
            this.getFile.UseVisualStyleBackColor = true;
            this.getFile.Click += new System.EventHandler(this.getFile_Click);
            // 
            // outBox
            // 
            this.outBox.Location = new System.Drawing.Point(36, 115);
            this.outBox.Multiline = true;
            this.outBox.Name = "outBox";
            this.outBox.ReadOnly = true;
            this.outBox.Size = new System.Drawing.Size(330, 230);
            this.outBox.TabIndex = 2;
            // 
            // radioButton1
            // 
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(6, 13);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(115, 23);
            this.radioButton1.TabIndex = 3;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Все цифры";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // twoDigitButton
            // 
            this.twoDigitButton.Location = new System.Drawing.Point(6, 33);
            this.twoDigitButton.Name = "twoDigitButton";
            this.twoDigitButton.Size = new System.Drawing.Size(133, 23);
            this.twoDigitButton.TabIndex = 3;
            this.twoDigitButton.Text = "Только двузначные";
            this.twoDigitButton.UseVisualStyleBackColor = true;
            this.twoDigitButton.CheckedChanged += new System.EventHandler(this.twoDigitButton_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.twoDigitButton);
            this.groupBox1.Controls.Add(this.radioButton1);
            this.groupBox1.Location = new System.Drawing.Point(220, 29);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(146, 62);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            // 
            // task2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(397, 357);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.outBox);
            this.Controls.Add(this.getFile);
            this.Controls.Add(this.label1);
            this.Name = "task2";
            this.Text = "Лабораторная работа №6";
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        private System.Windows.Forms.RadioButton twoDigitButton;

        private System.Windows.Forms.GroupBox groupBox1;

        private System.Windows.Forms.RadioButton radioButton1;

        private System.Windows.Forms.TextBox outBox;

        private System.Windows.Forms.Button getFile;

        private System.Windows.Forms.Label label1;

        private bool TwoDigitState = false;

        #endregion
    }
}