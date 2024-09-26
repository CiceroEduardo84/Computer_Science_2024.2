#include <stdio.h>
#include <time.h>
#include <Windows.h>

int main(){
	//Declaração de duas variáveis do tipo time_t
	time_t inicio, fim;
	
	//Captura o tempo atual e armazena na variável inicio
	time(&inicio);
	printf("Tempo inicial capturado...\n");
	
	//Simula uma pausa (espera) de 5 segundos
	printf("Esperando por 5 segundos...\n");
	for (int i = 0; i < 5; i++){
		printf("%d...\n",5-i);
		Sleep(1000);
	}
	
	//Captura o tempo atual novamente e armazena na variavel fim
	time(&fim);
	printf("Tempo final capturado.\n");
	
	//Calcula a diferença em segundos entre fim e inicio
	double diferenca = difftime(fim, inicio);
	
	//exibe a diferença em segundos
	printf("Adiferença em segundos eh: %.f segundos\n", diferenca);
	
	return 0;
}
