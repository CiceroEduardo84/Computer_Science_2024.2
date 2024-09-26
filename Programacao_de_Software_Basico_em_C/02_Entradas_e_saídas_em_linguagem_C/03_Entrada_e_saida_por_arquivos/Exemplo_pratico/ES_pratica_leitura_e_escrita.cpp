#include <stdio.h> // Biblioteca padr�o I/O

// Fun��o principal
int main() {
    FILE *fpTexto, *fpBinario; // Declara ponteiros para os arquivos de texto e bin�rios
    char nome[100]; // Declara um array de caracteres para armazenar o nome do participante
    int contador = 0; // Declara e inicializa uma vari�vel inteira para o contador de pessoas

    // Abertura dos arquivos
    fpTexto = fopen("participantes.txt", "a+");
    fpBinario = fopen("contador.bin", "rb+");

    if(fpBinario == NULL) { // Verifica se o arquivo bin�rio n�o existe
        // Se o arquivo bin�rio n�o existe, cria-o no modo de escrita e leitura("wb+")
        fpBinario = fopen("contador.bin", "wb+");
        fwrite(&contador, sizeof(int), 1, fpBinario); // Escreve o valor inicial do contador
    } else {
        // Se o arquivo bin�rio existir, l� o contador existente
        fread(&contador, sizeof(int), 1, fpBinario); // L� o valor do contador do arquivo
    }

    // Solicita ao usu�rio para digitar o nome do participante
    printf("Digite o nome do participante: ");
    scanf(" %[^\n]", nome); // L� o nome do participante, incluindo espa�os at� encontrar uma quebra de linha

    // Escreve o nome do participante no arquivo de texto
    fprintf(fpTexto, "%s\n", nome);

    // Incrementa o contador de participantes
    contador++;

    // Volta para o in�cio do arquivo bin�rio
    rewind(fpBinario);

    // Atualiza o contador no arquivo bin�rio
    fwrite(&contador, sizeof(int), 1, fpBinario);

    // Fechamento dos arquivos
    fclose(fpTexto);
    fclose(fpBinario);

    // Imprime o total de participantes registrados
    printf("Total de participantes registrados: %d\n", contador);

    // Retorna 0 para indicar que o programa encerrou de forma correta
    return 0;
}

