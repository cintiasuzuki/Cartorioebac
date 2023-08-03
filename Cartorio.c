#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h>//Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo / "w" = write/escrever
	fprintf(file, cpf); //Salva o valor da variável cpf
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, ","); //Inclui vírgula após variável cpf
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, nome); // Salva o valor da variável nome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, ","); //Inclui vírgula após variável nome
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", sobrenome); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, sobrenome); //Salva o valor da variável sobrenome
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, ","); //Inclui vírgula após variável sobrenome
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cargo); //scanf = pausa o programa / %s refere-se a string (salva)
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, cargo); //Salva o valor da variável cargo
	fclose(file); //Fecha o arquivo
	
	system("pause"); // Após usuário digitar mensagem/opções, pausa o programa
	
		
	
}

int consultar() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo texto em Português
	
	//Início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s", cpf); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Cria o arquivo / "r" = read/ler
	
	if(file == NULL) //IF = Estrutura de decisão (SE o arquivo tiver resultado NULO)
	{
		printf("Não foi possível abrir o arquivo, não localizado. \n"); //Resposta para resultado NULL 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //WHILE = Estrutura de decisão (ENQUANTO se as informações forem correspondentes a estas e forem DIFERENTES de NULO)
	{
		printf("Essas são as informações do usuário: "); //Resposta para resultados DIFERENTES (!=) de NULL
		printf("%s", conteudo); //%s refere-se a string (salvar)
		printf("\n\n"); //Próxima linha
	}
	
	system("pause"); //Após usuário digitar mensagem/opções, pausa o programa
	
}

int deletar() //Função responsável por consultar os usuários no sistema
{
	//Início criação de variáveis/string
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informação do usuário
	scanf("%s", cpf); //scanf = pausa o programa / %s refere-se a string 
	
	remove(cpf); //Remove variável preenchida (cpf)
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Cria o arquivo / "r" = read/ler
	
	if(file == NULL) //IF = Estrutura de decisão (SE o arquivo tiver resultado NULO)
	{
		printf("O usuário não se encontra no sistema. \n"); //Resposta para resultado NULL
		system("pause"); //Após usuário digitar mensagem/opções, pausa o programa
	}
	
}



int main ()
    {	
	int opcao=0; //Definindo variáveis
	int laco=1;

	for(laco=1;laco=1;)
	{
	
	  system("cls"); //Responsável por limpar a tela
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("### Cartório da EBAC ###\n\n"); //Início do menu
	  printf("Escolha a opção desejada do menu: \n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes \n");
	  printf("\t3 - Deletar nomes \n\n"); 
	  printf("Opção: "); //Fim do menu
	
	  scanf("%d" , &opcao); //Armazenando a escolha do usuário
	
	  system("cls"); //Após usuário digitar mensagem/opção, comando limpa a tela
	  
	  
	  switch(opcao) //Início da seleção do menu
	  {
	  	case 1:
	  	registro(); //Chamada de funções
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
	    deletar();
		break;
		
		
		default:
		printf("Essa opção não está disponível\n");
		system("pause");
		break;
			
	  }
	
	  
	 
    }
}
