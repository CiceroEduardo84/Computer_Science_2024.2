#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
	int pid; /* process ID */
	
	//O switch é usado para lidar com valor de retorno da chamada fork()
	switch (pid = fork()){
		case 0: /* um fork retornara 0 para o processo filho */
			//se o valor do returno for 0, estamos no processo filho*/
			printf("Eu sou o processo filho: pid=%d\n", getpid()); //getpid() retorna o ID do processo atual
			break;
		default: /* um fork retorn o pid do filho para o pai*/
			//SE o valor de retorno for positivo, estamos no processo pai e o valor é o PID do processo atual
			printf("Eu sou o processo pai: pid=%d, chilf pid=%d\n ", getpid(), pid);//getpid() retorna o ID do processo atual, pid é o ID do processo filho
			break;
		case -1: /*algo deu errado*/
			//Se o valor de retorno for -1, ocorreu um erro na chamada fork()
			perror("fork");//Perror() exibe a mensagem de erro
			exit(1);//Enecerra o programa com código de erro 1
	}
	exit(0);//Encerra o programa com sucesso	
}
