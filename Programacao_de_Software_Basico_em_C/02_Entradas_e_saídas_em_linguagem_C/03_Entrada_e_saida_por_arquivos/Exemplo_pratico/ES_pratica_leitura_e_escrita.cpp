#include <stdio.h> // Biblioteca padrão I/O

// Função principal
int main() {
    FILE *fpTexto, *fpBinario; // Declara ponteiros para os arquivos de texto e binários
    char nome[100]; // Declara um array de caracteres para armazenar o nome do participante
    int contador = 0; // Declara e inicializa uma variável inteira para o contador de pessoas

    // Abertura dos arquivos
    fpTexto = fopen("participantes.txt", "a+");
    fpBinario = fopen("contador.bin", "rb+");

    if(fpBinario == NULL) { // Verifica se o arquivo binário não existe
        // Se o arquivo binário não existe, cria-o no modo de escrita e leitura("wb+")
        fpBinario = fopen("contador.bin", "wb+");
        fwrite(&contador, sizeof(int), 1, fpBinario); // Escreve o valor inicial do contador
    } else {
        // Se o arquivo binário existir, lê o contador existente
        fread(&contador, sizeof(int), 1, fpBinario); // Lê o valor do contador do arquivo
    }

    // Solicita ao usuário para digitar o nome do participante
    printf("Digite o nome do participante: ");
    scanf(" %[^\n]", nome); // Lê o nome do participante, incluindo espaços até encontrar uma quebra de linha

    // Escreve o nome do participante no arquivo de texto
    fprintf(fpTexto, "%s\n", nome);

    // Incrementa o contador de participantes
    contador++;

    // Volta para o início do arquivo binário
    rewind(fpBinario);

    // Atualiza o contador no arquivo binário
    fwrite(&contador, sizeof(int), 1, fpBinario);

    // Fechamento dos arquivos
    fclose(fpTexto);
    fclose(fpBinario);

    // Imprime o total de participantes registrados
    printf("Total de participantes registrados: %d\n", contador);

    // Retorna 0 para indicar que o programa encerrou de forma correta
    return 0;
}

