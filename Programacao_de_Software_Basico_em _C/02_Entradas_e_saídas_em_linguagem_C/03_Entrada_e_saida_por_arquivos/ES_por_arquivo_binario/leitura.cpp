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
	if((fptr = fopen("temp.bin","rb")) == NULL){
		// Verifica se houve erro ao abrir ou criar arquivo
		// Se 'fptr' for NULL, imprime uma mensagem de erro e termina o programa
		printf("Erro ao abrir o arquivo");
		exit(1); //Encerra o programa com status de erro
	}
	
	//Loop para ler dados no arquivo binário
	for (int n = 1; n < 10; ++n){
		//Lê uma estrutura 'Num' do arquivo e armazena na variável 'obj' 
		fread(&obj, sizeof(struct Num), 1, fptr);
		//Imprime os valores de 'n1' e 'n2' lidos do arquivo
		printf("n: %d\tn2: %d\n", obj.n1, obj.n2);
	}
	
	//Fecha o arquivo
	fclose(fptr);
	
	//Encerra o progarama
	return 0;
}
