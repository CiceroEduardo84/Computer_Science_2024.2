#include <stdio.h>
#include <unisted.h>

int contador;

void function_A(void)
{
  while (1)
  { // Loop infinito.
    printf("Para a função A contador = %d.\n", contador);
    usleep(3000000);
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
  int pid;
  contador = 0; // inicializa o contador.
  pid = fork(); // Processo se divide em dois
  if (pid == 0)
    function_A(); // Se PID igual a zero executa o código da função A
  else
    function_B(); // Se PID diferente de zero executa  o código da função B
}