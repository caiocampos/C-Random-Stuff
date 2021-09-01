// PrimeiroPrograma.c - Isabel H. Manssour
// Um programa OpenGL simples que abre uma janela GLUT
// Este c�digo est� baseado no Simple.c, exemplo
// dispon�vel no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	//Limpa a janela de visualiza��o com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);
	//Executa os comandos OpenGL
	glFlush();
}
// Inicializa par�metros de rendering
void Inicializa (void)
{
	// Define a cor de fundo da janela de visualiza��o como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
// Programa Principal
int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutMainLoop();
}
