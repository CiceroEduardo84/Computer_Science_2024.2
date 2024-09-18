#include <stdio.h>
#include <string.h>

int main(){
	// Declara um array de caracteres chamado 'str' com tamanho 80
	char str[80];
	
	// Copia a string literal "test saída pelo console" para array 'str'
	strcpy(str, "test saida pelo console");
	
	// Copia a string armazenada em 'str' seguida por uma nova linha
	puts(str);
	
	// Retorna 0 para indicar que o programa terminou corretamente
	return 0;
}

