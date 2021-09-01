using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;

namespace program
{
    public partial class Relatorio : Form
    {
        // criador para relatório de todos clientes
        public Relatorio()
        {
            InitializeComponent();
            // cria a texto de argumentos
            String ARGS = "action=relatorio&var1=null";
            WebClient client = new WebClient();
            // envia para o servidor a mensagem
            // Properties.Settings.Default.URL está configurado em App.config
            String resposta = client.DownloadString(Properties.Settings.Default.URL + "?" + ARGS);
            // se tiver resposta coloca o resultado na caixa de texto
            if(resposta != null) this.caixaTextoRelatorio.Text = resposta;
        }

        // criador para consulta de um cliente
        public Relatorio(int codigo)
        {
            InitializeComponent();
            // cria a texto de argumentos
            String ARGS = "action=relatorio&var1=" + codigo.ToString();
            WebClient client = new WebClient()
            // envia para o servidor a mensagem
            // Properties.Settings.Default.URL está configurado em App.config
            String resposta = client.DownloadString(Properties.Settings.Default.URL + "?" + ARGS);
            // se tiver resposta coloca o resultado na caixa de texto
            if (resposta != null) this.caixaTextoRelatorio.Text = resposta;
        }
    }
}
