#include <stdio.h> //Biblioteca padr�o I/O
#include <stdlib.h> //Inclui a biblioteca padr�o de fun��es ultilit�rias, como 'exit'

//Fun��o principal do programa
int main(){
	FILE *ptr; //Declara um ponteiro para o arquivo
	
	//Abre (ou cria) um arquivo chamado "Hello.txt" no modo de escrita ("W")
	ptr = fopen("./Hello.txt", "w+");
	
	//Verificar se houve erro ao abrir ou criar o arquivo
	if (ptr == NULL){
		//Se "ptr" for NULL, imprime uma mensagem de erro e termina o programa
		printf("Erro ao criar o arquivo!");
		exit(1); //Encerra o programa com status de erro
	}
	
	//Define uma string de dados a ser escrita no arquivo
	char str[] = "Dados a serem inseridos no arquivo.";
	
	//Escreve a string no arquivo
	fputs(str, ptr);
	
	//Fecha o arquivo
	fclose(ptr);
	
	//Imprime uma mensagem indicando que os dados foram escritos com sucesso
	printf("Dados escritos no arquivo\n\n");
	
	// Retorna 0 para indicar que o programa terminou corretamente
	return 0;
	
}
