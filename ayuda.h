#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
void mainayudas(){
	FILE *ftp;
	char caracter;
	ftp=fopen("tAyuda.txt","r");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	if(ftp != NULL ){
		do{
		    caracter=getc(ftp);
		    putchar(toupper(caracter));
		    Sleep(5);
	    }while(!feof(ftp)); //Antes era un salto de línea la condición
	    fclose(ftp);
	    Question(help,22,22,10,20);
	    Question(help,22,22,50,20);
	    Question(help,22,22,90,20);
	    Question(help,22,22,130,20);
	}
	else  printf("NO se existe el archivo");
	getch();
}
