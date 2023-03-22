using System;
using System.Windows.Forms;

namespace Lab_2_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                double a = Convert.ToDouble(textBox1.Text);
                double b = Convert.ToDouble(textBox2.Text);
                double c = Convert.ToDouble(textBox3.Text);

                double ak = Solve(a);
                double bk = Solve(b);
                double ck = Solve(c);

                textBox5.Text = "f(A) = " + ak.ToString() + Environment.NewLine;
                textBox5.Text += "f(B) = " + bk.ToString() + Environment.NewLine;
                textBox5.Text += "f(C) = " + ck.ToString() + Environment.NewLine;
                textBox5.Text += "Минимальное значение в точке ";
                if (ak < bk && ak < ck)
                    textBox5.Text += "A";
                else if (bk < ak && bk < ck)
                    textBox5.Text += "B";
                else if (ck < bk && ck < ak)
                    textBox5.Text += "C";

                else if (ck == bk && ck < ak)
                    textBox5.Text += "C и B";
                else if (ck == ak && ck < bk)
                    textBox5.Text += "C и A";
                else if (ak == bk && ak < ck)
                    textBox5.Text += "C и B";
            }
            catch
            {
                textBox5.Text = "Введены некорректыне данные";
            }

        }

        double Solve(double x)
        {
            return Math.Sin(x) + Math.Cos(2.0 * x);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
