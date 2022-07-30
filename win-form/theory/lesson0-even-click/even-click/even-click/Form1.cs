using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace even_click
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

        }

        int counter = 0;
        private void Form1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Bạn đã click lên form " + counter +" lần");
            counter++;
        }
    }
}
