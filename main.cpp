#include<stdio.h>//librerias necesarias para el juego
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

//DEFINICION DE TECLAS
#define RIGHT 77//M
#define LEFT 75//K
#define DOWN 80 //P
#define UP 72//H
#define ENTER 13
#define ESC 27
#define SPACE 2//ESPACIO ENTRE CUADROS

typedef struct
{
	char userName[20];
	int puntos;
}player;


#include"funciones.h"//forma de llamar los demas archivos que componen al juego
#include"pixelArt.h"
#include"score.h"
#include"salida.h"
#include"menuFn.h"
#include"ayuda.h"
#include"juegos.h"


int main()//cuerpo del archivo principal
{
	int op=0;//opcion necesaria 
	int x=3,y=5;//posicion de este menu
	char nomArch[20]="puntos.txt";
	player users[6];
	system("MODE 300,400");//Por lo que entiendo, esta línea cambia el tamaño del compilador
	srand(time(0));//semilla para aleatorios
	
	getch();
	PortadaPixelArt(pixelArt1,34,25,10,0);//pixelar que servira de portada
	gotoxy(200,4);
	getch();//esperar tecla
	
	do{//seguir pidiendo elegir una opcion a menos de que se elija la opcion de salir (4)
		presenta_menu(x,y);//menu de opciones
		op=scroll_menu(x,y,4);//crea el seleccionardor (las flechitas que siguen la opciones que deseas escoger) y la forma de elegir la opcion;
		system("cls");//limpia pantalla
		switch(op)//elige la opcion dependiendo del valor almacenado
		{
			case 1: mainjuego(); break;
			case 2: mainayudas();break;
			case 3:	readPlayers(nomArch,users);printPlayers(users);getch();break;
			case 4: mainsalidas();break;
		}
		getch();
	 }while(op!=4);
	return 0;
}
