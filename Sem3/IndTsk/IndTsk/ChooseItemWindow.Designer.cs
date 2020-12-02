using System.ComponentModel;

namespace IndTsk
{
    partial class ChooseItemWindow
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.buttonH = new System.Windows.Forms.Button();
            this.buttonO = new System.Windows.Forms.Button();
            this.buttonCl = new System.Windows.Forms.Button();
            this.buttonK = new System.Windows.Forms.Button();
            this.buttonW = new System.Windows.Forms.Button();
            this.buttonKCl = new System.Windows.Forms.Button();
            this.buttonHCl = new System.Windows.Forms.Button();
            this.buttonKOH = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.radioButton1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(372, 46);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            // 
            // radioButton2
            // 
            this.radioButton2.Location = new System.Drawing.Point(251, 17);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(87, 23);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.Text = "Молекула";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(27, 17);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(87, 23);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Атом";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // buttonH
            // 
            this.buttonH.Location = new System.Drawing.Point(48, 78);
            this.buttonH.Name = "buttonH";
            this.buttonH.Size = new System.Drawing.Size(103, 27);
            this.buttonH.TabIndex = 1;
            this.buttonH.Text = "Водород";
            this.buttonH.UseVisualStyleBackColor = true;
            this.buttonH.Click += new System.EventHandler(this.buttonH_Click);
            // 
            // buttonO
            // 
            this.buttonO.Location = new System.Drawing.Point(229, 151);
            this.buttonO.Name = "buttonO";
            this.buttonO.Size = new System.Drawing.Size(103, 27);
            this.buttonO.TabIndex = 1;
            this.buttonO.Text = "Кислород";
            this.buttonO.UseVisualStyleBackColor = true;
            this.buttonO.Click += new System.EventHandler(this.buttonO_Click);
            // 
            // buttonCl
            // 
            this.buttonCl.Location = new System.Drawing.Point(229, 78);
            this.buttonCl.Name = "buttonCl";
            this.buttonCl.Size = new System.Drawing.Size(103, 27);
            this.buttonCl.TabIndex = 1;
            this.buttonCl.Text = "Хлор";
            this.buttonCl.UseVisualStyleBackColor = true;
            this.buttonCl.Click += new System.EventHandler(this.buttonCl_Click);
            // 
            // buttonK
            // 
            this.buttonK.Location = new System.Drawing.Point(48, 151);
            this.buttonK.Name = "buttonK";
            this.buttonK.Size = new System.Drawing.Size(103, 27);
            this.buttonK.TabIndex = 1;
            this.buttonK.Text = "Калий";
            this.buttonK.UseVisualStyleBackColor = true;
            this.buttonK.Click += new System.EventHandler(this.buttonK_Click);
            // 
            // buttonW
            // 
            this.buttonW.Location = new System.Drawing.Point(48, 299);
            this.buttonW.Name = "buttonW";
            this.buttonW.Size = new System.Drawing.Size(103, 27);
            this.buttonW.TabIndex = 1;
            this.buttonW.Text = "Вода";
            this.buttonW.UseVisualStyleBackColor = true;
            this.buttonW.Click += new System.EventHandler(this.buttonW_Click);
            // 
            // buttonKCl
            // 
            this.buttonKCl.Location = new System.Drawing.Point(48, 357);
            this.buttonKCl.Name = "buttonKCl";
            this.buttonKCl.Size = new System.Drawing.Size(103, 27);
            this.buttonKCl.TabIndex = 1;
            this.buttonKCl.Text = "Хлорид Калия";
            this.buttonKCl.UseVisualStyleBackColor = true;
            this.buttonKCl.Click += new System.EventHandler(this.buttonKCl_Click);
            // 
            // buttonHCl
            // 
            this.buttonHCl.Location = new System.Drawing.Point(229, 299);
            this.buttonHCl.Name = "buttonHCl";
            this.buttonHCl.Size = new System.Drawing.Size(103, 27);
            this.buttonHCl.TabIndex = 1;
            this.buttonHCl.Text = "Соляная кислота";
            this.buttonHCl.UseVisualStyleBackColor = true;
            this.buttonHCl.Click += new System.EventHandler(this.buttonHCl_Click);
            // 
            // buttonKOH
            // 
            this.buttonKOH.Location = new System.Drawing.Point(229, 357);
            this.buttonKOH.Name = "buttonKOH";
            this.buttonKOH.Size = new System.Drawing.Size(103, 27);
            this.buttonKOH.TabIndex = 1;
            this.buttonKOH.Text = "Гидроксид Калия";
            this.buttonKOH.UseVisualStyleBackColor = true;
            this.buttonKOH.Click += new System.EventHandler(this.buttonKOH_Click);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(48, 238);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(259, 28);
            this.label1.TabIndex = 2;
            this.label1.Text = "Молекулы:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(48, 131);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(100, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Только атом:";
            // 
            // ChooseItemWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(396, 411);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonKOH);
            this.Controls.Add(this.buttonK);
            this.Controls.Add(this.buttonHCl);
            this.Controls.Add(this.buttonCl);
            this.Controls.Add(this.buttonKCl);
            this.Controls.Add(this.buttonW);
            this.Controls.Add(this.buttonO);
            this.Controls.Add(this.buttonH);
            this.Controls.Add(this.groupBox1);
            this.Name = "ChooseItemWindow";
            this.Text = "ChooseItemWindow";
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
        }

        private System.Windows.Forms.Label label2;

        private System.Windows.Forms.Button buttonKOH;

        private System.Windows.Forms.Button buttonKCl;

        private System.Windows.Forms.Button buttonHCl;

        private System.Windows.Forms.Button buttonW;

        private System.Windows.Forms.Button buttonCl;
        private System.Windows.Forms.Button buttonH;
        private System.Windows.Forms.Button buttonK;
        private System.Windows.Forms.Button buttonO;

        private System.Windows.Forms.Label label1;

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;

        #endregion
    }
}