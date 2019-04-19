using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Compilers_gui
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        OpenFileDialog ofd = new OpenFileDialog();
        private void FlexBT_Click(object sender, EventArgs e)
        {
            Process process = new Process();
            process.StartInfo.FileName = "cmd.exe";
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.UseShellExecute = false;
            process.Start();
            process.StandardInput.WriteLine("flex "+ FilePathTB.Text);
            process.StandardInput.Flush();
            process.StandardInput.Close();
            process.WaitForExit();
            DisplayerRT.Text = process.StandardOutput.ReadToEnd();
            FilePathTB.Clear();
        }

        private void FileBT_Click(object sender, EventArgs e)
        {
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                FilePathTB.Text = ofd.SafeFileName;
            }
        }

        private void BisonBT_Click(object sender, EventArgs e)
        {
            Process process = new Process();
            process.StartInfo.FileName = "cmd.exe";
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.UseShellExecute = false;
            process.Start();
            process.StandardInput.WriteLine("bison -dy " + FilePathTB.Text);
            process.StandardInput.Flush();
            process.StandardInput.Close();
            process.WaitForExit();
            DisplayerRT.AppendText (process.StandardOutput.ReadToEnd());
            FilePathTB.Clear();
        }

        private void GccBT_Click(object sender, EventArgs e)
        {
            Process process = new Process();
            process.StartInfo.FileName = "cmd.exe";
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.UseShellExecute = false;
            process.Start();
            process.StandardInput.WriteLine("gcc lex.yy.c y.tab.c -o "+"myLang.exe");
            process.StandardInput.Flush();
            process.StandardInput.Close();
            process.WaitForExit();
            DisplayerRT.AppendText(process.StandardOutput.ReadToEnd());
            label1.Visible = true;
            FilePathTB.Clear();
        }

        private void CompileBT_Click(object sender, EventArgs e)
        {
            Process process = new Process();
            process.StartInfo.FileName = "cmd.exe";
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.UseShellExecute = false;
            process.Start();
            process.StandardInput.WriteLine("myLang.exe < "+ FilePathTB.Text);
            process.StandardInput.Flush();
            process.StandardInput.Close();
            process.WaitForExit();
            DisplayerRT.Text=process.StandardOutput.ReadToEnd();
            FilePathTB.Clear();
        }
    }
}
