namespace Ses_Lab_1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.bt_Connect = new System.Windows.Forms.Button();
            this.bt_Out = new System.Windows.Forms.Button();
            this.bt_Red = new System.Windows.Forms.Button();
            this.bt_Yelow = new System.Windows.Forms.Button();
            this.bt_Green = new System.Windows.Forms.Button();
            this.cbPorts = new System.Windows.Forms.ComboBox();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.bt_revers = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // bt_Connect
            // 
            this.bt_Connect.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt_Connect.Location = new System.Drawing.Point(104, 32);
            this.bt_Connect.Margin = new System.Windows.Forms.Padding(2);
            this.bt_Connect.Name = "bt_Connect";
            this.bt_Connect.Size = new System.Drawing.Size(150, 30);
            this.bt_Connect.TabIndex = 0;
            this.bt_Connect.Text = "Подключение";
            this.bt_Connect.UseVisualStyleBackColor = true;
            this.bt_Connect.Click += new System.EventHandler(this.bt_Connect_Click);
            // 
            // bt_Out
            // 
            this.bt_Out.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt_Out.Location = new System.Drawing.Point(4, 17);
            this.bt_Out.Margin = new System.Windows.Forms.Padding(2);
            this.bt_Out.Name = "bt_Out";
            this.bt_Out.Size = new System.Drawing.Size(108, 30);
            this.bt_Out.TabIndex = 1;
            this.bt_Out.Text = "Все";
            this.bt_Out.UseVisualStyleBackColor = true;
            this.bt_Out.Click += new System.EventHandler(this.bt_Out_Click);
            // 
            // bt_Red
            // 
            this.bt_Red.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt_Red.Location = new System.Drawing.Point(4, 59);
            this.bt_Red.Margin = new System.Windows.Forms.Padding(2);
            this.bt_Red.Name = "bt_Red";
            this.bt_Red.Size = new System.Drawing.Size(108, 30);
            this.bt_Red.TabIndex = 2;
            this.bt_Red.Text = "Красный";
            this.bt_Red.UseVisualStyleBackColor = true;
            this.bt_Red.Click += new System.EventHandler(this.bt_Red_Click);
            // 
            // bt_Yelow
            // 
            this.bt_Yelow.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt_Yelow.Location = new System.Drawing.Point(124, 59);
            this.bt_Yelow.Margin = new System.Windows.Forms.Padding(2);
            this.bt_Yelow.Name = "bt_Yelow";
            this.bt_Yelow.Size = new System.Drawing.Size(108, 30);
            this.bt_Yelow.TabIndex = 3;
            this.bt_Yelow.Text = "Жёлтый";
            this.bt_Yelow.UseVisualStyleBackColor = true;
            this.bt_Yelow.Click += new System.EventHandler(this.bt_Yelow_Click);
            // 
            // bt_Green
            // 
            this.bt_Green.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt_Green.Location = new System.Drawing.Point(124, 17);
            this.bt_Green.Margin = new System.Windows.Forms.Padding(2);
            this.bt_Green.Name = "bt_Green";
            this.bt_Green.Size = new System.Drawing.Size(108, 30);
            this.bt_Green.TabIndex = 4;
            this.bt_Green.Text = "Зелёный";
            this.bt_Green.UseVisualStyleBackColor = true;
            this.bt_Green.Click += new System.EventHandler(this.bt_Green_Click);
            // 
            // cbPorts
            // 
            this.cbPorts.FormattingEnabled = true;
            this.cbPorts.Location = new System.Drawing.Point(14, 41);
            this.cbPorts.Margin = new System.Windows.Forms.Padding(2);
            this.cbPorts.Name = "cbPorts";
            this.cbPorts.Size = new System.Drawing.Size(80, 21);
            this.cbPorts.TabIndex = 5;
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(4, 31);
            this.trackBar1.Margin = new System.Windows.Forms.Padding(2);
            this.trackBar1.Maximum = 255;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(220, 45);
            this.trackBar1.TabIndex = 6;
            this.trackBar1.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.bt_Out);
            this.groupBox1.Controls.Add(this.bt_Green);
            this.groupBox1.Controls.Add(this.bt_Red);
            this.groupBox1.Controls.Add(this.bt_Yelow);
            this.groupBox1.Location = new System.Drawing.Point(9, 91);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(2);
            this.groupBox1.Size = new System.Drawing.Size(245, 108);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Светодиоды";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.bt_revers);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.trackBar1);
            this.groupBox2.Location = new System.Drawing.Point(9, 213);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(2);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(2);
            this.groupBox2.Size = new System.Drawing.Size(245, 133);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Мотор";
            // 
            // bt_revers
            // 
            this.bt_revers.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.bt_revers.Location = new System.Drawing.Point(4, 96);
            this.bt_revers.Margin = new System.Windows.Forms.Padding(2);
            this.bt_revers.Name = "bt_revers";
            this.bt_revers.Size = new System.Drawing.Size(108, 30);
            this.bt_revers.TabIndex = 5;
            this.bt_revers.Text = "Реверс";
            this.bt_revers.UseVisualStyleBackColor = true;
            this.bt_revers.Click += new System.EventHandler(this.bt_revers_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(208, 63);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(25, 13);
            this.label2.TabIndex = 10;
            this.label2.Text = "255";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 63);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(13, 13);
            this.label1.TabIndex = 9;
            this.label1.Text = "0";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(13, 351);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(240, 60);
            this.textBox1.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(271, 416);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.cbPorts);
            this.Controls.Add(this.bt_Connect);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bt_Connect;
        private System.Windows.Forms.Button bt_Out;
        private System.Windows.Forms.Button bt_Red;
        private System.Windows.Forms.Button bt_Yelow;
        private System.Windows.Forms.Button bt_Green;
        private System.Windows.Forms.ComboBox cbPorts;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button bt_revers;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
    }
}

