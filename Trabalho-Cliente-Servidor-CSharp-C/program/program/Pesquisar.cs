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
    public partial class Pesquisar : Form
    {
        public Pesquisar()
        {
            InitializeComponent();
        }

        private void pesquisa_Click(object sender, EventArgs e)
        {
            int res;
            try
            {
                // tenta converter o campo do código do cliente
                res = int.Parse(codCli.Text);
            }
            catch (Exception ex)
            {
                // se der errado cria uma caixa de mensagem de erro
                MessageBox.Show("O campo de pesuisa deve conter apenas números inteiros", "Resultado", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                // fecha a função
                return;
            }
            // se a conversão der certo cria uma tela de relatório passando o código do cliente
            Relatorio rl = new Relatorio(res);
            rl.ShowDialog();
        }
    }
}
