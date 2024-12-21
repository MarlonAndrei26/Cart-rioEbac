#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string


int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/sting
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf ("%s", cpf); //%s refere-se a String
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	
	file = fopen(arquivo, "a"); //acrescentando informações ao arquivo sem apagar informações já existentes
	fprintf(file,"CPF "); //adicionando "espaço/," na informação salva
	
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acrescentando informações ao arquivo sem apagar informações já existentes
	fprintf(file,", Nome: "); //adicionando "espaço/," na informação salva
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",nome); //%s refere-se ao String
	
	file = fopen(arquivo, "a"); //acrescentando informações ao arquivo sem apagar informações já existentes
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acrescentando informações ao arquivo sem apagar informações já existentes
	fprintf(file,", Sobrenome: "); //adicionando "espaço/," na informação salva
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",sobrenome); //%s refere-se ao String
	
	file = fopen(arquivo, "a"); //acrescentando informações ao arquivo sem apagar informações já existentes
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //acrescentando informações ao arquivo sem apagar informações já existentes
	fprintf(file,", Cargo: "); //adicionando "espaço/," na informação salva
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cargo); //%s refere-se a String
	
	file = fopen (arquivo, "a"); //acrescentando informações ao arquivo sem apagar informações já existentes
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //responsável por pausar a execução do programa e exibir a mensagem "aperte uma tecla para continuar"
	
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //solicitando informação para consulta
	scanf("%s",cpf); //%s refere-se ao String
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); //o "r" Abertura do arquivo em modo leitura para consulta
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");  //responsável por pausar a execução do programa e exibir a mensagem "aperte uma tecla para continuar"
	fclose(file); //fecha o arquivo
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
		remove(cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("Usuário deletado do sistema!.\n");
		system("pause");  //responsável por pausar a execução do programa e exibir a mensagem "aperte uma tecla para continuar"
		
	}
	
}


int main ()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela

		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break; 
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");  //responsável por pausar a execução do programa e exibir a mensagem "aperte uma tecla para continuar"
			break;
			//fim da seleção do menu
		}
	
	}
	
} 
