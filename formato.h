#include<stdio.h>//librerias necesarias para el juego
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

void Portada(int posX,int posY,int ancho=20,int alto=40, int color);

void Portada(int posX,int posY,int ancho,int alto,int color)
{
	int i;
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),color);//color se declaro en la funcion de tablero con el numero 15(blanco)
	for(i=0;i<ancho;i++)//horizantoles
	{
		gotoxy(posX+i,posY);
		printf("%c",205);//--- 196
		gotoxy(posX+i,posY+alto);
		printf("%c",205);//=		
	}
	for(i=0;i<alto;i++)//verticales
	{
		gotoxy(posX,posY+i);
		printf("%c",186);//||
		gotoxy(posX+ancho,posY+i);
		printf("%c",186);//||		
		//Sleep(50);
	}
	
	gotoxy(posX,posY);//impresion de las esquinas 
	printf("%c",201);
	gotoxy(posX+ancho,posY);
	printf("%c",187);
	gotoxy(posX,posY+alto);
	printf("%c",200);
	gotoxy(posX+ancho,posY+alto);
	printf("%c",188); //217
	
}
