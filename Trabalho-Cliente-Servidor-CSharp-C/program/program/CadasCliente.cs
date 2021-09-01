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
    public partial class CadasCliente : Form
    {
        public CadasCliente()
        {
            InitializeComponent();
        }

        private void cadastro_Click(object sender, EventArgs e)
        {
            // testa se existem campos vazios
            if (nome.Text.Equals("") || endereco.Text.Equals("") || telefone.Text.Equals("") || cpf.Text.Equals("") || codigo.Text.Equals(""))
                // se sim cria uma caixa de mensagem
                MessageBox.Show("Existem campos vazios", "Resultado", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            // se não
            else
            {
                // cria a texto de argumentos
                String ARGS = "action=cadcli&var1=" + nome.Text + "&var2=" + endereco.Text + "&var3=" + telefone.Text + "&var4=" + cpf.Text + "&var5=" + codigo.Text;
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