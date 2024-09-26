#include <stdio.h> // Biblioteca padrão de E/S

//Função principal do programa
int main(){
	char livro[100], autor[100]; //Declara arrays de caracteres para armazenar o nome
	int paginas; // Declara uma variavel inteira para armazenar o número de páginas
	
	//Solicitar ao usuário para digitar o nome do livro
	printf("Digite o nome do livro:");
	
	//Lê uma string com espaços até encontrar uma nova linha
	//" %99[^\n]" especifica que deve ler até 99 caracteres ou até encontrar uma nova linha
	// O espaço antes de %99[^\n] é necessario para ignorar quaisquer espaços em branco
	scanf(" %99[^\n]", livro);
	
	//Solicita ao usuário para digitar o nome do autor
	printf("Digite o nome do author:");
	//Lê uma string com espaços até encontrar uma nova linha 
	// A mesma lógica de leitura é aplicada aqui
	scanf(" %99[^\n]", autor);
	
	//Solicita ao usuário para digitar o número de páginas
	printf("Digite o numero de paginas:");
	//Lê uma valor inteiro e armazena na variavel 'paginas' 
	scanf("%d", &paginas);
	
	//Imprime os detalhes do livro registrado
	printf("\nVoce registrou o livro: '%s' de '%s', com %d paginas.\n", livro, autor, paginas);
	
	//Retorna 0 para indicar que o programa terminou corretamente
	return 0;
}

