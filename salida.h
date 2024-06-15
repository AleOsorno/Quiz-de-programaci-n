#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
void mainsalidas(){
	FILE *ftp;
	char caracter;
	ftp=fopen("tSalida.txt","r");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	if(ftp != NULL ){
		do{
		    caracter=getc(ftp);
		    putchar(toupper(caracter));
		    Sleep(5);
	    }while(!feof(ftp)); //Antes era un salto de línea la condición
	    fclose(ftp);
	    Finish(final,27,44,60,24);
	}
	else  printf("NO se existe el archivo");
	getch();
}
