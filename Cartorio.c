#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo / "w" = write/escrever
	fprintf(file, cpf); //Salva o valor da vari�vel cpf
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, ","); //Inclui v�rgula ap�s vari�vel cpf
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", nome); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, nome); // Salva o valor da vari�vel nome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, ","); //Inclui v�rgula ap�s vari�vel nome
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, sobrenome); //Salva o valor da vari�vel sobrenome
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, ","); //Inclui v�rgula ap�s vari�vel sobrenome
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cargo); //scanf = pausa o programa / %s refere-se a string (salva)
	
	file = fopen(arquivo, "a"); //Abre o arquivo / "a" = atualiza
	fprintf(file, cargo); //Salva o valor da vari�vel cargo
	fclose(file); //Fecha o arquivo
	
	system("pause"); // Ap�s usu�rio digitar mensagem/op��es, pausa o programa
	
		
	
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo texto em Portugu�s
	
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //scanf = pausa o programa / %s refere-se a string (salvar)
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Cria o arquivo / "r" = read/ler
	
	if(file == NULL) //IF = Estrutura de decis�o (SE o arquivo tiver resultado NULO)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n"); //Resposta para resultado NULL 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //WHILE = Estrutura de decis�o (ENQUANTO se as informa��es forem correspondentes a estas e forem DIFERENTES de NULO)
	{
		printf("Essas s�o as informa��es do usu�rio: "); //Resposta para resultados DIFERENTES (!=) de NULL
		printf("%s", conteudo); //%s refere-se a string (salvar)
		printf("\n\n"); //Pr�xima linha
	}
	
	system("pause"); //Ap�s usu�rio digitar mensagem/op��es, pausa o programa
	
}

int deletar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //scanf = pausa o programa / %s refere-se a string 
	
	remove(cpf); //Remove vari�vel preenchida (cpf)
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Cria o arquivo / "r" = read/ler
	
	if(file == NULL) //IF = Estrutura de decis�o (SE o arquivo tiver resultado NULO)
	{
		printf("O usu�rio n�o se encontra no sistema. \n"); //Resposta para resultado NULL
		system("pause"); //Ap�s usu�rio digitar mensagem/op��es, pausa o programa
	}
	
}



int main ()
    {	
	int opcao=0; //Definindo vari�veis
	int laco=1;

	for(laco=1;laco=1;)
	{
	
	  system("cls"); //Respons�vel por limpar a tela
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	  printf("Escolha a op��o desejada do menu: \n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes \n");
	  printf("\t3 - Deletar nomes \n\n"); 
	  printf("Op��o: "); //Fim do menu
	
	  scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
	  system("cls"); //Ap�s usu�rio digitar mensagem/op��o, comando limpa a tela
	  
	  
	  switch(opcao) //In�cio da sele��o do menu
	  {
	  	case 1:
	  	registro(); //Chamada de fun��es
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
	    deletar();
		break;
		
		
		default:
		printf("Essa op��o n�o est� dispon�vel\n");
		system("pause");
		break;
			
	  }
	
	  
	 
    }
}
