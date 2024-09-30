#include <stdio.h> 	//Biblioteca padrão de E/S
#include <stdlib.h> //Biblioteca padrão para funções como exit()
#include <pthread.h>//Biblioteca para manipulação de threads

#define NUM_THREADS 5 // Define o número de threads como 5

//Função que será executada por cada thread
void *perform_operation(void *arg){
	int thread_id = *(int *)arg;//Obtém o ID da thread a partir do argumento
	int result = 0; //Variável para armazenar o resultado da operação
	
	// Simula diferentes operações matemáticas baseadas no ID da thread
	switch(thread_id){
		case 0:
			result = thread_id*2; //Exemplo: multiplicação
			printf("Thread %d: Resultado da multiplicação = %d\n", thread_id, result);
			break;
		case 1:
			result = thread_id+100; //Exemplo: adição
			printf("Thread %d: Resultado da adição = %d\n", thread_id, result);
			break;
		case 2:
			result = thread_id-50; //Exemplo: subtração
			printf("Thread %d: Resultado da subtração = %d\n", thread_id, result);
			break;
		case 3:
			result = thread_id*2; //Exemplo: quadrado
			printf("Thread %d: Resultado do quadrado = %d\n", thread_id, result);
			break;
		case 4:
			result = thread_id*10; //Exemplo: multiplicação por 10
			printf("Thread %d: Resultado da multiplicação por 10 = %d\n", thread_id, result);
			break;
		default:
			printf("Thread %d: Nenhuma operação atribuida\n", thread_id);
			break;	
	}
	
	pthread_exit(NULL); //Encerra a thread
}

int main(){
	pthread_t threads[NUM_THREADS]; //Array para armazenar os identificadores das threads
	int threads_ids[NUM_THREADS]; //Array para armazenar os IDs das thereads
	int rc; //Variável para armazenar o cod. de retorno da criação da thread
	
	//Cria os thereads
	for(int i = 0; i < NUM_THREADS; i++){
		threads_ids[i] = i;//Define o ID da thread
		//Cria uma nova thread que executa a função perform_operation
		rc = pthread_create(&threads[i], NULL, perform_operation, (void *)&threads_ids[i]);
		//Verifica se a criação da thread foi bem-sucedida
		if(rc){
			printf("Erro: Não foi possivel criar o thread %d\n", i);//Mensagem de erro em caso de falha na criação da thread
			exit(-1);
		}
	}

	//Espera que todas as threads completem sua operações
	for(int i = 0; i<NUM_THREADS; i++){
		pthread_join(threads[i], NULL);//Aguardaa a thread espesificada terminar
	}

	printf("Todos os threads concluíram suas operações.\n");//Memoria indicando que todos os threads 
	return 0; //Encerra o programa com sucesso
}