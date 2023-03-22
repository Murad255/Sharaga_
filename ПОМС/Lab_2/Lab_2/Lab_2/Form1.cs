using System;
using System.Windows.Forms;

namespace Lab_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonl_Click(object sender, EventArgs e)
        {
            try
            {
                // Считывание начальных данных
                double x0 = Convert.ToDouble(textBox1.Text);
                double xk = Convert.ToDouble(textBox2.Text);

                double dx = Convert.ToDouble(textBox3.Text);
                double b = Convert.ToDouble(textBox4.Text);
                textBox5.Text = "Работу выполнил ст. Абдулзагиров М.М." + Environment.NewLine;
                // Цикл для табулирования функции
                double x = x0;
                while (Math.Abs(x) <= Math.Abs(xk + dx / 2))
                {
                    double y = x * x + Math.Tan(5.0 * x + b / x);
                    textBox5.Text += "x=" + x.ToString() + "; y=" + y.ToString() + Environment.NewLine;
                    x = x + dx;
                }
            }
            catch
            {
                textBox5.Text = "Введены некорректыне данные";
            }
        }


    }
}
