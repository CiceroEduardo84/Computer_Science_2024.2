#include <stdio.h>
#include <string.h>

//A fun��o principal do progarama
int main(){
	// Declara um array de caracteres chamado 'string' com tamanho 5
	char string[5];
	
	// Imprime a mensagem "Digite um texto: " no console
	printf("Digite um texto:");
	
	//L� uma linha de texto do usu�rio e armazena no array 'string'
	//'fgets l� at� (sizeof(string)-1) caracteres ou at� encontrar uma nova linha
	//O '\n' ser� inclu�do se houver espa�o no buffer
	fgets(string, sizeof(string), stdin);
	
	//Imprime o comprimento da string digitada pelo usu�rio
	//'strlen' calcula o comprimento da string, excluindo o caractere nulo '\0' de term
	printf("\nO comprimento eh %d\n ", strlen(string));
	
	//Retorna 0 para indicar que o programa terminou corretamente
	return 0;
	
}
