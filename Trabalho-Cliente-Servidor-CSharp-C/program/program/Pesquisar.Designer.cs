namespace program
{
    partial class Pesquisar
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
            this.codCli = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.pesquisa = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // codCli
            // 
            this.codCli.Location = new System.Drawing.Point(108, 12);
            this.codCli.Name = "codCli";
            this.codCli.Size = new System.Drawing.Size(164, 20);
            this.codCli.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Código do cliente";
            // 
            // pesquisa
            // 
            this.pesquisa.Location = new System.Drawing.Point(197, 38);
            this.pesquisa.Name = "pesquisa";
            this.pesquisa.Size = new System.Drawing.Size(75, 23);
            this.pesquisa.TabIndex = 2;
            this.pesquisa.Text = "Pesquisar";
            this.pesquisa.UseVisualStyleBackColor = true;
            this.pesquisa.Click += new System.EventHandler(this.pesquisa_Click);
            // 
            // Pesquisar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 72);
            this.Controls.Add(this.pesquisa);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.codCli);
            this.Name = "Pesquisar";
            this.Text = "Pesquisar";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox codCli;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button pesquisa;
    }
}