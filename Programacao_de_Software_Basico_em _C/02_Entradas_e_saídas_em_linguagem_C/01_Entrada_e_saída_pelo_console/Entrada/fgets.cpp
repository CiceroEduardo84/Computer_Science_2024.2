#include <stdio.h>
#include <string.h>

int main(void) {
    char string[5];
    printf("Digite um texto: ");
    // Temos a fun��o gets()para a leitura de strings, mas ela � conhecida por seus problemas de seguran�a, como buffer overflow.
	// Uma alternativa segura � usar fgets()
    fgets(string, sizeof(string), stdin);
    printf("\nO comprimento eh %d\n", strlen(string));
}
