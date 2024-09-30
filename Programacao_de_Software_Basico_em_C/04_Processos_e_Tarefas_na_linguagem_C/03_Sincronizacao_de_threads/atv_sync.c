#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define INITIAL_BALANCE 10000

// Inicializa o mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int account_balance = INITIAL_BALANCE; // Saldo inicial da conta

// Função que será executada por cada thread para realizar um saque
void *withdraw(void *arg) {
    int amount = *(int *)arg; // Obtém a quantia a ser sacada a partir do argumento

    // Bloqueia o mutex para garantir acesso exclusivo à conta
    pthread_mutex_lock(&mutex);

    if (account_balance >= amount) {
        // Se o saldo for suficiente, realiza o saque
        printf("Thread %ld: Sacar %d\n", pthread_self(), amount);
        account_balance -= amount; // Atualiza o saldo da conta
        printf("Thread %ld: Novo saldo %d\n", pthread_self(), account_balance);
    } else {
        // Se o saldo for insuficiente, exibe uma mensagem de erro
        printf("Thread %ld: Fundos insuficientes para saque de %d\n", pthread_self(), amount);
    }

    // Desbloqueia o mutex
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS]; // Array para armazenar os identificadores dos threads
    int amounts[NUM_THREADS] = {1000, 2000, 1500, 3000, 2500, 1200, 1800, 2300, 1600, 1400}; // Quantias a serem sacadas

    // Cria os threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, withdraw, (void *)&amounts[i]);
    }

    // Espera que todos os threads completem suas operações
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Exibe o saldo final da conta
    printf("Saldo final da conta: %d\n", account_balance);
    pthread_mutex_destroy(&mutex); // Destroi o mutex
    return 0;
}
