#include <stdio.h>

int main(){
	int temperatura;
	
	printf("Digite a temperatura atual: ");
	scanf("%d", &temperatura);
	
	if(temperatura < 0){
		printf("Está muito frio!\n");
	} else if(temperatura >= 0 ){
		printf("Está frio.\n");
	} else if(temperatura >=20 && temperatura < 30){
		printf("Está agradável.\n");
	} else {
		printf("Esta quente!\n");
	}
	
	return 0;
}
