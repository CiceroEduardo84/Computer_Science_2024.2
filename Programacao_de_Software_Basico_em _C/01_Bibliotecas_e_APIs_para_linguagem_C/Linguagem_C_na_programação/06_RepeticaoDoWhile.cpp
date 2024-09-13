#include <stdio.h>

int main(){
	int contador = 0;
	
	//Laço while para imprimir números de 0 a 4
	do{
		printf("Numero %d\n", contador);
		contador++;
	} while(contador<5);
	return 0;
}
