#include <stdio.h>
#include <stdlib.h>

int main(){
	int count = 1, num = 2, i;
	int N =100; //Deseja encontrar o 100° primo
	int isPrime;
	
	while (count < N){
		isPrime = 1; //Asume que o número é primo
		for(i=0;i<= num; i++){
			if(num % i == 0){
				isPrime = 0; //O numero não é primo
				break;
			}
		}
		
		if(isPrime){
			count++;
			if(count == N){
				printf("%d° númeor primo é: ", N, num);
			}
		}
		num++;
	}
	return 0;
}
