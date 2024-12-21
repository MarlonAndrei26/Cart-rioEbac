#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/sting
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf ("%s", cpf); //%s refere-se a String
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	
	file = fopen(arquivo, "a"); //acrescentando informa��es ao arquivo sem apagar informa��es j� existentes
	fprintf(file,"CPF "); //adicionando "espa�o/," na informa��o salva
	
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acrescentando informa��es ao arquivo sem apagar informa��es j� existentes
	fprintf(file,", Nome: "); //adicionando "espa�o/," na informa��o salva
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //%s refere-se ao String
	
	file = fopen(arquivo, "a"); //acrescentando informa��es ao arquivo sem apagar informa��es j� existentes
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acrescentando informa��es ao arquivo sem apagar informa��es j� existentes
	fprintf(file,", Sobrenome: "); //adicionando "espa�o/," na informa��o salva
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //%s refere-se ao String
	
	file = fopen(arquivo, "a"); //acrescentando informa��es ao arquivo sem apagar informa��es j� existentes
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acrescentando informa��es ao arquivo sem apagar informa��es j� existentes
	fprintf(file,", Cargo: "); //adicionando "espa�o/," na informa��o salva
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a String
	
	file = fopen (arquivo, "a"); //acrescentando informa��es ao arquivo sem apagar informa��es j� existentes
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //respons�vel por pausar a execu��o do programa e exibir a mensagem "aperte uma tecla para continuar"
	
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //solicitando informa��o para consulta
	scanf("%s",cpf); //%s refere-se ao String
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); //o "r" Abertura do arquivo em modo leitura para consulta
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");  //respons�vel por pausar a execu��o do programa e exibir a mensagem "aperte uma tecla para continuar"
	fclose(file); //fecha o arquivo
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
		remove(cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("Usu�rio deletado do sistema!.\n");
		system("pause");  //respons�vel por pausar a execu��o do programa e exibir a mensagem "aperte uma tecla para continuar"
		
	}
	
}


int main ()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela

		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break; 
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");  //respons�vel por pausar a execu��o do programa e exibir a mensagem "aperte uma tecla para continuar"
			break;
			//fim da sele��o do menu
		}
	
	}
	
} 
