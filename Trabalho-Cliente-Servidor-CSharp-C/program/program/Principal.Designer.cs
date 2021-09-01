namespace program
{
    partial class Principal
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
            this.cadCli = new System.Windows.Forms.Button();
            this.cadDiv = new System.Windows.Forms.Button();
            this.relatorio = new System.Windows.Forms.Button();
            this.pesqCli = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // cadCli
            // 
            this.cadCli.Location = new System.Drawing.Point(80, 74);
            this.cadCli.Name = "cadCli";
            this.cadCli.Size = new System.Drawing.Size(154, 23);
            this.cadCli.TabIndex = 0;
            this.cadCli.Text = "Cadastrar novo cliente";
            this.cadCli.UseVisualStyleBackColor = true;
            this.cadCli.Click += new System.EventHandler(this.cadCli_Click);
            // 
            // cadDiv
            // 
            this.cadDiv.Location = new System.Drawing.Point(80, 103);
            this.cadDiv.Name = "cadDiv";
            this.cadDiv.Size = new System.Drawing.Size(154, 23);
            this.cadDiv.TabIndex = 1;
            this.cadDiv.Text = "Cadastrar nova dívida";
            this.cadDiv.UseVisualStyleBackColor = true;
            this.cadDiv.Click += new System.EventHandler(this.cadDiv_Click);
            // 
            // relatorio
            // 
            this.relatorio.Location = new System.Drawing.Point(80, 132);
            this.relatorio.Name = "relatorio";
            this.relatorio.Size = new System.Drawing.Size(154, 23);
            this.relatorio.TabIndex = 2;
            this.relatorio.Text = "Relatório";
            this.relatorio.UseVisualStyleBackColor = true;
            this.relatorio.Click += new System.EventHandler(this.relatorio_Click);
            // 
            // pesqCli
            // 
            this.pesqCli.Location = new System.Drawing.Point(80, 161);
            this.pesqCli.Name = "pesqCli";
            this.pesqCli.Size = new System.Drawing.Size(154, 23);
            this.pesqCli.TabIndex = 3;
            this.pesqCli.Text = "Pesquisar cituação do cliente";
            this.pesqCli.UseVisualStyleBackColor = true;
            this.pesqCli.Click += new System.EventHandler(this.pesqCli_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(292, 31);
            this.label1.TabIndex = 4;
            this.label1.Text = "Gerenciador de dívidas";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(77, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(104, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Escolha uma opção:";
            // 
            // Principal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(312, 204);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pesqCli);
            this.Controls.Add(this.relatorio);
            this.Controls.Add(this.cadDiv);
            this.Controls.Add(this.cadCli);
            this.Name = "Principal";
            this.Text = "Principal";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button cadCli;
        private System.Windows.Forms.Button cadDiv;
        private System.Windows.Forms.Button relatorio;
        private System.Windows.Forms.Button pesqCli;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}