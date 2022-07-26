using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lable_gui
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

       
        int counter = -1;
        private void label1_Click(object sender, EventArgs e)
        {
            label1.Text = "click into label";
        }

        private void form1_Click(object sender, EventArgs e)
        {
            label1.Text = "click into form";
        }
    }
}
