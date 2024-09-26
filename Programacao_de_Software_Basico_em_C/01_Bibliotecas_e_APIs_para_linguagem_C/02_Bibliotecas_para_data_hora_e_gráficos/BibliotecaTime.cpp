#include <stdio.h>
#include <time.h>

int main(){
	time_t agora;
	time(&agora);
	
	printf("Hora atual: %s", ctime(&agora));
	return 0;
}
