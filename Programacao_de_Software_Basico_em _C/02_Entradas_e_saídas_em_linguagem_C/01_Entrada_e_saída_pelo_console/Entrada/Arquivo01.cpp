#include <stdio.h>
#include <string.h>

//A função principal do progarama
int main(){
	// Declara um array de caracteres chamado 'string' com tamanho 5
	char string[5];
	
	// Imprime a mensagem "Digite um texto: " no console
	printf("Digite um texto:");
	
	//Lê uma linha de texto do usuário e armazena no array 'string'
	//'fgets lê até (sizeof(string)-1) caracteres ou até encontrar uma nova linha
	//O '\n' será incluído se houver espaço no buffer
	fgets(string, sizeof(string), stdin);
	
	//Imprime o comprimento da string digitada pelo usuário
	//'strlen' calcula o comprimento da string, excluindo o caractere nulo '\0' de term
	printf("\nO comprimento eh %d\n ", strlen(string));
	
	//Retorna 0 para indicar que o programa terminou corretamente
	return 0;
	
}
