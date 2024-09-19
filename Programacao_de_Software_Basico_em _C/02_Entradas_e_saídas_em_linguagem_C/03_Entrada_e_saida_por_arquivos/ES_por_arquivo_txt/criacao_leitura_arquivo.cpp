#include <stdio.h> //Biblioteca padrão I/O
#include <stdlib.h> //Inclui a biblioteca padrão de funções ultilitárias, como 'exit'

//Função principal do programa
int main(){
	FILE *ptr; //Declara um ponteiro para o arquivo
	
	//Abre (ou cria) um arquivo chamado "Hello.txt" no modo de escrita ("W")
	ptr = fopen("./Hello.txt", "w");
	
	//Verificar se houve erro ao abrir ou criar o arquivo
	if (ptr == NULL){
		//Se "ptr" for NULL, imprime uma mensagem de erro e termina o programa
		printf("Erro ao criar o arquivo!");
		exit(1); //Encerra o programa com status de erro
	}
	
	//Fecha o arquivo
	fclose(ptr);
	
	//Imprime uma mensagem indicando que o arquivo foi criado com sucesso
	printf("Arquivo criado\n\n");
	
	// Retorna 0 para indicar que o programa terminou corretamente
	return 0;
	
}
