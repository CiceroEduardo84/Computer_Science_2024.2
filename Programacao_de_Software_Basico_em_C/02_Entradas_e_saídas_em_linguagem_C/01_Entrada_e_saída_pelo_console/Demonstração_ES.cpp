#include <stdio.h> // Biblioteca padr�o de E/S

//Fun��o principal do programa
int main(){
	char livro[100], autor[100]; //Declara arrays de caracteres para armazenar o nome
	int paginas; // Declara uma variavel inteira para armazenar o n�mero de p�ginas
	
	//Solicitar ao usu�rio para digitar o nome do livro
	printf("Digite o nome do livro:");
	
	//L� uma string com espa�os at� encontrar uma nova linha
	//" %99[^\n]" especifica que deve ler at� 99 caracteres ou at� encontrar uma nova linha
	// O espa�o antes de %99[^\n] � necessario para ignorar quaisquer espa�os em branco
	scanf(" %99[^\n]", livro);
	
	//Solicita ao usu�rio para digitar o nome do autor
	printf("Digite o nome do author:");
	//L� uma string com espa�os at� encontrar uma nova linha 
	// A mesma l�gica de leitura � aplicada aqui
	scanf(" %99[^\n]", autor);
	
	//Solicita ao usu�rio para digitar o n�mero de p�ginas
	printf("Digite o numero de paginas:");
	//L� uma valor inteiro e armazena na variavel 'paginas' 
	scanf("%d", &paginas);
	
	//Imprime os detalhes do livro registrado
	printf("\nVoce registrou o livro: '%s' de '%s', com %d paginas.\n", livro, autor, paginas);
	
	//Retorna 0 para indicar que o programa terminou corretamente
	return 0;
}

