#include <stdio.h>  // Biblioteca-padrão de entrada e saída
#include <stdlib.h> // Biblioteca-padrão de funções utilitárias
#include <unistd.h> // Biblioteca para chamadas ao sistema Posix (como sleep)
#include <pthread.h> // Biblioteca para manipulação de threads
  
// Uma função normal em C que é executada como um thread
// quando seu nome é especificado em pthread_create()
void *helloWorld(void *vargp)
{
    sleep(1); // Faz o thread dormir por 1 segundo
    printf("Alo mundo \n"); // Imprime "Hello World" na tela
    return NULL; // Retorna Null ao terminar a execução do thread
}
   
int main()
{
    pthread_t thread_id; // Declaração de uma variável para armazenar o ID do thread
    printf("Before Thread\n"); // Imprime antes de criar o thread
    pthread_create(&thread_id, NULL, helloWorld, NULL); // Cria um novo thread que executa a função helloWorld
    pthread_join(thread_id, NULL); // Espera até que o thread especificado termine
    printf("Após a Thread\n"); // Imprime após o thread ter terminado
    exit(0); // Encerra o programa
} 