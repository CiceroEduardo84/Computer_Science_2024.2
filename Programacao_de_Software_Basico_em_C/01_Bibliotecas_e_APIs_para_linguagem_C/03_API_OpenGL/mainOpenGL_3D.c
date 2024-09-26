#include <glut.h>

//Função chamada para desenhar
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//posicionar a câmera
	gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	//Rotação simples ao redor 	do aixo y
	static float angle = 0.0;
	glRotatef(angle, 0.0, 1.0, 0.0);
	
	//Desenhar cubo
	glutSolidCube(1.5);
	
	//Atualiza o angulo
	angle += 0.05;
	
	if (angle > 360){
		glutSwapBuffers();
	}
}

//Inicializa parâmetros de rendering
void initRendering(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
	//Definindo a cor de fundo
	glClearColor(0.1,0.1,0.1,0.1);
	
	//Configuração de iluminação
	GLfloat lightPos[] = {0.1,0.1,0.1,0.0};
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

//Chamada quando a janela e redimensionada
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
	//Incializa GLUT e processa os argumentos do usuario
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	//configura o tamanho e a posição inicial da janela
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	
	//Cria a janela
	glutCreateWindow("Exemplo de cubo 3D OpenGL");
	
	//Inicializa alguns parametro de redering
	initRendering();
	
	//configura as funções de callback
	glutDisplayFunc(display);
	glutIdleFunc(display);
    glutReshapeFunc(handleResize);

    // Começa o loop principal
    glutMainLoop();
    return 0;
}
