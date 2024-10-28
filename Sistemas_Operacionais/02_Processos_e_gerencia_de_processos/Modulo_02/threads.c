#define GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unisted.h>
#include <sched.h>
#include <sys/wait.h>

#define TAMANHO_DA_PILHA 65536

int contador;

void function_A(void)
{
  while (1)
  { // Loop infinito.
    printf("Para a função A contador = %d.\n", contador);
    usleep(3000000); // Dorme 3 segundos.
  }
}

void function_B(void)
{
  while (1)
  { // Loop infinito.
    printf("Função B incrementado o contador.\n");
    contador += 1; // Incrementa o contador
    printf("Para a função B contador= %d. \n", contador);
    usleep(3000000); // Dorme 3 segundos.
  }
}

void main(void)
{
  void *pilha_A, *pilha_B;

  int i, pid_A, pid_B, id_A, id_B;

  // Aloca pilha para a theread A.
  if ((pilha_A = malloc(TAMANHO_DA_PILHA)) == 0)
  {
    perror("Erro na alocação da pilha para a função A.");
    exit(1);
  }

  // Aloca pilha para a thread B.
  if ((pilha_B = malloc(TAMANHO_DA_PILHA)) == 0)
  {
    perror("Erro na alocação da pilha para a função B.");
    exit(1);
  }

  contador = 0; // Inicializa o contador.
  // Coloca a função A em execução com theread.
  pid_A = clone(function_A, pilha_A + TAMANHO_DA_PILHA, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SINGHAND | SIGCHLD, &id_A);

  // Coloca a função A em execução com theread.
  pid_B = clone(function_B, pilha_B + TAMANHO_DA_PILHA, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SINGHAND | SIGCHLD, &id_B);

  // Coloca programa principal (thread principal) em espera
  waitpid(pid_A, 0, 0);
  waitpid(pid_B, 0, 0);
}