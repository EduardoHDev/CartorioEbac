#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsav�l pelas strings

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Voc� escolheu a op��o de Registro de us�ario!\n");
	printf("Aperte ENTER para continuar.\n");
	system("pause");
	
	system("cls");
	
	printf("Digite o CPF a ser cadastrado: \n"); // Pede informa��o para o usuario para registro do CPF
	scanf("%s", cpf);

	strcpy(arquivo, cpf); // Responsavel por copiar os valores dos strings
	
	FILE *file; // Responsavel por criar arquivo
	file = fopen(arquivo, "w"); // comando para abrir o arquivo "w" para escrever um novo arquivo
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //comando para abrir o arquivo "a" para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n"); // Pede informa��o para o usuario para registro do nome
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: \n"); // Pede informa��o para o usuario para registro do sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n"); // Pede informa��o para o usuario para registro do cargo
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");

}

int consulta() // Fun��o respons�vel por consulta de usu�rio
{
	setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Voc� escolheu a op��o de Consulta de us�ario!\n");
	printf("Aperte ENTER para continuar.\n");
	system("pause");
	
	system("cls");
	
	printf("Digite o CPF a ser consultado: \n"); // Pede informa��o para o usu�rio para consulta do banco de dados
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r"); // comando para abrir o arquivo "r" para ler o arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() // Fun��o respons�vel por deletar usu�rio do banco de dados
{
	setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	char cpf[40];
	
	printf("Voc� escolheu a op��o de Deletar us�ario!\n");
	printf("Aperte ENTER para continuar.\n");
	system("pause");
	
	system("cls");
	
	printf("Informe o CPF do usu�rio que voc� deseja deletar: \n"); // Pede informa��o para o usuario para deletar informa��o do banco de dados
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r"); // comando para abrir o arquivo "r" para ler o arquivo
	
	if (file != NULL) // confirma��o de remo��o de usu�rio
	{
		printf("O usu�rio foi removido do sistema!\n");
		printf("Aperte ENTER para voltar ao menu!\n");
		system("pause");
	}
	
	fclose(file);
	remove(cpf);
	
	if(file == NULL) // Informa caso n�o seja localizado o usu�rio no bando de dados
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		printf("Aperte ENTER para voltar ao menu!\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //variavel utilizada para selecionar a op��o
	int laco=1;
	int confirm;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	
		printf("\t --- Cart�rio da EBAC --- \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar us�ario na plataforma.\n");
		printf("\t2 - Consultar us�ario na plataforma.\n");
		printf("\t3 - Deletar us�ario da plataforma.\n");
		printf("\t4 - Sair do sistema\n");
	
		printf("Digite a op��o desejada: ");
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //limpeza do menu ap�s sele��o da op��o
		
		switch(opcao)//inicio da sele��o
		{
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Voc� tem certeza que deseja sair do sistema?\n");
				printf("Se sim, digite 1. Caso contr�rio, digite 0: ");
				scanf("%d", &confirm);
				
				system("cls");
				
				if (confirm == 1)
				{
					printf("Obrigado por utilizar nosso sistema!\n");
					return 0;
				}
				else
				{
					printf("Retornando para o menu!\n");
					system("pause");
				}
			break;
			
			default:
				printf("Est� op��o n�o existe, favor retornar ao Menu e escolher uma op��o existente!\n");
				system("pause");
		}
	} //fim da sele��o
}
