#include <graphics.h> //Inclui a biblioteca gr�fica
//Graphics � usado para fins educacionais pois � ultrapassada

int main(){
	//Cria uma janela 800x800 pixels para renderiza��o gr�fica
	initwindows(800, 800);
	
	int left = 100, top = 100, right = 200, bottom = 200;
	int x = 300, y = 150, radius = 50;
	
	//Desenha um ret�ngulo
	rectangle(left, top, right, bottom);
	//Desenha um circulo
	circle(x,y,radius);
	//Desenha um ret�ngulo preenchido, deslocado 300 pixels � direita
	bar(left + 300, top, right + 300, bottom);
	//Desenha uma linha horizontal estendendo-se do ret�ngulo
	line(left - 10, top + 150, left + 410, top + 150);
	//Desenha uma elipse completa com raios horizontais e vreticais
	ellipse(x, y + 200, 0, 360, 100, 50);
	//Exibe texto nas coordenadas definidas
	outtextxy(left + 100, top + 325, "Meu programa grafico");
	
	//Mentem a janela aberta at� a tecla ser pressionada
	getch();
	return 0;
}
