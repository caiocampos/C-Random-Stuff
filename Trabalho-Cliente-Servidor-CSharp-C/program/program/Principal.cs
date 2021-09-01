using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace program
{
    public partial class Principal : Form
    {
        public Principal()
        {
            InitializeComponent();
        }

        private void cadCli_Click(object sender, EventArgs e)
        {
            // cria uma tela de cadastro de clientes
            CadasCliente cc = new CadasCliente();
            cc.ShowDialog();
        }

        private void cadDiv_Click(object sender, EventArgs e)
        {
            // cria uma tela de cadastro de diviida
            CadasDivida cd = new CadasDivida();
            cd.ShowDialog();
        }

        private void relatorio_Click(object sender, EventArgs e)
        {
            // cria uma tela de relatório
            Relatorio rl = new Relatorio();
            rl.ShowDialog();
        }

        private void pesqCli_Click(object sender, EventArgs e)
        {
            // cria uma tela de pesquisa
            Pesquisar ps = new Pesquisar();
            ps.ShowDialog();
        }
    }
}
