// Um programa OpenGL que exemplifica a visualiza��o
// de objetos 3D com a inser��o de uma fonte de luz.
// Este c�digo est� baseado nos exemplos dispon�veis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>


GLfloat angle, fAspect;
// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	// Desenha um cubo
	glBegin(GL_QUADS);
		// Face posterior
		glNormal3f(0.0, 0.0, 1.0);
		// Normal da face
		glVertex3f(40.0, 40.0, 40.0);
		glVertex3f(-40.0, 40.0, 40.0);
		glVertex3f(-40.0,-40.0, 40.0);
		glVertex3f(40.0,-40.0, 40.0);
	glEnd();
	glBegin(GL_QUADS);
		// Face frontal
		glNormal3f(0.0, 0.0,-1.0);
		// Normal da face
		glVertex3f(40.0, 40.0,-40.0);
		glVertex3f(40.0,-40.0,-40.0);
		glVertex3f(-40.0,-40.0,-40.0);
		glVertex3f(-40.0, 40.0,-40.0);
	glEnd();
	glBegin(GL_QUADS);
		// Face lateral esquerda
		glNormal3f(-1.0, 0.0, 0.0);
		// Normal da face
		glVertex3f(-40.0, 40.0, 40.0);
		glVertex3f(-40.0, 40.0,-40.0);
		glVertex3f(-40.0,-40.0,-40.0);
		glVertex3f(-40.0,-40.0, 40.0);
	glEnd();
	glBegin(GL_QUADS);
		// Face lateral direita
		glNormal3f(1.0, 0.0, 0.0);
		// Normal da face
		glVertex3f(40.0, 40.0, 40.0);
		glVertex3f(40.0,-40.0, 40.0);
		glVertex3f(40.0,-40.0,-40.0);
		glVertex3f(40.0, 40.0,-40.0);
	glEnd();
	glBegin(GL_QUADS);
		// Face superior
		glNormal3f(0.0, 1.0, 0.0);
		// Normal da face
		glVertex3f(-40.0, 40.0,-40.0);
		glVertex3f(-40.0, 40.0, 40.0);
		glVertex3f(40.0, 40.0, 40.0);
		glVertex3f(40.0, 40.0,-40.0);
	glEnd();
	glBegin(GL_QUADS);
		// Face inferior
		glNormal3f(0.0,-1.0, 0.0);
		// Normal da face
		glVertex3f(-40.0,-40.0,-40.0);
		glVertex3f(40.0,-40.0,-40.0);
		glVertex3f(40.0,-40.0, 40.0);
		glVertex3f(-40.0,-40.0, 40.0);
	glEnd();
	glutSwapBuffers();
}
// Inicializa par�metros de rendering
void Inicializa (void)
{
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0}; // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0}; // "brilho"
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};
	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;
	// Especifica que a cor de fundo da janela ser� preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);
	// Define a reflet�ncia do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita a luz de n�mero 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	angle=45;
}
// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();
	// Especifica a proje��o perspectiva
	gluPerspective(angle,fAspect,0.4,500);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posi��o do observador e do alvo
	gluLookAt(0,80,200, 0,0,0, 0,1,0);
}
// Fun��o callback chamada quando o tamanho da janela � alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;
	EspecificaParametrosVisualizacao();
}
// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) { // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}
// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,350);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}
