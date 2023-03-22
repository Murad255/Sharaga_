using System;
using System.Windows.Forms;

namespace Lab_2_2
{
    public partial class Form1 : Form
    {
        int buttonsCount = 1;
        int tagsCount = 1;
        int fieldsCount = 1;

        public Form1()
        {
            InitializeComponent();
        }

        void UpdateCoints()
        {
            l_buttons.Text = buttonsCount.ToString();
            l_tags.Text = tagsCount.ToString();
            l_fields.Text = fieldsCount.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Button thisButton = (Button)sender;
            Button button = new Button();
            button.Location = new System.Drawing.Point(thisButton.Location.X, 60 + 30 * buttonsCount);
            button.Name = "button" + (buttonsCount + 1).ToString();
            button.Size = thisButton.Size;
            button.Text = thisButton.Text;
            button.Click += new System.EventHandler(this.button1_Click);
            this.Controls.Add(button);
            buttonsCount++;
            UpdateCoints();
        }

        private void checkBox1_Click(object sender, EventArgs e)
        {
            CheckBox thisTag = (CheckBox)sender;
            CheckBox check = new CheckBox();
            check.AutoSize = true;
            check.Location = new System.Drawing.Point(thisTag.Location.X, 60 + 30 * tagsCount);
            check.Name = "checkBox" + (tagsCount + 1).ToString();
            check.Size = new System.Drawing.Size(57, 17);
            check.TabIndex = 1;
            check.Text = "метка";
            check.UseVisualStyleBackColor = true;
            check.Click += new System.EventHandler(this.checkBox1_Click);

            this.Controls.Add(check);
            tagsCount++;
            UpdateCoints();
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            TextBox thisText = (TextBox)sender;
            TextBox textBox = new TextBox();

            textBox.Location = new System.Drawing.Point(147, 60 + 30 * fieldsCount);
            textBox.Name = "textBox" + (fieldsCount + 1).ToString();
            textBox.Size = new System.Drawing.Size(100, 20);
            textBox.Text = "поле ввода";
            textBox.Click += new System.EventHandler(this.textBox1_Click);

            this.Controls.Add(textBox);
            fieldsCount++;
            UpdateCoints();
        }
    }
}
