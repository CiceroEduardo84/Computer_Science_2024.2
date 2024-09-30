#include <pthread.h> //Biblioteca para manipulação de threads
#include <stdio.h> 	//Biblioteca padrão de entrada e saída
#include <stdlib.h>//Biblioteca padrão para funções como exit()

#define NUM_THREADS 5 //Define o número de threads como 5

void *PrintHello(void *threadid){
	long tid;
	
	tid = (long)threadid; //Converter o identificador da thread para um tipo long
	printf("Alo mundo! Sou eu, thread #%d!\n", tid);//Imprime o identificador da thread
	pthread_exit(NULL);//Encerra a thread
}

int main (int argc, char *argv){
	pthread_t threads[NUM_THREADS];//DEclaração de uma array para armazenar os IDs das threads
	int rc;//Variável para armazena o cod de retorno de criação da thread
	int t;//Variável usada para iterar e identificar cada thread
	
	//Cria multiplas threads
	for (t=0; t< NUM_THREADS; t++){
		printf("Em main: criando thread %d\n", t);//Imprime a criação de thread
		// Cria uma nova thread que executa a função PrintHello
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		
		/*
		
		Argumentos:
		
		thread - Identificador opaco e exclusivo para o novo thread retornado pela sub-rotina.
		attr - Um objeto de atributo opaco que pode ser usado para definir atributos de therads
		Você pode especificar um objeto de atributos de thread ou NULL para os valores padrão 
		start_routine - a função C que o theread executará depois de criado.
		arg - UM único argumento que pode ser passado para start_routine. Deve ser passado por
		referência como um ponteiro convertido do tipo void. NULL pode ser usado se nenhum argumento for passado.
	
		*/
	
		// Verifica se a criação da thread foi bem-sucedida
		if(rc){
			printf("Erro; código de retorno de pthread_create() eh %d\n", rc); //Imprime mensagem de erro se pthread_create falhar
			exit(-1);//Encerra o programa em caso de erro
		}
	}
	
	/*Á ultima coisa que a função main() deve fazer*/
	//Aguardar que todas as threads terminem antes de encerrar o programa
	pthread_exit(NULL);
}