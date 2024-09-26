#include <stdio.h>

// Função que utiliza um contador estático
void incrementaContador(){
	//Declaração do contador estático
	static int contador =0;
	
	//Incrementa o contador
	contador++;
	
	// Imprime o valor atual do contador
	printf("Contador: %d\n", contador);
}

 int main(){
 	//Chama a função várias vezes para demonstrar o contador estático
 	incrementaContador();
 	incrementaContador();
 	incrementaContador();
 	incrementaContador();
 	
 	return 0;
 }
