#include <stdio.h>
#include <time.h>

int main(){
	time_t agora;
	struct tm*infoTempo;
	char buffer[80];
	
	time(&agora);
	infoTempo = localtime(&agora);
	strftime(buffer, 80, "Data e Hora: %d-%m-%Y %H:%M:%S", infoTempo);
	printf("%s\n", buffer);
	return 0;
	}
