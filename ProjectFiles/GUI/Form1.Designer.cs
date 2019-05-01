namespace Compilers_gui
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
            this.FlexBT = new System.Windows.Forms.Button();
            this.BisonBT = new System.Windows.Forms.Button();
            this.GccBT = new System.Windows.Forms.Button();
            this.CompileBT = new System.Windows.Forms.Button();
            this.DisplayerRT = new System.Windows.Forms.RichTextBox();
            this.FileBT = new System.Windows.Forms.Button();
            this.FilePathTB = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // FlexBT
            // 
            this.FlexBT.Location = new System.Drawing.Point(646, 270);
            this.FlexBT.Name = "FlexBT";
            this.FlexBT.Size = new System.Drawing.Size(223, 68);
            this.FlexBT.TabIndex = 0;
            this.FlexBT.Text = "Flex";
            this.FlexBT.UseVisualStyleBackColor = true;
            this.FlexBT.Click += new System.EventHandler(this.FlexBT_Click);
            // 
            // BisonBT
            // 
            this.BisonBT.Location = new System.Drawing.Point(646, 344);
            this.BisonBT.Name = "BisonBT";
            this.BisonBT.Size = new System.Drawing.Size(223, 66);
            this.BisonBT.TabIndex = 1;
            this.BisonBT.Text = "Bison";
            this.BisonBT.UseVisualStyleBackColor = true;
            this.BisonBT.Click += new System.EventHandler(this.BisonBT_Click);
            // 
            // GccBT
            // 
            this.GccBT.Location = new System.Drawing.Point(646, 416);
            this.GccBT.Name = "GccBT";
            this.GccBT.Size = new System.Drawing.Size(223, 66);
            this.GccBT.TabIndex = 2;
            this.GccBT.Text = "GCC";
            this.GccBT.UseVisualStyleBackColor = true;
            this.GccBT.Click += new System.EventHandler(this.GccBT_Click);
            // 
            // CompileBT
            // 
            this.CompileBT.Location = new System.Drawing.Point(646, 488);
            this.CompileBT.Name = "CompileBT";
            this.CompileBT.Size = new System.Drawing.Size(223, 66);
            this.CompileBT.TabIndex = 3;
            this.CompileBT.Text = "Compile";
            this.CompileBT.UseVisualStyleBackColor = true;
            this.CompileBT.Click += new System.EventHandler(this.CompileBT_Click);
            // 
            // DisplayerRT
            // 
            this.DisplayerRT.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DisplayerRT.Location = new System.Drawing.Point(23, 35);
            this.DisplayerRT.Name = "DisplayerRT";
            this.DisplayerRT.ReadOnly = true;
            this.DisplayerRT.Size = new System.Drawing.Size(451, 516);
            this.DisplayerRT.TabIndex = 4;
            this.DisplayerRT.Text = "";
            // 
            // FileBT
            // 
            this.FileBT.Location = new System.Drawing.Point(646, 196);
            this.FileBT.Name = "FileBT";
            this.FileBT.Size = new System.Drawing.Size(223, 68);
            this.FileBT.TabIndex = 5;
            this.FileBT.Text = "Open File";
            this.FileBT.UseVisualStyleBackColor = true;
            this.FileBT.Click += new System.EventHandler(this.FileBT_Click);
            // 
            // FilePathTB
            // 
            this.FilePathTB.Enabled = false;
            this.FilePathTB.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FilePathTB.Location = new System.Drawing.Point(646, 123);
            this.FilePathTB.Multiline = true;
            this.FilePathTB.Name = "FilePathTB";
            this.FilePathTB.Size = new System.Drawing.Size(223, 52);
            this.FilePathTB.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(488, 139);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(145, 17);
            this.label1.TabIndex = 8;
            this.label1.Text = "GCC Input Test Name";
            this.label1.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(881, 582);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.FilePathTB);
            this.Controls.Add(this.FileBT);
            this.Controls.Add(this.DisplayerRT);
            this.Controls.Add(this.CompileBT);
            this.Controls.Add(this.GccBT);
            this.Controls.Add(this.BisonBT);
            this.Controls.Add(this.FlexBT);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button FlexBT;
        private System.Windows.Forms.Button BisonBT;
        private System.Windows.Forms.Button GccBT;
        private System.Windows.Forms.Button CompileBT;
        private System.Windows.Forms.RichTextBox DisplayerRT;
        private System.Windows.Forms.Button FileBT;
        private System.Windows.Forms.TextBox FilePathTB;
        private System.Windows.Forms.Label label1;
    }
}

