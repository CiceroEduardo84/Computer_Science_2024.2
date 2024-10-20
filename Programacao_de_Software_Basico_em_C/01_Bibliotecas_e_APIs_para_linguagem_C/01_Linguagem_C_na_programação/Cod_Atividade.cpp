/*Vamos escrever um programa que permite ao usu�rio inserir uma quantidade definida de n�meros
os armazenar em um array din�mico e depois exibir os n�meros inseridos.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int *array;
	int size, i;
	
	printf("Quantos n�meros voc� deseja inserir?");
	scanf("%d", &size);
	
	//Aloca��o din�mica de mem�ria
	array = (int*) malloc(size * sizeof(int));
	
	//Verificar aloca��o din�mica
	if (array == NULL){
		printf("Erro na aloca��o de memoria!");
		return -1;//Encerra o programa com erro
	}
	
	//Inser��o de n�meros no array
	for (i=0;i<size;i++){
		printf("Digite o n�mero %d: ", i+1);
		scanf("%d", &array[i]);	
	}
	
	//Exibi��o dos n�meros
	printf("Voc� inseriu: ");
	for (i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	//Libera��o de memoria
	free(array);
	
	return 0;
}
