using System;
using System.Windows.Forms;

namespace Lab_1_3
{
    public partial class Form1 : Form
    {
        const double x_0 = -1.5;
        const double b = -0.8;
        const double x_k = -2.5;
        const double d_x = -0.5;

        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            textBoxXmin.Text = "-5";
            textBoxXmax.Text = "5";
            textBoxStep.Text = "0,5";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Считываем с формы требуемые значения
            double Xmin = double.Parse(textBoxXmin.Text);
            double Xmax = double.Parse(textBoxXmax.Text);
            double Step = double.Parse(textBoxStep.Text);
            // Количество точек графика
            int count = (int)Math.Ceiling((Xmax - Xmin) / Step) + 1;
            // Массив значений X – общий для обоих графиков
            double[] x = new double[count];
            // Два массива Y – по одному для каждого графика
            double[] y1 = new double[count];
            double[] y2 = new double[count];
            // Расчитываем точки для графиков функции
            for (int i = 0; i < count; i++)
            {
                // Вычисляем значение X
                x[i] = Xmin + Step * i;
                // Вычисляем значение функций в точке X
                y1[i] = f1(x[i]);
                y2[i] = f2(x[i]);
            }
            // Настраиваем оси графика
            chart1.ChartAreas[0].AxisX.Minimum = Xmin;
            chart1.ChartAreas[0].AxisX.Maximum = Xmax;
            // Определяем шаг сетки
            chart1.ChartAreas[0].AxisX.MajorGrid.Interval = Step;
            // Добавляем вычисленные значения в графики
            chart1.Series[0].Points.DataBindXY(x, y1);
            chart1.Series[1].Points.DataBindXY(x, y2);
        }

        double f1(double x)
        {
            return Math.Pow(x, 2) + Math.Tan(5.0*x+ b/x);
        }

        double f2(double x)
        {
            return -0.6 * Math.Pow(x, 3) + 2.0 *Math.Pow(x,2) + 5.0*x + x_0 ;
        }
    }
}
