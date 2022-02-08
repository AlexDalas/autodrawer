
namespace AutoDrawer
{
    partial class SettingsForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.cursorOffsetCheck = new System.Windows.Forms.CheckBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.colorCommunication = new System.Windows.Forms.CheckBox();
            this.yNumeric = new System.Windows.Forms.NumericUpDown();
            this.xNumeric = new System.Windows.Forms.NumericUpDown();
            this.FreeDrawCheck = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.yNumeric)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.xNumeric)).BeginInit();
            this.SuspendLayout();
            // 
            // cursorOffsetCheck
            // 
            this.cursorOffsetCheck.AutoSize = true;
            this.cursorOffsetCheck.Location = new System.Drawing.Point(12, 12);
            this.cursorOffsetCheck.Name = "cursorOffsetCheck";
            this.cursorOffsetCheck.Size = new System.Drawing.Size(87, 17);
            this.cursorOffsetCheck.TabIndex = 0;
            this.cursorOffsetCheck.Text = "Cursor Offset";
            this.cursorOffsetCheck.UseVisualStyleBackColor = true;
            this.cursorOffsetCheck.CheckedChanged += new System.EventHandler(this.cursorOffsetCheck_CheckedChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(82, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "X Offset";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(183, 38);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Y Offset";
            // 
            // colorCommunication
            // 
            this.colorCommunication.AutoSize = true;
            this.colorCommunication.BackColor = System.Drawing.SystemColors.Control;
            this.colorCommunication.Enabled = false;
            this.colorCommunication.ForeColor = System.Drawing.SystemColors.ControlText;
            this.colorCommunication.Location = new System.Drawing.Point(12, 107);
            this.colorCommunication.Name = "colorCommunication";
            this.colorCommunication.Size = new System.Drawing.Size(155, 17);
            this.colorCommunication.TabIndex = 5;
            this.colorCommunication.Text = "Script Color Communication";
            this.colorCommunication.UseVisualStyleBackColor = false;
            // 
            // yNumeric
            // 
            this.yNumeric.Location = new System.Drawing.Point(133, 35);
            this.yNumeric.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            this.yNumeric.Name = "yNumeric";
            this.yNumeric.Size = new System.Drawing.Size(44, 20);
            this.yNumeric.TabIndex = 7;
            this.yNumeric.ValueChanged += new System.EventHandler(this.yNumeric_ValueChanged);
            // 
            // xNumeric
            // 
            this.xNumeric.Location = new System.Drawing.Point(32, 35);
            this.xNumeric.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            this.xNumeric.Name = "xNumeric";
            this.xNumeric.Size = new System.Drawing.Size(44, 20);
            this.xNumeric.TabIndex = 8;
            this.xNumeric.ValueChanged += new System.EventHandler(this.xNumeric_ValueChanged);
            // 
            // FreeDrawCheck
            // 
            this.FreeDrawCheck.AutoSize = true;
            this.FreeDrawCheck.BackColor = System.Drawing.SystemColors.Control;
            this.FreeDrawCheck.Enabled = false;
            this.FreeDrawCheck.ForeColor = System.Drawing.SystemColors.ControlText;
            this.FreeDrawCheck.Location = new System.Drawing.Point(12, 61);
            this.FreeDrawCheck.Name = "FreeDrawCheck";
            this.FreeDrawCheck.Size = new System.Drawing.Size(167, 17);
            this.FreeDrawCheck.TabIndex = 9;
            this.FreeDrawCheck.Text = "Free Draw 2 Support (Broken)";
            this.FreeDrawCheck.UseVisualStyleBackColor = false;
            this.FreeDrawCheck.Visible = false;
            this.FreeDrawCheck.CheckedChanged += new System.EventHandler(this.FreeDrawCheck_CheckedChanged);
            // 
            // SettingsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(253, 136);
            this.Controls.Add(this.FreeDrawCheck);
            this.Controls.Add(this.xNumeric);
            this.Controls.Add(this.yNumeric);
            this.Controls.Add(this.colorCommunication);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cursorOffsetCheck);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SettingsForm";
            this.ShowIcon = false;
            this.Text = "Settings";
            this.Load += new System.EventHandler(this.Form4_Load);
            ((System.ComponentModel.ISupportInitialize)(this.yNumeric)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.xNumeric)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox cursorOffsetCheck;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.CheckBox colorCommunication;
        private System.Windows.Forms.NumericUpDown yNumeric;
        private System.Windows.Forms.NumericUpDown xNumeric;
        private System.Windows.Forms.CheckBox FreeDrawCheck;
    }
}