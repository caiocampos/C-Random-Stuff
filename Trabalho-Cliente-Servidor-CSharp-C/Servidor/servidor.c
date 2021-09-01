#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
    #define snprintf _snprintf
    #define vsnprintf _vsnprintf
    #define strcasecmp _stricmp
    #define strncasecmp _strnicmp
#endif

#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
#endif

#pragma warning (disable : 4996)

#define CGI_URL "http://localhost/cgi-bin/run.cgi"

typedef struct divida {
	float valor;
	int dia;
	char mes[2];
	int ano;
	struct divida *proxima;
} tipoDivida; // estrutura que armazena divida

typedef struct cliente {
	char nome[100];
	char endereco[100];
	char telefone[20];
	char cpf[20];
	int codigo;
} Cpessoa; // estrutura que armazena cliente

typedef struct lista {
	Cpessoa dados;
	tipoDivida *dividas;
	struct lista *proximo; // apontador para o próximo elemento
} Tlista; // estrutura que armazena a lista encadeada

Tlista *inicio = NULL; // lista de clientes e dividas

void salva_cliente(Cpessoa cli) { // salva o cliente no arquivo
	FILE *arq = fopen("cli.txt", "a"); // abre o arquivo
	fprintf(arq, "%s\n", cli.nome);
	fprintf(arq, "%s\n", cli.endereco);
	fprintf(arq, "%s\n", cli.telefone);
	fprintf(arq, "%s\n", cli.cpf);
	fprintf(arq, "%d\n", cli.codigo);
	fclose(arq); // fecha o arquivo
}

void salva_divida(tipoDivida div, int codigo) { // salva a divida no arquivo
	FILE *arq = fopen("div.txt", "a"); // abre o arquivo
	fprintf(arq, "%f\n", div.valor);
	fprintf(arq, "%d\n", div.dia);
	fprintf(arq, "%s\n", div.mes);
	fprintf(arq, "%d\n", div.ano);
	fprintf(arq, "%d\n", codigo); // escreve no arquivo o código do cliente que a divida está relacionada
	fclose(arq); // fecha o arquivo
}

Tlista *encontra_cliente(int codigo) { // retorna o nó da lista em que o cliente se encontra
	Tlista *aux = inicio; // cria um ponteiro indicando o inicio da lista
	while(aux != NULL) { // enquanto não chegou no fim da lista
		if(aux->dados.codigo == codigo) { // verifica se o cliente do nó possui um código igual ao pesquisado
			return aux; // se sim retorna o nó
		}
		else aux = aux->proximo; // se não vai para o próximo nó
	}
	return NULL; // se chegou no fim da lista e não encontrou retorna valor nulo
}

tipoDivida *criar_divida(float valor, int dia, char *mes, int ano, int cod_cli) { // cria a divida
	tipoDivida *novo; // ponteiro para nova divida
	tipoDivida *ponteiro = NULL; // ponteiro auxiliar
	Tlista *aux;
	aux = encontra_cliente(cod_cli); // procura o nó onde está o cliente indicado
	novo = (tipoDivida *)malloc(sizeof(tipoDivida)); // aloca memória para divida
	if(valor <= 0 || dia <= 0 || dia > 31 || ano == 0 || aux == NULL || novo == NULL) { // verifica se algum valor está errado
		return NULL; // se sim retorna valor nulo
	}
	else { // se não
		ponteiro = aux->dividas; // faz o ponteiro indicar o começo da lista de dividas do cliente
		if(ponteiro == NULL) { // se não existirem dividas relacionadas ao cliente
			aux->dividas = novo; // coloca a nova divida como a primeira divida
		}
		else { // se existirem dividas
			while(ponteiro->proxima != NULL) { // enquanto existir a próxima divida
				ponteiro = ponteiro->proxima; // apontar para a próxima
			}
            // quando chegar na ultima divida
			ponteiro->proxima = novo; // colocar a nova divida como a próxima
		}
		novo->valor = valor;
		novo->dia = dia;
		strcpy(novo->mes, mes);
		novo->ano = ano;
		novo->proxima = NULL;
		return novo; // retorna o endereço da divida
	}
}

void cadas_divida(float valor, int dia, char *mes, int ano, int cod_cli) { // cadastrar divida
	tipoDivida *novo = criar_divida(valor, dia, mes, ano, cod_cli); // cria a divida
	if(novo == NULL) { // se não conseguiu
		printf("Erro ao cadastrar divida\n"); // retornar mensagem de erro
	}
	else { // se conseguiu
		salva_divida(*novo, cod_cli); // salvar a divida em arquivo
		printf("Cadastro realizado\n"); // retornar mensagem de sucesso
	}
}

int criar_elemento(Cpessoa dado) { // cria o nó da lista
	Tlista *novo; // ponteiro para o novo nó
	Tlista *aux = inicio; // ponteiro indicando o inicio da lista
	novo = (Tlista *)malloc(sizeof(Tlista)); // aloca o nó
	if(dado.codigo <= 0 || encontra_cliente(dado.codigo) != NULL || novo == NULL) { // verifica algum valor errado
		return -1; // se sim retorna sinal de erro
	}
	else { // se não
		if(inicio == NULL) { // se não houver nenhum nó na lista
			inicio = novo; // colocar o novo nó como primeiro da lista
		}
		else { // se existir outros elementos
			while(aux->proximo != NULL) { // enquanto o próximo existe
				aux = aux->proximo; // aponta para o próximo
			}
            // quando chegar no final da lista
			aux->proximo = novo; // apontar o novo nó como próximo
		}
		novo->dados = dado;
		novo->dividas = NULL;
		novo->proximo = NULL;
		return 0; // retorna sinal de sucesso
	}
}

Cpessoa criar_cliente(char *nome, char *endereco, char *telefone, char *cpf, int codigo) { // cria o cliente
	Cpessoa cli;
	strcpy(cli.nome, nome);
	strcpy(cli.endereco, endereco);
	strcpy(cli.telefone, telefone);
	strcpy(cli.cpf, cpf);
	cli.codigo = codigo;
	return cli;
}

void cadas_cliente(Cpessoa dado) { // cadastrar cliente
	if(criar_elemento(dado) == -1) { // se não conseguiu criar o nó para o cliente
		printf("Erro ao cadastrar cliente\n"); // retorna mensagem de erro
	}
	else { // se criou o nó com sucesso
		salva_cliente(dado); // salva o cliente em arquivo
		printf("Cadastro realizado\n"); // retorna mensagem de sucesso
	}
}

void consulta(int codigo) { // faz consulta do cliente
	Tlista *aux;
	tipoDivida *ponteiro;
	aux = encontra_cliente(codigo); // procura o cliente
	if(aux == NULL) { // se não encontrou o cliente
		printf("Cliente não encontrado\n"); // retorna mensagem de erro
		return; // fecha a função
	}
	// se encontrou o cliente imprime os dados
	printf("NOME: %s\n", aux->dados.nome);
	printf("ENDEREÇO: %s\n", aux->dados.endereco);
	printf("TELEFONE: %s\n", aux->dados.telefone);
	printf("CPF: %s\n", aux->dados.cpf);
	printf("CODIGO DO CLIENTE: %d\n\n", aux->dados.codigo);
	printf("DIVIDA:\n\n");
	if(aux->dividas == NULL) { // verifica se possui divida
		printf("NENHUMA DIVIDA\n\n"); // se não possui imprime mensagem falando que não possui dividas
	}
	else { // se possui dividas
		ponteiro = aux->dividas; // aponta para a primeira divida
		while(ponteiro != NULL) { // enquanto a divida apontada existir imprime os dados da divida
			printf("VALOR DA DIVIDA: %f\n", ponteiro->valor);
			printf("DIA: %d\n", ponteiro->dia);
			printf("MES: %s", ponteiro->mes);
			printf("ANO: %d\n\n", ponteiro->ano);
			ponteiro = ponteiro->proxima; // aponta para a próxima divida
		}
	}
	printf("______________________________________\n");
}

void relatorio() { // faz o relatório de todos os clientes
	Tlista *aux = inicio;
	tipoDivida *ponteiro;
	if(aux == NULL) { // se não existem clientes cadastrados
		printf("NENHUM CLIENTE ENCONTRADO\n"); // retorna mensagem de erro
		return; // fecha a função
	}
	while(aux != NULL) { // enquanto existir clientes imprimir seus dados
		printf("NOME: %s\n", aux->dados.nome);
		printf("ENDEREÇO: %s\n", aux->dados.endereco);
		printf("TELEFONE: %s\n", aux->dados.telefone);
		printf("CPF: %s\n", aux->dados.cpf);
		printf("CODIGO DO CLIENTE: %d\n\n", aux->dados.codigo);
		printf("DIVIDAS:\n\n");
		if(aux->dividas == NULL) { // verifica se possui divida
			printf("NENHUMA DIVIDA\n\n"); // se não possui imprime mensagem falando que não possui dividas
		}
		else { // se possui dividas
			ponteiro = aux->dividas; // aponta para a primeira divida
			while(ponteiro != NULL) { // enquanto a divida apontada existir imprime os dados da divida
				printf("VALOR DA DIVIDA: %f\n", ponteiro->valor);
				printf("DIA: %d\n", ponteiro->dia);
				printf("MES: %s", ponteiro->mes);
				printf("ANO: %d\n\n", ponteiro->ano);
				ponteiro = ponteiro->proxima; // aponta para a próxima divida
			}
		}
	    printf("______________________________________\n");
		aux = aux->proximo; // aponta para o próximo nó
	}
}

/** Converter uma string de dois caracteres hexa no caractere correspondente **/
char x2c(char *what) {
	register char digit;
	digit = (what[0] >= 'A' ? ((what[0] & 0xdf) - 'A') + 10 : (what[0] - '0'));
	digit *= 16;
	digit += (what[1] >= 'A' ? ((what[1] & 0xdf) - 'A') + 10 : (what[1] - '0'));
	return(digit);
}

/** Converter qualquer "escape sequence" %xx nos caracteres correspondentes **/
void unescape_url(char *url) {
	register int i, j;
	for(i = 0, j = 0; url[j]; ++i, ++j) {
		if((url[i] = url[j]) == '%') {
			url[i] = x2c(&url[j+1]) ;
			j += 2 ;
		}
	}
	url[i] = '\0' ;
}

/** Ler a entrada CGI e colocar todos os pares nome/valor na lista. **/
/** Retorna lista contendo nome1, valor1, nome2, valor2, ... , NULL **/
char **getcgivars() {
	register int i;
	char *request_method;
	int content_length;
	char *cgiinput;
	char **cgivars ;
	char **pairlist;
	int paircount;
	char *nvpair;
	char *eqpos;
	/** Dependendo do metodo de solicitacao, ler toda a entrada CGI e colocar em cgiinput **/
	/** (realmente deve produzir mensagens de erro HTML, em vez de sair com exit() ) **/
	request_method = getenv("REQUEST_METHOD");
	if(!strcmp(request_method, "GET") || !strcmp(request_method, "HEAD")) {
		cgiinput = strdup(getenv("QUERY_STRING"));
	}
	else if (!strcmp(request_method, "POST")) {
		/* strcasecmp() is not supported in Windows-- use strcmpi() instead */
		if(strcasecmp(getenv("CONTENT_TYPE"), "application/x-www-form-urlencoded")) {
			printf("getcgivars(): Unsupported Content-Type.\n");
			exit(1);
		}
		if (!(content_length = atoi(getenv("CONTENT_LENGTH")))) {
			printf("getcgivars(): No Content-Length was sent with the POST request.\n");
			exit(1);
		}
		if (!(cgiinput = (char *)malloc(content_length+1)) ) {
			printf("getcgivars(): Could not malloc for cgiinput.\n");
			exit(1);
		}
		if (!fread(cgiinput, content_length, 1, stdin)) {
			printf("Couldn't read CGI input from STDIN.\n");
			exit(1);
		}
		cgiinput[content_length] = '\0';
	}
	else {
		printf("getcgivars(): unsupported REQUEST_METHOD\n");
		exit(1);
	}
	/** Retornar todos os '+' para espacos **/
	for(i = 0; cgiinput[i]; i++)
		if(cgiinput[i] == '+') cgiinput[i] = ' ';
	/** Primeiro, quebrar nos "&" para extrair os pares nome-valor para pairlist **/
	pairlist = (char **)malloc(256 * sizeof(char **));
	paircount = 0;
	nvpair = strtok(cgiinput, "&");
	while(nvpair) {
		pairlist[paircount++] = strdup(nvpair);
		if(!(paircount % 256))
			pairlist = (char **)realloc(pairlist, (paircount + 256) * sizeof(char **));
		nvpair = strtok(NULL, "&");
	}
	pairlist[paircount] = 0; /* terminar a lista com NULL */
	/** Agora, da lista de pares extrair os nomes e valores **/
	cgivars = (char **)malloc((paircount * 2 + 1) * sizeof(char **));
	for(i = 0; i < paircount; i++) {
		if(eqpos = strchr(pairlist[i], '=')) {
			*eqpos = '\0' ;
			unescape_url(cgivars[i*2+1] = strdup(eqpos + 1));
		}
		else unescape_url(cgivars[i*2+1] = strdup(""));
		unescape_url(cgivars[i*2] = strdup(pairlist[i]));
	}
	cgivars[paircount*2] = 0; /* terminar a lista com NULL */
	/** Liberar tudo que deva ser liberado **/
	free(cgiinput);
	for(i = 0; pairlist[i]; i++) free(pairlist[i]);
	free(pairlist);
	/** Retornar a lista de strings nome-valor **/
	return cgivars;
}

void ResponsePlainTextMimeType() {
	printf("Content-type: text/plain\n\n") ;
}

int isEqual(const char *Str1, const char *Str2) {
	int result;
	if(strcmp(Str1,Str2) == 0) {
		result = 1;
	}
	else result = 0;
	return result;
}

void carregar_arquivo() {
	FILE *cli = fopen("cli.txt", "rt"); // abre o arquivo de clientes
	FILE *div;
	char buffer1[100];
	char buffer2[100];
	char buffer3[100];
	char buffer4[100];
	char buffer5[100];
	if(cli == NULL) return; // se não conseguir ler o arquivo fecha a função
	else { // se abriu o arquivo
		while(!feof(cli)) { // enquanto o arquivo não terminar
			if(fgets(buffer1, 100, cli) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer2, 100, cli) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer3, 100, cli) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer4, 100, cli) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer5, 100, cli) == NULL) break; // tenta ler se não conseguir quebra o laço
			criar_elemento(criar_cliente(buffer1, buffer2, buffer3, buffer4, atoi(buffer5))); // cria o cliente e o nó
		}
		fclose(cli); // fecha o arquivo
	}
	div = fopen("div.txt", "rt"); // abre o arquivo de dividas
	if(div == NULL) return; // se não conseguir ler o arquivo fecha a função
	else { // se abriu o arquivo
		while(!feof(div)) { // enquanto o arquivo não terminar
			if(fgets(buffer1, 100, div) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer2, 100, div) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer3, 100, div) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer4, 100, div) == NULL) break; // tenta ler se não conseguir quebra o laço
			if(fgets(buffer5, 100, div) == NULL) break; // tenta ler se não conseguir quebra o laço
			criar_divida((float)atof(buffer1), atoi(buffer2), buffer3, atoi(buffer4), atoi(buffer5)); // cria a divida
		}
		fclose(div); // fecha o arquivo
	}
}

void processRequest() { // responde a requisição HTTP
	char **cgivars;
	int i;
	cgivars = getcgivars();
	if(cgivars[0] == NULL) { // run.cgi (Nesse caso, sem nenhum argumento)
		ResponsePlainTextMimeType();
		printf("Mensagem não possui argumentos!\n"); // retorna erro
	}
	else { // run.cgi com argumento
		ResponsePlainTextMimeType();
		if(isEqual(cgivars[1], "cadcli")) { // cadastro de clientes
			Cpessoa cli = criar_cliente(cgivars[3], cgivars[5], cgivars[7], cgivars[9], atoi(cgivars[11])); // cria o cliente
			cadas_cliente(cli); // cadastra o cliente
		}
		else if(isEqual(cgivars[1], "caddiv")) { // cadastro de dividas
			cadas_divida((float)atof(cgivars[3]), atoi(cgivars[5]), cgivars[7], atoi(cgivars[9]), atoi(cgivars[11])); // cria e cadastra a divida
		}
		else if(isEqual(cgivars[1], "relatorio")) { // relatório
			if(isEqual(cgivars[3], "null")) relatorio(); // se no argumento estiver escrito "null", fazer o relatório de todos clientes
			else consulta(atoi(cgivars[3])); // se não, fazer a consulta para um cliente específico
		}
		else printf("Erro");
	}
	/** Liberar memoria **/
	for(i = 0; cgivars[i]; i++) free(cgivars[i]);
	free(cgivars);
}

int main(){
	carregar_arquivo(); // carrega os arquivos de cliente e de dividas
	processRequest();
	return 0;
}
