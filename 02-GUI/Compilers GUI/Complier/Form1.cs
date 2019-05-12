using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;

namespace Complier
{
    public partial class Form1 : Form
    {
        OpenFileDialog ofd = new OpenFileDialog();
        string undo = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            richTextBox2.Clear();
            richTextBox3.Clear();
            TextWriter txt = new StreamWriter(@"..\\..\\..\\input.txt");
            txt.Write(richTextBox1.Text);
            txt.Close();

            // TODO: Change path acoordingly
            System.Diagnostics.Process.Start("cmd.exe", "/C C: & cd C:\\Users\\Mohamed\\Documents\\GitHub\\Mini-C-Compiler\\Compilers GUI & CMD.bat & pause");

            richTextBox2.Text = File.ReadAllText(@"C:\\Users\\Mohamed\\Documents\\GitHub\\Mini-C-Compiler\\Compilers GUI\\codeGENERATED.txt");
            richTextBox3.Text = File.ReadAllText(@"C:\\Users\\Mohamed\\Documents\\GitHub\\Mini-C-Compiler\\Compilers GUI\\mySymbols.txt");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.Text = File.ReadAllText(ofd.FileName);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Text == "")
                return;
            undo = richTextBox1.Text;
            richTextBox1.Text = "";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = undo;
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
