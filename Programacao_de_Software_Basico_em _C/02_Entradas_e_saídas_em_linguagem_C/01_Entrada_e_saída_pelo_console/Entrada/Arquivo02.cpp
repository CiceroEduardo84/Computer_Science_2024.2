#include <stdio.h>
#include <string.h>

//A fun��o principal do progarama
int main(){
	// Declara um array de caracteres chamado 'string' com tamanho 80
	char string[80];
	
	// Imprime a mensagem "Digite um texto: " no console
	printf("Digite um texto:");
	
	//L� uma linha de texto do usu�rio e armazena no array 'string'
	//'fgets l� at� (sizeof(string)-1) caracteres ou at� encontrar uma nova linha
	//O '\n' ser� inclu�do se houver espa�o no buffer
	scanf("%s", string);
	
	//Imprime a string digitada pelo usu�rio
	printf("\nA string digitada eh:\n%s", string);
	
	//Retorna 0 para indicar que o programa terminou corretamente
	return 0;
	
}
