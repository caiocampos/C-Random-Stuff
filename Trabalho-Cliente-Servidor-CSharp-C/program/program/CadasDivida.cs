using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace program
{
    public partial class CadasDivida : Form
    {
        public CadasDivida()
        {
            InitializeComponent();
        }

        private void cadastro_Click(object sender, EventArgs e)
        {
            // testa se existem campos vazios
            if (valor.Text.Equals("") || dia.Text.Equals("") || mes.Text.Equals("") || ano.Text.Equals("") || codCliente.Text.Equals(""))
                // se sim cria uma caixa de mensagem
                MessageBox.Show("Existem campos vazios", "Resultado", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            // se não
            else
            {
                // cria a texto de argumentos
                String ARGS = "action=caddiv&var1=" + valor.Text + "&var2=" + dia.Text + "&var3=" + mes.Text + "&var4=" + ano.Text + "&var5=" + codCliente.Text;
                WebClient client = new WebClient();
                // envia para o servidor a mensagem
                // Properties.Settings.Default.URL está configurado em App.config
                String resposta = client.DownloadString(Properties.Settings.Default.URL + "?" + ARGS);
                // se tiver resposta cria uma caixa de mensagem com o resultado
                if (resposta != null) MessageBox.Show(resposta, "Resultado", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }
    }
}