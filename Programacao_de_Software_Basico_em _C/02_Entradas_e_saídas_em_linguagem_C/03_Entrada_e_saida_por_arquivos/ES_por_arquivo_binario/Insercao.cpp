#include <stdio.h> //Inclui a biblioteca padão I/O
#include <stdlib.h> //Inclui a biblioteca padrão de funções utilitárias, como 'exit'

//Define uma estrutura chamada 'Num' que contem 2 inteiros
struct Num {
	int n1, n2;
};

//Função principal
int main(){
	struct Num obj; // Declara uma variavel do tipo 'struct Num'
	FILE *fptr; // Declara um ponteiro para um arquivo

	// Abre (ou cria) um arquivo binário chamado "temp.bin" no modo de escrita binária
	if((fptr = fopen("temp.bin","wb")) == NULL){
		// Verifica se houve erro ao abrir ou criar arquivo
		// Se 'fptr' for NULL, imprime uma mensagem de erro e termina o programa
		printf("Erro ao abrir o arquivo");
		exit(1); //Encerra o programa com status de erro
	}
	
	//Loop para escrever dados no arquivo binário
	for (int n = 1; n < 10; n++){
		obj.n1 = n; //Atribui o valor de 'n' a 'n1' da estrutura
		obj.n2 = 12 + n; //Atribui o valor de '12 + n' a 'n2' da estrutura
		//Escreve a estrutura 'obj' no arquivo
		//'fwrite' escreve '1' bloco de dados do tamanho da 'struct Num' 
		fwrite(&obj, sizeof(struct Num), 1, fptr);	
	}
	
	//Fecha o arquivo
	fclose(fptr);
	
	//Imprime uma mensagem indicando que os dados foram gravados corretamente
	printf("Dados gravados no arquivo\n\n");
	
	//Encerra o progarama
	return 0;
}
