#include <stdio.h>

int main(){
	int tabela[4][5];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			tabela[i][j] = i * j;
			printf("%d ", tabela[i][j]);
		}
		printf("\n");
	}
	return 0;
}
