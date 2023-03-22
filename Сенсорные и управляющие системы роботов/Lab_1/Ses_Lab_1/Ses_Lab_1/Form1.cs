using System;
using System.Drawing;
using System.IO.Ports;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;


namespace Ses_Lab_1
{
    public partial class Form1 : Form
    {
        SerialPort serial;

        bool Red = false, Yelow = false, Green = false, Revers = false;
        int pastMotorVal = 0;
        int motorVal = 0;
        int serialSpeed = 9600;//115200;

        public Form1()
        {
            InitializeComponent();
            cbPorts.Items.Clear();
            int portCount = 0;
            foreach (string portName in SerialPort.GetPortNames())
            {
                cbPorts.Items.Add(portName);
                portCount++;
            }
            if (cbPorts.Items.Count > 0) cbPorts.SelectedIndex = 0;
            serial = new SerialPort();
            serial.BaudRate = serialSpeed;
            serial.DataReceived += SerialDataReceivedEventHandler;
        }

        void SerialDataReceivedEventHandler(object sender, SerialDataReceivedEventArgs e)
        {
            string str = serial.ReadLine();

            if (str != null)
            this.Invoke(new Action(() => {
                textBox1.Text += str;
                //textBox1.Text += "/n";
            }));

        }


        private void bt_Connect_Click(object sender, EventArgs e)
        {
            try
            {
                if (!serial.IsOpen)
                {
                    serial.PortName = cbPorts.Text;
                    do
                    {
                        serial.Open();
                        bt_Connect.BackColor = Color.Green;
                        Task.Run(() =>
                        {
                            Thread.Sleep(200);
                            while (serial.IsOpen)
                            {
                                if (pastMotorVal != motorVal)
                                {
                                    serial.Write(motorVal.ToString());
                                    pastMotorVal = motorVal;
                                }
                                Thread.Sleep(500);
                            }
                        });

                    } while (!serial.IsOpen);
                }
                else
                {
                    serial.Close();
                    bt_Connect.BackColor = Color.Red;

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка", ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error);
                bt_Connect.BackColor = Color.Wheat;

            }
        }

        private void bt_Out_Click(object sender, EventArgs e)
        {
            if (!(Green && Red && Yelow))
            {
                serial.Write("ON");
                Green = Red = Yelow = true;
            }
            else
            {
                serial.Write("OFF");
                Green = Red = Yelow = false;
            }
        }
        private void bt_Green_Click(object sender, EventArgs e)
        {
            if (Green)
                serial.Write("/G");
            else
                serial.Write("G");
            Green = !Green;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            motorVal = trackBar1.Value;
        }

        private void bt_revers_Click(object sender, EventArgs e)
        {
            if (Revers)
                serial.Write("/REV");
            else
                serial.Write("REV");
            Revers = !Revers;
        }

        private void bt_Red_Click(object sender, EventArgs e)
        {
            if (Red)
                serial.Write("/R");
            else
                serial.Write("R");
            Red = !Red;
        }

        private void bt_Yelow_Click(object sender, EventArgs e)
        {
            if (Yelow)
                serial.Write("/Y");
            else
                serial.Write("Y");
            Yelow = !Yelow;
        }
    }
}
