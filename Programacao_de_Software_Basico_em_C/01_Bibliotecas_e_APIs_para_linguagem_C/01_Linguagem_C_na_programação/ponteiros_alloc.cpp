#include <stdio.h>
#include <stdlib.h>

int main() {
	int *numbers = (int *) malloc(10* sizeof (int));
	
	if (numbers == NULL){
		printf("Erro ao alocar memoria\n");
		return 1;
	}
	
	for (int i = 0; i < 101; i++){
		numbers[i]=1;
		printf("Numero %d\n", i);
	}
	free(numbers);
	return 0;
}
