#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavél pelas strings

int registro() // Função responsavel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Você escolheu a opção de Registro de usúario!\n");
	printf("Aperte ENTER para continuar.\n");
	system("pause");
	
	system("cls");
	
	printf("Digite o CPF a ser cadastrado: \n"); // Pede informação para o usuario para registro do CPF
	scanf("%s", cpf);

	strcpy(arquivo, cpf); // Responsavel por copiar os valores dos strings
	
	FILE *file; // Responsavel por criar arquivo
	file = fopen(arquivo, "w"); // comando para abrir o arquivo "w" para escrever um novo arquivo
	fprintf(file,cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //comando para abrir o arquivo "a" para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n"); // Pede informação para o usuario para registro do nome
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: \n"); // Pede informação para o usuario para registro do sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n"); // Pede informação para o usuario para registro do cargo
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");

}

int consulta() // Função responsável por consulta de usuário
{
	setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Você escolheu a opção de Consulta de usúario!\n");
	printf("Aperte ENTER para continuar.\n");
	system("pause");
	
	system("cls");
	
	printf("Digite o CPF a ser consultado: \n"); // Pede informação para o usuário para consulta do banco de dados
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r"); // comando para abrir o arquivo "r" para ler o arquivo
	
	if(file == NULL)
	{
		printf("O usuário não foi localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() // Função responsável por deletar usuário do banco de dados
{
	setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	char cpf[40];
	
	printf("Você escolheu a opção de Deletar usúario!\n");
	printf("Aperte ENTER para continuar.\n");
	system("pause");
	
	system("cls");
	
	printf("Informe o CPF do usuário que você deseja deletar: \n"); // Pede informação para o usuario para deletar informação do banco de dados
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r"); // comando para abrir o arquivo "r" para ler o arquivo
	
	if (file != NULL) // confirmação de remoção de usuário
	{
		printf("O usuário foi removido do sistema!\n");
		printf("Aperte ENTER para voltar ao menu!\n");
		system("pause");
	}
	
	fclose(file);
	remove(cpf);
	
	if(file == NULL) // Informa caso não seja localizado o usuário no bando de dados
	{
		printf("O usuário não se encontra no sistema!\n");
		printf("Aperte ENTER para voltar ao menu!\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //variavel utilizada para selecionar a opção
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
	
		printf("\t --- Cartório da EBAC --- \n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar usúario na plataforma.\n");
		printf("\t2 - Consultar usúario na plataforma.\n");
		printf("\t3 - Deletar usúario da plataforma.\n\n");
	
		printf("Digite a opção desejada: ");
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpeza do menu após seleção da opção
		
		switch(opcao)//inicio da seleção
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
			
			default:
				printf("Está opção não existe, favor retornar ao Menu e escolher uma opção existente!\n");
				system("pause");
		}
	} //fim da seleção
}
