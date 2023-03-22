using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace Lab_1_Task_2
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
            radioButton1.Checked = true;
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
                FunctionType fType;
                if(radioButton1.Checked)
                    fType = FunctionType.sh_x;
                else if (radioButton2.Checked)
                    fType = FunctionType.x2;
                else
                    fType = FunctionType.e_x;

                // Вычисляем арифметическое выражение
                double u = SixTask2(x, y, fType);
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

        double SixTask2(double x, double b, FunctionType type)
        {
            double g;
            if (x * b > 0.5 && x * b < 10)
                g = Math.Pow(Math.E, f(x, type) - Math.Abs(b));
            if (x * b < 0.5 && x * b > 0.1)
                g = Math.Sqrt(Math.Abs(f(x,type)+b));
            else
                g = 2.0 * Math.Pow(f(x,type),2.0);

            return g;
        }

        double f(double x, FunctionType type)
        {
            switch (type)
            {
                case FunctionType.sh_x:
                    return Math.Sinh(x);
                case FunctionType.x2:
                    return Math.Pow(x, 2.0);
                case FunctionType.e_x:
                    return Math.Pow(Math.E, 2.0);
                default:
                    throw new Exception("Неверный тип уравнения");
            }
        }


        enum FunctionType
        {
            sh_x, x2, e_x
        }
    }
}
