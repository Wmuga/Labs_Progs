namespace IndividualTask
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

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
            this.field = new System.Windows.Forms.Panel();
            this.FPSLabel = new System.Windows.Forms.Label();
            this.TempertureControl = new System.Windows.Forms.HScrollBar();
            this.showElectronsCheckBox = new System.Windows.Forms.CheckBox();
            this.changeDrawTreeBox = new System.Windows.Forms.CheckBox();
            this.DebugLabel = new System.Windows.Forms.Label();
            this.clearButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.field.SuspendLayout();
            this.SuspendLayout();
            // 
            // field
            // 
            this.field.BackColor = System.Drawing.Color.Black;
            this.field.Controls.Add(this.FPSLabel);
            this.field.Location = new System.Drawing.Point(1, 1);
            this.field.Name = "field";
            this.field.Size = new System.Drawing.Size(802, 367);
            this.field.TabIndex = 2;
            // 
            // FPSLabel
            // 
            this.FPSLabel.ForeColor = System.Drawing.Color.Lime;
            this.FPSLabel.Location = new System.Drawing.Point(0, 0);
            this.FPSLabel.Name = "FPSLabel";
            this.FPSLabel.Size = new System.Drawing.Size(77, 18);
            this.FPSLabel.TabIndex = 0;
            this.FPSLabel.Text = "fps";
            // 
            // TempertureControl
            // 
            this.TempertureControl.LargeChange = 1;
            this.TempertureControl.Location = new System.Drawing.Point(51, 380);
            this.TempertureControl.Name = "TempertureControl";
            this.TempertureControl.Size = new System.Drawing.Size(544, 18);
            this.TempertureControl.TabIndex = 3;
            this.TempertureControl.Scroll += new System.Windows.Forms.ScrollEventHandler(this.TemperatureControl_Scroll);
            // 
            // showElectronsCheckBox
            // 
            this.showElectronsCheckBox.Location = new System.Drawing.Point(30, 414);
            this.showElectronsCheckBox.Name = "showElectronsCheckBox";
            this.showElectronsCheckBox.Size = new System.Drawing.Size(179, 22);
            this.showElectronsCheckBox.TabIndex = 4;
            this.showElectronsCheckBox.Text = "Показ электронов";
            this.showElectronsCheckBox.UseVisualStyleBackColor = true;
            this.showElectronsCheckBox.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // changeDrawTreeBox
            // 
            this.changeDrawTreeBox.Location = new System.Drawing.Point(205, 414);
            this.changeDrawTreeBox.Name = "changeDrawTreeBox";
            this.changeDrawTreeBox.Size = new System.Drawing.Size(179, 22);
            this.changeDrawTreeBox.TabIndex = 4;
            this.changeDrawTreeBox.Text = "Показывать границы дерева";
            this.changeDrawTreeBox.UseVisualStyleBackColor = true;
            this.changeDrawTreeBox.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // DebugLabel
            // 
            this.DebugLabel.Location = new System.Drawing.Point(423, 414);
            this.DebugLabel.Name = "DebugLabel";
            this.DebugLabel.Size = new System.Drawing.Size(195, 21);
            this.DebugLabel.TabIndex = 5;
            this.DebugLabel.Click += new System.EventHandler(this.DebugLabel_Click);
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(643, 417);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(126, 30);
            this.clearButton.TabIndex = 6;
            this.clearButton.Text = "Очистить";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(612, 376);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(171, 38);
            this.label1.TabIndex = 7;
            this.label1.Text = "Нажмите на поле, чтобы создать новую частицу";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.DebugLabel);
            this.Controls.Add(this.changeDrawTreeBox);
            this.Controls.Add(this.showElectronsCheckBox);
            this.Controls.Add(this.TempertureControl);
            this.Controls.Add(this.field);
            this.Name = "Form1";
            this.Text = "Симуляция";
            this.field.ResumeLayout(false);
            this.ResumeLayout(false);
        }

        private System.Windows.Forms.Label FPSLabel;

        private System.Windows.Forms.Label label1;

        private System.Windows.Forms.Button clearButton;

        private System.Windows.Forms.CheckBox changeDrawTreeBox;
        private System.Windows.Forms.Label DebugLabel;

        private System.Windows.Forms.CheckBox showElectronsCheckBox;

        private System.Windows.Forms.HScrollBar TempertureControl;

        private System.Windows.Forms.Panel field;

        #endregion
    }
}