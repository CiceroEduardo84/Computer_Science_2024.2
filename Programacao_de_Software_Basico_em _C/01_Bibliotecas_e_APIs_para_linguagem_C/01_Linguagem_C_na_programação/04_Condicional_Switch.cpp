#include <stdio.h>
int main(){
	int escolha;
	printf("Escolha seu produto: 1 para �gua, 2 para Refrigerante, 3 para suco \n");
	scanf("%d", &escolha);
	switch(escolha){
		case 1:
			printf("Voce escolheu �gua!\n");
			break;
		case 2:
			printf("Voce escolheu Refrigerente!\n");
			break;
		case 3:
			printf("Voce escolheu Suco!\n");
			break;
		default:
			printf("Op��o inv�lida. Por favor, escolha um outro produto!");
	}
return 0;
}

