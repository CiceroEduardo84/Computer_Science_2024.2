#include <graphics.h>
#include <conio.h>

int main(){
	int gd = DETECT, gm;
	int x = 100, y = 200; //Posição inicial do circulo
	int radius = 30; //Raio do circulo
	int maxX;
	int step = 5; //Passo do movimento do circulo
	
	initgraph(&gd, &gm, NULL);
	maxX = getmaxx();
	
	while (!kbhit()) { //Executa até que uma tecla seja pressionada
		cleardevice(); //Limpa a tela
		setcolor(RED); //Define a cor do círculo para vermelho
		circle(x, y, radius); //Desenha o cículo n aposição atual
		
		//Atualiza a posição x do cículo
		x += step;
		
		//Inverte a direção quando atinge as bordas da janela
		if (x > maxX-radius || x < radius){
			step = -step;
		}
		
		delay(50); //Espera um pouco antes de continuar
	}

	getch(); //Espera que o usuario pressione a tecla
	closegraph();
	return 0;
}
