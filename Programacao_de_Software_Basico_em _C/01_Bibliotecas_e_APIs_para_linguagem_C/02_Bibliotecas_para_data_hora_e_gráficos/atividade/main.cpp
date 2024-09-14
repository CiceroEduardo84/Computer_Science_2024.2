#include <conio.h>
#include <graphics.h>
#include <stdlib.h> // Para rand() e srand()
#include <time.h>   // Para time()

int main() {
    int gd = DETECT, gm;
    int x = 300, y = 200; // Posi��o inicial do c�rculo
    int radius = 30;      // Raio do c�rculo
    int maxX, maxY;
    int dx = 4, dy = 4;   // Componentes de velocidade iniciais

    srand(time(NULL)); // Inicializa o gerador de n�meros aleat�rios

    initgraph(&gd, &gm, NULL); // Inicializa o sistema gr�fico
    maxX = getmaxx(); // Pega a largura m�xima da tela
    maxY = getmaxy(); // Pega a altura m�xima da tela

    while (!kbhit()) { // Executa at� que uma tecla seja pressionada
        cleardevice(); // Limpa a tela
        setcolor(RED); // Define a cor do c�rculo para vermelho
        circle(x, y, radius); // Desenha o c�rculo na posi��o atual

        // Atualiza a posi��o do c�rculo
        x += dx;
        y += dy;

        // Verifica se o c�rculo atinge as bordas e ajusta a dire��o
        if (x > maxX - radius || x < radius) {
            dx = -dx + (rand() % 4); // Inverte e ajusta aleatoriamente a dire��o horizontal
        }
        if (y > maxY - radius || y < radius) {
            dy = -dy + (rand() % 4); // Inverte e ajusta aleatoriamente a dire��o vertical
        }

        delay(50); // Espera um pouco antes de continuar
    }

    getch(); // Espera que o usu�rio pressione uma tecla
    closegraph(); // Fecha o sistema gr�fico
    return 0;
}

