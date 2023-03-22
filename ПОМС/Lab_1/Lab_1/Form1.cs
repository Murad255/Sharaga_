using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Lab_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Начальное значение X
            textBox1.Text = "3,4";
            // Начальное значение Y
            textBox2.Text = "0,74";
            // Начальное значение Z
            textBox3.Text = "19,43";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                // Считывание значения X
                double x = double.Parse(textBox1.Text);
                // Вывод значения X в окно
                textBox4.Text = Environment.NewLine +
                "X = " + x.ToString();
                // Считывание значения Y
                double y = double.Parse(textBox2.Text);
                // Вывод значения Y в окно
                textBox4.Text += Environment.NewLine +
                "Y = " + y.ToString();
                // Считывание значения Z
                double z = double.Parse(textBox3.Text);
                // Вывод значения Z в окно
                textBox4.Text += Environment.NewLine +
                "Z = " + z.ToString();
                // Вычисляем арифметическое выражение
                //double a = Math.Tan(x + y) *
                //Math.Tan(x + y);
                //double b = Math.Exp(y - z);
                //double c = Math.Sqrt(Math.Cos(x * x) +
                //Math.Sin(z * z));
                //double u = a - b * c;
                double u = SixTask(x, y, z);
                // Выводим результат в окно
                textBox4.Text += Environment.NewLine +
                "\nРезультат U = " + u.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Введены некорректыне данные\n" + ex.Message,
                    "Ошибка",
                    MessageBoxButtons.YesNo,
                    MessageBoxIcon.Error);

               // textBox4.Text = "Введены некорректыне данные";
            }
        }

        double SixTask(double x, double y, double z)
        {
            double t1 = Math.Sqrt(10.0 * (Math.Pow(x, 1.0 / 3.0) + Math.Pow(x, y + 2.0)));
            double t4 = z - Math.Abs(x - y);
           // double t3 =t4 - (double)(int)t4;
            double t2 = (Math.Pow(Math.Atan(t4), 2) );
            return t1*t2;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // Считывание значения X
            double x =0.01655;
            // Вывод значения X в окно
            textBox4.Text = Environment.NewLine +
            "X = " + x.ToString();
            // Считывание значения Y
            double y = -2.75;
            // Вывод значения Y в окно
            textBox4.Text += Environment.NewLine +
            "Y = " + y.ToString();
            // Считывание значения Z
            double z = 0.15;
            // Вывод значения Z в окно
            textBox4.Text += Environment.NewLine +
            "Z = " + z.ToString();
            double u = SixTask(x, y, z);
            // Выводим результат в окно
            textBox4.Text += Environment.NewLine +
            "\nРезультат U = " + u.ToString();
        }


    }
}
