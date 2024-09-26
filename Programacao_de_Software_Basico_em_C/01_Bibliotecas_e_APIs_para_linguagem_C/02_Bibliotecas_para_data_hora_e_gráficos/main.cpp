#include <graphics.h>
#include <conio.h>

int main(){
	int gd = DETECT, gm;
	int x = 100, y = 200; //Posi��o inicial do circulo
	int radius = 30; //Raio do circulo
	int maxX;
	int step = 5; //Passo do movimento do circulo
	
	initgraph(&gd, &gm, NULL);
	maxX = getmaxx();
	
	while (!kbhit()) { //Executa at� que uma tecla seja pressionada
		cleardevice(); //Limpa a tela
		setcolor(RED); //Define a cor do c�rculo para vermelho
		circle(x, y, radius); //Desenha o c�culo n aposi��o atual
		
		//Atualiza a posi��o x do c�culo
		x += step;
		
		//Inverte a dire��o quando atinge as bordas da janela
		if (x > maxX-radius || x < radius){
			step = -step;
		}
		
		delay(50); //Espera um pouco antes de continuar
	}

	getch(); //Espera que o usuario pressione a tecla
	closegraph();
	return 0;
}
