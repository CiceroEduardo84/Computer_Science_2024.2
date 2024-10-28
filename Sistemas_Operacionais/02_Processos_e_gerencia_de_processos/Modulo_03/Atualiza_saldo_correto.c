#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>

#define TAMANHO_PILHA 65536

typedef struct
{                // Simula registro de saldo em conta
  char nome[50]; // Nome do correntista
  double saldo;  // Saldo da conta
} Registro;

Registro registro[500];

// Função para criação de conta.
void cria_conta(char *nome, int numero, float saldo)
{
  strcpy(registro[numero].nome, nome);
  registro[numero].saldo = saldo;
}

// Função para mostrar a conta
void mostrar_conta(int numero)
{
  printf("A conta de %s possui R$%.2f.\n", registro[numero].nome, registro[numero].saldo);
}

// Função de leitura para registro na conta
Registro le_registro(int conta)
{
  return registro[conta];
}

// Função para gravação do registro na conta
void grava_registro(Registro reg, int conta)
{
  registro[conta] = reg;
}

// Função para atualização do saldo na conta
void atualiza_saldo(double valor, int conta)
{
  Registro reg;
  printf("Operação [%.2f] vai entrar na região  crítica \n", valor);
  up(&mutex); // Inicio da região crítica
  printf("Operação [%.2f] entro na região crítica\n", valor);
  reg = le_registro(conta); // Lê o resgitro da conta
  printf("Iniciando operação [%.2f] (saldo atual = R$%.2f)\n", valor, reg.saldo);
  sleep(1000); // Pequena pausa
  reg.saldo = reg.saldo + valor;
  grava_registro(reg, conta); // Grava saldo atualizado na conta.
  printf("Terminando operação [%.2f] (saldo atual = R$%.2f)\n", valor, reg.saldo);
  printf("Operação [%.2f] saindo da região crítica\n", valor);
  down(&mutex);
}

int funcaoDeposito(void *arg)
{
  // Faz deposito de 100,00
  atualiza_saldo(100, 231);
}

int funcaoSaque(void *arg)
{
  // Faz saque de 200,00
  atualiza_saldo(-200, 231);
}

int main()
{
  void *pilha1, *pilha2;
  int pid1, pid2;

  // Cria conta para teste
  cria_conta("Jose maria", 231, 500);
  printf("Saldo antes das operações:");
  mostrar_conta(231);

  if ((pilha1 = malloc(TAMANHO_PILHA)) == 0)
  {
    perror("Error na alocação da pilha.");
    exit(1);
  }

  if ((pilha2 = malloc(TAMANHO_PILHA)) == 0)
  {
    perror("Error na alocação da pilha.");
    exit(1);
  }

  // Inicia thread de deposito
  pid1 = clone(funcaoDeposito, pilha1 + TAMANHO_PILHA, CLONE_VM | sigchld);
  // Inicia thread de deposito
  pid2 = clone(funcaoDeposito, pilha2 + TAMANHO_PILHA, CLONE_VM | sigchld);

  // Aguarda o final da aoperação
  waitpid(pid1, 0, 0);
  waitpid(pid2, 0, 0);
}