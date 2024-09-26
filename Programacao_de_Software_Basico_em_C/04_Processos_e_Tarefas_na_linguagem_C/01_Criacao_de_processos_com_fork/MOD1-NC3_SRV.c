#include <stdio.h> // Contém declarações usadas na maioria das entradas e saídas
#include <sys/types.h> // Contém definições de tipos de dados usados em chamadas do sistema
#include <sys/socket.h> // Inclui definições de estruturas necessárias para sockets
#include <netinet/in.h> // Contém constantes e estruturas necessárias para endereços de domínio de internet

// Função chamada quando uma chamada do sistema falha, exibindo uma mensagem de erro e abortando o programa
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256]; // Buffer onde o servidor lê caracteres da conexão socket
    struct sockaddr_in serv_addr, cli_addr; // Estrutura contendo um endereço de internet
    int n;

    // Verifica se o número da porta foi passado como argumento
    if (argc < 2) {
        fprintf(stderr,"ERRO, nenhuma porta fornecida\n");
        exit(1);
    }

    // Cria um novo socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERRO na abertura do socket ");

    // Inicializa serv_addr com zeros
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]); // Converte o número da porta de string para inteiro
    serv_addr.sin_family = AF_INET; // Define a família de endereços como AF_INET
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Define o endereço IP do servidor
    serv_addr.sin_port = htons(portno); // Converte o número da porta para a ordem de bytes da rede

    // Associa o socket a um endereço
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERRO na associacao ");

    // Escuta por conexões no socket
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Aceita uma conexão
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERRO no aceite ");

    // Inicializa o buffer e lê do socket
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) 
        error("ERRO lendo do socket ");
    printf("Aqui esta a mensagem: %s\n", buffer);

    // Escreve no socket
    n = write(newsockfd, "Eu obtive sua mensagem ", 18);
    if (n < 0) 
        error("ERRO escrevendo no socket ");

    return 0;
} 
