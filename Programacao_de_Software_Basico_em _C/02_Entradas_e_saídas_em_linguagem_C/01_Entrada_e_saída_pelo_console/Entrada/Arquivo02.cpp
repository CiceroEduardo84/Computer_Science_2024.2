#include <stdio.h>
#include <string.h>

//A função principal do progarama
int main(){
	// Declara um array de caracteres chamado 'string' com tamanho 80
	char string[80];
	
	// Imprime a mensagem "Digite um texto: " no console
	printf("Digite um texto:");
	
	//Lê uma linha de texto do usuário e armazena no array 'string'
	//'fgets lê até (sizeof(string)-1) caracteres ou até encontrar uma nova linha
	//O '\n' será incluído se houver espaço no buffer
	scanf("%s", string);
	
	//Imprime a string digitada pelo usuário
	printf("\nA string digitada eh:\n%s", string);
	
	//Retorna 0 para indicar que o programa terminou corretamente
	return 0;
	
}
