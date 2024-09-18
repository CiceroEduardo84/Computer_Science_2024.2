#include <stdio.h>
#include <string.h>

int main(void) {
    char string[5];
    printf("Digite um texto: ");
    // Temos a função gets()para a leitura de strings, mas ela é conhecida por seus problemas de segurança, como buffer overflow.
	// Uma alternativa segura é usar fgets()
    fgets(string, sizeof(string), stdin);
    printf("\nO comprimento eh %d\n", strlen(string));
}
