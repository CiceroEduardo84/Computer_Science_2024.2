/*Programa para imprimir uma mensagem de saudação,
Calcular a área de um cirulo e exibir o resultado.*/

//Inclusão de bibliotecas
#include <stdio.h> //Biblioteca padrão para entrada e saída

//Definição de constantes
//#define PI 3.4 //Definindo uma const para o valor de PI
const float PI = 3.14;

int main(){
	//Declaração de variáveis
	int raio = 5; //Variável inteira para o raio do circulo
	float area; //Variável float para a área do circulo
	
	//Impressão de uma mensagem de saudações
	printf("Ola, bem-vindo ao programa de calculo de area de um circulo!");
	
	//cálculo da área de um circulo
	area = PI*raio*raio;
	
	//exibição do resultado
	printf("A area do curculo com raip %d eh: %.2f\n", raio, area);
	
	//returno 0 indicandoque o programa terminou corretamente
	return 0;
	
}
