#include <conio.h>  // Inclui a biblioteca conio.h que contém funções específicas do console
#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída
#include <ctype.h>  // Inclui a biblioteca para funções de teste e mapeamento de caracteres

int main(void) {
    char caractere;  // Declara uma variável do tipo char para armazenar cada caractere lido

    // Solicita ao usuário que digite um texto e informa como sair do programa
    printf("Entre com um texto (Digite ponto (.) para sair do programa): \n");
    do {
        caractere = getch();  // Lê um caractere do teclado sem ecoar na tela
        
        // Verifica se o caractere é uma letra minúscula
        if (islower(caractere)) {
            caractere = toupper(caractere);  // Converte para maiúscula se for minúscula
        }
        else {
            caractere = tolower(caractere);  // Converte para minúscula se não for minúscula
        }
        
        putchar(caractere);  // Exibe o caractere convertido no console
    } 
    while (caractere != '.');  // Repete o loop até que o caractere '.' seja digitado
}
