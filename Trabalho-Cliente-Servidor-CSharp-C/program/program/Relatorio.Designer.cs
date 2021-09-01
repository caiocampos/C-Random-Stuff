namespace program
{
    partial class Relatorio
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
            this.caixaTextoRelatorio = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // caixaTextoRelatorio
            // 
            this.caixaTextoRelatorio.Location = new System.Drawing.Point(12, 12);
            this.caixaTextoRelatorio.Name = "caixaTextoRelatorio";
            this.caixaTextoRelatorio.Size = new System.Drawing.Size(260, 238);
            this.caixaTextoRelatorio.TabIndex = 0;
            this.caixaTextoRelatorio.Text = "";
            // 
            // Relatorio
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(283, 262);
            this.Controls.Add(this.caixaTextoRelatorio);
            this.Name = "Relatorio";
            this.Text = "Relatório";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox caixaTextoRelatorio;

    }
}