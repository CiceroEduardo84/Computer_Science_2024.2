#include <stdio.h>

// Fun��o que utiliza um contador est�tico
void incrementaContador(){
	//Declara��o do contador est�tico
	static int contador =0;
	
	//Incrementa o contador
	contador++;
	
	// Imprime o valor atual do contador
	printf("Contador: %d\n", contador);
}

 int main(){
 	//Chama a fun��o v�rias vezes para demonstrar o contador est�tico
 	incrementaContador();
 	incrementaContador();
 	incrementaContador();
 	incrementaContador();
 	
 	return 0;
 }
