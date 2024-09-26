/*Vamos escrever um programa que permite ao usuário inserir uma quantidade definida de números
os armazenar em um array dinâmico e depois exibir os números inseridos.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int *array;
	int size, i;
	
	printf("Quantos números você deseja inserir?");
	scanf("%d", &size);
	
	//Alocação dinâmica de memória
	array = (int*) malloc(size * sizeof(int));
	
	//Verificar alocação dinâmica
	if (array == NULL){
		printf("Erro na alocação de memoria!");
		return -1;//Encerra o programa com erro
	}
	
	//Inserção de números no array
	for (i=0;i<size;i++){
		printf("Digite o número %d: ", i+1);
		scanf("%d", &array[i]);	
	}
	
	//Exibição dos números
	printf("Você inseriu: ");
	for (i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	//Liberação de memoria
	free(array);
	
	return 0;
}
