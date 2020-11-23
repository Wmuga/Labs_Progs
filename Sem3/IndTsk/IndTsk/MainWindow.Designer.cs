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
            this.NewParticleButton = new System.Windows.Forms.Button();
            this.field = new System.Windows.Forms.Panel();
            this.TempertureControl = new System.Windows.Forms.HScrollBar();
            this.SuspendLayout();
            // 
            // NewParticleButton
            // 
            this.NewParticleButton.Location = new System.Drawing.Point(643, 393);
            this.NewParticleButton.Name = "NewParticleButton";
            this.NewParticleButton.Size = new System.Drawing.Size(145, 31);
            this.NewParticleButton.TabIndex = 1;
            this.NewParticleButton.Text = "Новая частица";
            this.NewParticleButton.UseVisualStyleBackColor = true;
            this.NewParticleButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // field
            // 
            this.field.BackColor = System.Drawing.Color.Black;
            this.field.Location = new System.Drawing.Point(1, 1);
            this.field.Name = "field";
            this.field.Size = new System.Drawing.Size(802, 367);
            this.field.TabIndex = 2;
            // 
            // TempertureControl
            // 
            this.TempertureControl.Location = new System.Drawing.Point(51, 380);
            this.TempertureControl.Name = "TempertureControl";
            this.TempertureControl.Size = new System.Drawing.Size(544, 18);
            this.TempertureControl.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.TempertureControl);
            this.Controls.Add(this.field);
            this.Controls.Add(this.NewParticleButton);
            this.Name = "Form1";
            this.Text = "Симуляция";
            this.ResumeLayout(false);
        }

        private System.Windows.Forms.Button NewParticleButton;
        private System.Windows.Forms.HScrollBar TempertureControl;

        private System.Windows.Forms.Panel field;

        #endregion
    }
}