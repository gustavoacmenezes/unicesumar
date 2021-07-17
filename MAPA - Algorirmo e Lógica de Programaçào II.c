#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 200

typedef struct
{
	int codigoProjeto;
	char nomeProjeto[30], descricaoProjeto[200], anoProjeto[4], dataLimiteProjeto[10], setorDestinoProjeto[30], gerenteProjeto[30], statusProjeto[1], equipeProjeto[1];
}dados;

int posicao = 0;

void cadastrarProjeto(dados cadastro[MAX]);
void relatorioTotalProjetos(dados cadastro[MAX]);
void buscarProjetoCodigo(dados cadastro[MAX]);
void buscarProjetoNome(dados cadastro[MAX]);
void buscarProjetosEquipe(dados cadastro[MAX]);
void relatorioProjetosFazer(dados cadastro[MAX]);
void relatorioProjetosExecucao(dados cadastro[MAX]);
void relatorioProjetosConcluidos(dados cadastro[MAX]);


int main()
{
	setlocale(LC_ALL, "Portuguese");
	dados cadastro[MAX];
	
	int opcao;
	
	system("cls");	
	do
	{
		system("cls");
		printf("*************************************************");
		printf("\n*\t\t\t\t\t\t*");
		printf("\n*\t       CADASTRO DE PROJETOS\t\t*");
		printf("\n*\t\t\t\t\t\t*");
		printf("\n*************************************************");
		printf("\n* \t\t MENU DE OPÇÕES \t\t*");
		printf("\n* \t\t\t\t\t\t*");
		printf("\n*  1 - Cadastrar Projeto \t\t\t*");
		printf("\n*  2 - Imprimir todos os cadastros de Projetos  *");
		printf("\n*  3 - Buscar Projetos por código \t\t*");
		printf("\n*  4 - Buscar Projetos por Nome \t\t*");
		printf("\n*  5 - Buscar Projetos por Equipe \t\t*");
		printf("\n*  6 - Imprimir Projetos a Fazer \t\t*");
		printf("\n*  7 - Imprimir Projetos em Execução \t\t*");
		printf("\n*  8 - Imprimir Projetos Concluídos \t\t*");
		printf("\n*  9 - Sair \t\t\t\t\t*");
		printf("\n* \t\t\t\t\t\t*");
		printf("\n*************************************************");
		printf("\n << Escolha uma opção do menu: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				cadastrarProjeto(cadastro);			
				break;
			case 2:
				relatorioTotalProjetos(cadastro);
				break;
			case 3:
				buscarProjetoCodigo(cadastro);
				break;
			case 4:
				buscarProjetoNome(cadastro);
				break;
			case 5:
				buscarProjetosEquipe(cadastro);
				break;
			case 6:
				relatorioProjetosFazer(cadastro);
				break;
			case 7:
				relatorioProjetosExecucao(cadastro);
				break;
			case 8:
				relatorioProjetosConcluidos(cadastro);
				break;
			case 9:
				printf("\nSaindo da Aplicação\n");
				system("Pause");
				break;
			default:
				printf("\nOPÇÃO ESCOLHIDA INEXSISTENTE! POR FAVOR ESCOLHA OUTRA OPÇÃO!\n");
				system("Pause");
		}
	}while(opcao != 9);
	return 0;
}

void cadastrarProjeto(dados cadastro[MAX])
{
	system("cls");
	char resposta = 's';
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t\t     CADASTRO\t\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
	
	while(resposta == 's' && posicao <= MAX)
	{
		posicao++;
		printf("\n\nProjeto código: %d ", posicao);
		cadastro[posicao].codigoProjeto = posicao;
		printf("\nInforme o nome do projeto: ");
		scanf("%s", cadastro[posicao].nomeProjeto);
		printf("Descreva o projeto: ");
		scanf("%s", cadastro[posicao].descricaoProjeto);
		printf("Informe o ano de início do projeto: ");
		scanf("%s", cadastro[posicao].anoProjeto);	
		printf("Informe a data limite do projeto (dd/mm/aaaa): ");
		scanf("%s", cadastro[posicao].dataLimiteProjeto);
		printf("Informe o setor de destino do projeto: ");
		scanf("%s", cadastro[posicao].setorDestinoProjeto);
		printf("Informe o status do projeto: ");
		printf("\n 1 - A fazer");
		printf("\n 2 - Em execução");
		printf("\n 3 - Concluído\n");
		scanf("%s", cadastro[posicao].statusProjeto);
		printf("Informe a equipe respostaonsável pelo projeto: ");
		printf("\n 1- Equipe 1");
		printf("\n 2- Equipe 2");
		printf("\n 3- Equipe 3\n");
		scanf("%s", cadastro[posicao].equipeProjeto);
		printf("Informe o gerente do projeto: ");
		scanf("%s", cadastro[posicao].gerenteProjeto);
		
		if(posicao < MAX)
		{
			printf("\n\nDeseja cadastrar novo Projeto? [s] Sim [n] Não: ");
			fflush(stdin);
			scanf("%c", &resposta);
		}
		else
		{
			printf("\nSua base de Dados já chegou ao limite!!!\n");
			resposta = 'n';
		}
	}
}

void relatorioTotalProjetos(dados cadastro[MAX])
{
	system("cls");
	int i=1;
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t\t    RELATÓRIO\t\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
	
	
	if(posicao >= 1)
	{
		while(i <= posicao)
		{
			printf("\nCódigo do Projeto: %d", cadastro[i].codigoProjeto);
			printf("\n Nome do Projeto: %s", cadastro[i].nomeProjeto);
			printf("\n Descrição do Projeto: %s", cadastro[i].descricaoProjeto);
			printf("\n Ano do projeto: %s", cadastro[i].anoProjeto);
			printf("\n Data Limite do Projeto: %s", cadastro[i].dataLimiteProjeto);
			printf("\n Status do Projeto: %s", cadastro[i].statusProjeto);
			printf("\n Equipe respostaonsável pelo Projeto: %s", cadastro[i].equipeProjeto);
			printf("\n Gerente responsável pela equipe: %s\n", cadastro[i].gerenteProjeto);
			printf("\n=============================================================\n");
			i++;
		}	
			
	}else
	{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void buscarProjetoCodigo(dados cadastro[MAX])
{
	system("cls");
	int codigoProjeto, busca=0, i=0;
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t   BUSCA POR CÓDIGO DO PROJETO\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
	printf("\n\nEntre com o código do projeto: ");
	scanf("%d", &codigoProjeto);

	while((busca == 0) && (i <= posicao))
	{
		if(codigoProjeto == cadastro[i].codigoProjeto)
		{
			printf("\nCódigo do Projeto: %d", cadastro[i].codigoProjeto);
			printf("\n Nome do Projeto: %s", cadastro[i].nomeProjeto);
			printf("\n Descrição do Projeto: %s", cadastro[i].descricaoProjeto);
			printf("\n Ano do projeto: %s", cadastro[i].anoProjeto);
			printf("\n Data Limite do Projeto: %s", cadastro[i].dataLimiteProjeto);
			printf("\n Status do Projeto: %s", cadastro[i].statusProjeto);
			printf("\n Equipe respostaonsável pelo Projeto: %s", cadastro[i].equipeProjeto);
			printf("\n Gerente responsável pela equipe: %s\n\n", cadastro[i].gerenteProjeto);busca = 1;
			system("Pause");
		}
		i++;
	}
		if(busca == 0 )
		{
			printf("\nRegistro não encontrado com o código %d \n", codigoProjeto);
			system("Pause");
		}
}
void buscarProjetoNome(dados cadastro[MAX])
{
	system("cls");
	char nomeProjeto[30];
	int busca=0, i=0;
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t    BUSCA POR NOME DO PROJETO\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
	printf("\n\nEntre com o nome do projeto (idêntico ao digitado): ");
	fflush(stdin);
	scanf("%s", &nomeProjeto);
	while((busca == 0) && (i < MAX))
	{
		if(strcmp(cadastro[i].nomeProjeto,nomeProjeto)==0)
		{
			printf("\nCódigo do Projeto: %d", cadastro[i].codigoProjeto);
			printf("\n Nome do Projeto: %s", cadastro[i].nomeProjeto);
			printf("\n Descrição do Projeto: %s", cadastro[i].descricaoProjeto);
			printf("\n Ano do projeto: %s", cadastro[i].anoProjeto);
			printf("\n Data Limite do Projeto: %s", cadastro[i].dataLimiteProjeto);
			printf("\n Status do Projeto: %s", cadastro[i].statusProjeto);
			printf("\n Equipe respostaonsável pelo Projeto: %s", cadastro[i].equipeProjeto);
			printf("\n Gerente responsável pela equipe: %s\n\n", cadastro[i].gerenteProjeto);busca = 1;
			system("Pause");
		}
		i++;
	}
	if(busca == 0 )
	{
		printf("\nRegistro não encontrado com o nome %s \n", nomeProjeto);
		system("Pause");
	}
}

void buscarProjetosEquipe(dados cadastro[MAX])
{
	system("cls");
	char equipeProjeto[4];
	int i=0;
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t   BUSCA DE PROJETO POR EQUIPE\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
	printf("\nEquipes: ");
	printf("\n1- Equipe 1 ");
	printf("\n2- Equipe 2 ");
	printf("\n3- Equipe 3 \n");
	printf("\nEntre com o número da equipe desejada: ");
	fflush(stdin);
	scanf("%s", &equipeProjeto);
	
	while (i <= MAX)
	{
		if(strcmp(cadastro[i].equipeProjeto, equipeProjeto)==0)
		{
			printf("\n=============================================================\n");
			printf("\nCódigo do Projeto: %d", cadastro[i].codigoProjeto);
			printf("\n Nome do Projeto: %s", cadastro[i].nomeProjeto);
			printf("\n Descrição do Projeto: %s", cadastro[i].descricaoProjeto);
			printf("\n Ano do projeto: %s", cadastro[i].anoProjeto);
			printf("\n Data Limite do Projeto: %s", cadastro[i].dataLimiteProjeto);
			printf("\n Status do Projeto: %s", cadastro[i].statusProjeto);
			printf("\n Equipe respostaonsável pelo Projeto: %s", cadastro[i].equipeProjeto);
			printf("\n Gerente responsável pela equipe: %s\n\n", cadastro[i].gerenteProjeto);
		}
		i++;
	}
	printf("=============================================================\n\n");
	system("Pause");
}

void relatorioProjetosFazer(dados cadastro[MAX])
{
	system("cls");
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t    RELATÓRIO STATUS A FAZER\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
	int i=0;
	char statusProjeto[1]="1";
	
	if(posicao >= 1)
	{
		while(i <= posicao)
		{
			while (i < MAX)
			{
					if(strcmp(cadastro[i].statusProjeto, statusProjeto)==0)
					{
						printf("\nCódigo do Projeto: %d", cadastro[i].codigoProjeto);
						printf("\n Nome do Projeto: %s", cadastro[i].nomeProjeto);
						printf("\n Descrição do Projeto: %s", cadastro[i].descricaoProjeto);
						printf("\n Ano do projeto: %s", cadastro[i].anoProjeto);
						printf("\n Data Limite do Projeto: %s", cadastro[i].dataLimiteProjeto);
						printf("\n Status do Projeto: %s", cadastro[i].statusProjeto);
						printf("\n Equipe respostaonsável pelo Projeto: %s", cadastro[i].equipeProjeto);
						printf("\n Gerente responsável pela equipe: %s\n", cadastro[i].gerenteProjeto);
						printf("\n=============================================================\n\n");
						system("Pause");
					}
					i++;
			}
		}				
	}
	else
	{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void relatorioProjetosExecucao(dados cadastro[MAX])
{
	system("cls");
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t  RELATÓRIO STATUS EM EXECUÇÃO\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");;
	int i=0;
	char statusProjeto[1]="2";
	
	if(posicao >= 1)
	{
		while(i <= posicao)
		{
			while (i < MAX)
			{
				if(strcmp(cadastro[i].statusProjeto, statusProjeto)==0)
				{
					printf("\nCódigo do Projeto: %d", cadastro[i].codigoProjeto);
					printf("\n Nome do Projeto: %s", cadastro[i].nomeProjeto);
					printf("\n Descrição do Projeto: %s", cadastro[i].descricaoProjeto);
					printf("\n Ano do projeto: %s", cadastro[i].anoProjeto);
					printf("\n Data Limite do Projeto: %s", cadastro[i].dataLimiteProjeto);
					printf("\n Status do Projeto: %s", cadastro[i].statusProjeto);
					printf("\n Equipe respostaonsável pelo Projeto: %s", cadastro[i].equipeProjeto);
					printf("\n Gerente responsável pela equipe: %s\n", cadastro[i].gerenteProjeto);
					printf("\n=============================================================\n\n");
					system("Pause");
				}
				i++;
			}
		}	
			
	}else
	{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void relatorioProjetosConcluidos(dados cadastro[MAX])
{
	system("cls");
	printf("*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t   RELATÓRIO STATUS CONCLUÍDO\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
	int i=0;
	char statusProjeto[1]="3";
	
	if(posicao >= 1)
	{
		while(i <= posicao)
		{
			while (i < MAX)
			{
				if(strcmp(cadastro[i].statusProjeto, statusProjeto)==0)
				{
					printf("\nCódigo do Projeto: %d", cadastro[i].codigoProjeto);
					printf("\n Nome do Projeto: %s", cadastro[i].nomeProjeto);
					printf("\n Descrição do Projeto: %s", cadastro[i].descricaoProjeto);
					printf("\n Ano do projeto: %s", cadastro[i].anoProjeto);
					printf("\n Data Limite do Projeto: %s", cadastro[i].dataLimiteProjeto);
					printf("\n Status do Projeto: %s", cadastro[i].statusProjeto);
					printf("\n Equipe respostaonsável pelo Projeto: %s", cadastro[i].equipeProjeto);
					printf("\n Gerente responsável pela equipe: %s\n", cadastro[i].gerenteProjeto);
					printf("\n=============================================================\n\n");
					system("Pause");
				}
				i++;
			}
		}	
			
	}else
	{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}




