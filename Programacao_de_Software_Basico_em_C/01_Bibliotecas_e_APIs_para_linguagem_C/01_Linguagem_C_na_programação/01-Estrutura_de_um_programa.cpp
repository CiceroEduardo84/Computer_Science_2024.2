/*Programa para imprimir uma mensagem de sauda��o,
Calcular a �rea de um cirulo e exibir o resultado.*/

//Inclus�o de bibliotecas
#include <stdio.h> //Biblioteca padr�o para entrada e sa�da

//Defini��o de constantes
//#define PI 3.4 //Definindo uma const para o valor de PI
const float PI = 3.14;

int main(){
	//Declara��o de vari�veis
	int raio = 5; //Vari�vel inteira para o raio do circulo
	float area; //Vari�vel float para a �rea do circulo
	
	//Impress�o de uma mensagem de sauda��es
	printf("Ola, bem-vindo ao programa de calculo de area de um circulo!");
	
	//c�lculo da �rea de um circulo
	area = PI*raio*raio;
	
	//exibi��o do resultado
	printf("A area do curculo com raip %d eh: %.2f\n", raio, area);
	
	//returno 0 indicandoque o programa terminou corretamente
	return 0;
	
}
