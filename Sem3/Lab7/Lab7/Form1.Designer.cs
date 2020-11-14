namespace Lab7
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.firstTaskTab = new System.Windows.Forms.TabPage();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.firstMaxOutBox = new System.Windows.Forms.TextBox();
            this.firstOutputBox = new System.Windows.Forms.TextBox();
            this.createFileButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.secondTaskTab = new System.Windows.Forms.TabPage();
            this.secondOutBox = new System.Windows.Forms.TextBox();
            this.getFileButton = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.tabControl1.SuspendLayout();
            this.firstTaskTab.SuspendLayout();
            this.secondTaskTab.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.firstTaskTab);
            this.tabControl1.Controls.Add(this.secondTaskTab);
            this.tabControl1.Location = new System.Drawing.Point(12, 1);
            this.tabControl1.Multiline = true;
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(386, 382);
            this.tabControl1.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabControl1.TabIndex = 0;
            // 
            // firstTaskTab
            // 
            this.firstTaskTab.Controls.Add(this.textBox1);
            this.firstTaskTab.Controls.Add(this.label3);
            this.firstTaskTab.Controls.Add(this.label2);
            this.firstTaskTab.Controls.Add(this.firstMaxOutBox);
            this.firstTaskTab.Controls.Add(this.firstOutputBox);
            this.firstTaskTab.Controls.Add(this.createFileButton);
            this.firstTaskTab.Controls.Add(this.label1);
            this.firstTaskTab.Location = new System.Drawing.Point(4, 22);
            this.firstTaskTab.Name = "firstTaskTab";
            this.firstTaskTab.Padding = new System.Windows.Forms.Padding(3);
            this.firstTaskTab.Size = new System.Drawing.Size(378, 356);
            this.firstTaskTab.TabIndex = 0;
            this.firstTaskTab.Text = "Задание 1";
            this.firstTaskTab.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(55, 143);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(260, 18);
            this.label3.TabIndex = 5;
            this.label3.Text = "Содержимое файла";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(14, 76);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(133, 24);
            this.label2.TabIndex = 4;
            this.label2.Text = "Максимальный элемент";
            // 
            // firstMaxOutBox
            // 
            this.firstMaxOutBox.Font = new System.Drawing.Font("Times New Roman", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (204)));
            this.firstMaxOutBox.Location = new System.Drawing.Point(195, 76);
            this.firstMaxOutBox.Name = "firstMaxOutBox";
            this.firstMaxOutBox.Size = new System.Drawing.Size(171, 25);
            this.firstMaxOutBox.TabIndex = 3;
            this.firstMaxOutBox.TextChanged += new System.EventHandler(this.firstMaxOutBox_TextChanged);
            // 
            // firstOutputBox
            // 
            this.firstOutputBox.Font = new System.Drawing.Font("Times New Roman", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (204)));
            this.firstOutputBox.Location = new System.Drawing.Point(26, 164);
            this.firstOutputBox.Multiline = true;
            this.firstOutputBox.Name = "firstOutputBox";
            this.firstOutputBox.ReadOnly = true;
            this.firstOutputBox.Size = new System.Drawing.Size(319, 122);
            this.firstOutputBox.TabIndex = 2;
            // 
            // createFileButton
            // 
            this.createFileButton.Location = new System.Drawing.Point(102, 301);
            this.createFileButton.Name = "createFileButton";
            this.createFileButton.Size = new System.Drawing.Size(162, 26);
            this.createFileButton.TabIndex = 1;
            this.createFileButton.Text = "Создать файл";
            this.createFileButton.UseVisualStyleBackColor = true;
            this.createFileButton.Click += new System.EventHandler(this.createFileButton_Click);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(6, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(355, 71);
            this.label1.TabIndex = 0;
            this.label1.Text = resources.GetString("label1.Text");
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // secondTaskTab
            // 
            this.secondTaskTab.Controls.Add(this.secondOutBox);
            this.secondTaskTab.Controls.Add(this.getFileButton);
            this.secondTaskTab.Controls.Add(this.label4);
            this.secondTaskTab.Location = new System.Drawing.Point(4, 22);
            this.secondTaskTab.Name = "secondTaskTab";
            this.secondTaskTab.Padding = new System.Windows.Forms.Padding(3);
            this.secondTaskTab.Size = new System.Drawing.Size(378, 356);
            this.secondTaskTab.TabIndex = 1;
            this.secondTaskTab.Text = "Задание 2";
            this.secondTaskTab.UseVisualStyleBackColor = true;
            // 
            // secondOutBox
            // 
            this.secondOutBox.Location = new System.Drawing.Point(59, 286);
            this.secondOutBox.Name = "secondOutBox";
            this.secondOutBox.ReadOnly = true;
            this.secondOutBox.Size = new System.Drawing.Size(241, 20);
            this.secondOutBox.TabIndex = 3;
            // 
            // getFileButton
            // 
            this.getFileButton.Location = new System.Drawing.Point(111, 141);
            this.getFileButton.Name = "getFileButton";
            this.getFileButton.Size = new System.Drawing.Size(144, 38);
            this.getFileButton.TabIndex = 2;
            this.getFileButton.Text = "Выбрать файл";
            this.getFileButton.UseVisualStyleBackColor = true;
            this.getFileButton.Click += new System.EventHandler(this.getFileButton_Click);
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(3, 25);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(366, 60);
            this.label4.TabIndex = 1;
            this.label4.Text = "Выяснить, верно ли, что среди символов строки произвольной длины, расположенной в" + " файле, имеются все символы, входящие в слово ДЕНЬ";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(193, 106);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(172, 20);
            this.textBox1.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(410, 393);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "Лабораторная работа #7";
            this.tabControl1.ResumeLayout(false);
            this.firstTaskTab.ResumeLayout(false);
            this.firstTaskTab.PerformLayout();
            this.secondTaskTab.ResumeLayout(false);
            this.secondTaskTab.PerformLayout();
            this.ResumeLayout(false);
        }

        private System.Windows.Forms.TextBox textBox1;

        private System.Windows.Forms.Button getFileButton;
        private System.Windows.Forms.TextBox secondOutBox;

        private System.Windows.Forms.Label label4;

        private System.Windows.Forms.Label label3;

        private System.Windows.Forms.Label label2;

        private System.Windows.Forms.TextBox firstMaxOutBox;

        private System.Windows.Forms.Button createFileButton;
        private System.Windows.Forms.TextBox firstOutputBox;

        private System.Windows.Forms.TabPage secondTaskTab;

        private System.Windows.Forms.TabPage firstTaskTab;
        private System.Windows.Forms.Label label1;

        private System.Windows.Forms.TabControl tabControl1;

        #endregion
    }
}