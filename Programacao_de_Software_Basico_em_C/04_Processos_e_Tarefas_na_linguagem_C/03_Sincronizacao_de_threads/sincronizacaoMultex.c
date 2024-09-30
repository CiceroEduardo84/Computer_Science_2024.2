/*
 *
 *   pthreads-synch.c: Programa para demonstrar a sincronização de Pthreads
 *                     usando mutex e variáveis de condição em C no Linux
 *                     (Problema do Produtor-Consumidor)
 */

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

// Estruturas de dados do buffer
#define MAX_BUFFERS 10
char buf[MAX_BUFFERS][100];
int buffer_index;
int buffer_print_index;

pthread_mutex_t buf_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buf_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t spool_cond = PTHREAD_COND_INITIALIZER;
int buffers_available = MAX_BUFFERS;
int lines_to_print = 0;

void *producer(void *arg);
void *spooler(void *arg);

int main(int argc, char **argv) {
    pthread_t tid_producer[10], tid_spooler;
    int i, r;

    // Inicialização
    buffer_index = buffer_print_index = 0;

    // Cria a thread spooler
    if ((r = pthread_create(&tid_spooler, NULL, spooler, NULL)) != 0) {
        fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
    }

    // Cria 10 threads produtoras
    int thread_no[10];
    for (i = 0; i < 10; i++) {
        thread_no[i] = i;
        if ((r = pthread_create(&tid_producer[i], NULL, producer, (void *)&thread_no[i])) != 0) {
            fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
        }
    }
    // Aguarda as threads produtoras terminarem
    for (i = 0; i < 10; i++)
        if ((r = pthread_join(tid_producer[i], NULL)) == -1) {
            fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
        }
    
    // Não há mais strings para imprimir?
    while (lines_to_print) sleep(1);
    // Termina a thread spooler
    if ((r = pthread_cancel(tid_spooler)) != 0) {
        fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
    }

    exit(0);
}

// Função produtora: produz strings para impressão
// Pode haver múltiplas threads produtoras
void *producer(void *arg) {
    // Cria 10 strings e termina
    int i, r;
    int my_id = *((int *)arg);
    int count = 0;

    for (i = 0; i < 10; i++) {

        // Bloqueia o mutex
        if ((r = pthread_mutex_lock(&buf_mutex)) != 0) {
            fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
        }

        // Aguarda até que haja buffers disponíveis
        while (!buffers_available) 
            pthread_cond_wait(&buf_cond, &buf_mutex);

        // Incrementa o índice do buffer
        int j = buffer_index;
        buffer_index++;
        if (buffer_index == MAX_BUFFERS)
            buffer_index = 0;
        buffers_available--;

        // Produz uma string
        sprintf(buf[j], "Thread %d: %d\n", my_id, ++count);
        lines_to_print++;

        // Sinaliza que há linhas para imprimir
        pthread_cond_signal(&spool_cond);

        // Desbloqueia o mutex
        if ((r = pthread_mutex_unlock(&buf_mutex)) != 0) {
            fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
        }
    
        // Dá uma pausa
        sleep(1);
    }
}
// Há apenas uma thread spooler
void *spooler(void *arg) {
    int r;

    while (1) {  // Executa para sempre
        // Bloqueia o mutex
        if ((r = pthread_mutex_lock(&buf_mutex)) != 0) {
            fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
        }
        // Aguarda até que haja linhas para imprimir
        while (!lines_to_print) 
            pthread_cond_wait(&spool_cond, &buf_mutex);

        // Imprime a string
        printf("%s", buf[buffer_print_index]);
        lines_to_print--;

        // Incrementa o índice de impressão do buffer
        buffer_print_index++;
        if (buffer_print_index == MAX_BUFFERS)
            buffer_print_index = 0;

        buffers_available++;

        // Sinaliza que há buffers disponíveis
        pthread_cond_signal(&buf_cond);

        // Desbloqueia o mutex
        if ((r = pthread_mutex_unlock(&buf_mutex)) != 0) {
            fprintf(stderr, "Erro = %d (%s)\n", r, strerror(r)); exit(1);
        }

    }
}