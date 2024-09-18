#include <stdio.h>

// Função principal
int main(void){
	int i; // Declara uma variavel inteira 'i'.
	
	//Loop 'for' que itera de 1 a 7
	for (i = 1; i < 8; i++){
		//Imprime três valores em colunas com largura de 8 caracteres
		//Primeiro valor: i
		//Segundo valor: i ao quadrado (i*i)
		//Terceiro valor: i so cubo (i*i*i)
		printf("%8d %8d %8d\n", i, i*i, i*i*i);
	}
		
	//Imprime o valor justificado á direita com largura de 8 caracteres
	printf("Justificado a direita: %8d\n", i);
		
	//Imprime o valor justificado á esquerda com largura de 8 caracteres
	printf("Justificativa a esquerda: %-8d\n", i);
		
	//Retorna 0 para indicar que o programa terminou corretamente
	return 0;
}
