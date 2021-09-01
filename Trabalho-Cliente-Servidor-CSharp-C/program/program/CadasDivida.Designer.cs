namespace program
{
    partial class CadasDivida
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
            this.valor = new System.Windows.Forms.TextBox();
            this.dia = new System.Windows.Forms.TextBox();
            this.mes = new System.Windows.Forms.TextBox();
            this.ano = new System.Windows.Forms.TextBox();
            this.codCliente = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.cadastro = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // valor
            // 
            this.valor.Location = new System.Drawing.Point(48, 52);
            this.valor.Name = "valor";
            this.valor.Size = new System.Drawing.Size(122, 20);
            this.valor.TabIndex = 0;
            // 
            // dia
            // 
            this.dia.Location = new System.Drawing.Point(48, 78);
            this.dia.Name = "dia";
            this.dia.Size = new System.Drawing.Size(82, 20);
            this.dia.TabIndex = 1;
            // 
            // mes
            // 
            this.mes.Location = new System.Drawing.Point(48, 104);
            this.mes.Name = "mes";
            this.mes.Size = new System.Drawing.Size(82, 20);
            this.mes.TabIndex = 2;
            // 
            // ano
            // 
            this.ano.Location = new System.Drawing.Point(48, 130);
            this.ano.Name = "ano";
            this.ano.Size = new System.Drawing.Size(82, 20);
            this.ano.TabIndex = 3;
            // 
            // codCliente
            // 
            this.codCliente.Location = new System.Drawing.Point(106, 156);
            this.codCliente.Name = "codCliente";
            this.codCliente.Size = new System.Drawing.Size(123, 20);
            this.codCliente.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 52);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Valor";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(23, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Dia";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 104);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(27, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Mês";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 130);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(26, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Ano";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 156);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(89, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "Código do cliente";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(12, 9);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(240, 31);
            this.label6.TabIndex = 10;
            this.label6.Text = "Cadastro de dívida";
            // 
            // cadastro
            // 
            this.cadastro.Location = new System.Drawing.Point(189, 182);
            this.cadastro.Name = "cadastro";
            this.cadastro.Size = new System.Drawing.Size(75, 23);
            this.cadastro.TabIndex = 11;
            this.cadastro.Text = "Cadastrar";
            this.cadastro.UseVisualStyleBackColor = true;
            this.cadastro.Click += new System.EventHandler(this.cadastro_Click);
            // 
            // CadasDivida
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(276, 215);
            this.Controls.Add(this.cadastro);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.codCliente);
            this.Controls.Add(this.ano);
            this.Controls.Add(this.mes);
            this.Controls.Add(this.dia);
            this.Controls.Add(this.valor);
            this.Name = "CadasDivida";
            this.Text = "Cadastro de dívida";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox valor;
        private System.Windows.Forms.TextBox dia;
        private System.Windows.Forms.TextBox mes;
        private System.Windows.Forms.TextBox ano;
        private System.Windows.Forms.TextBox codCliente;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button cadastro;
    }
}