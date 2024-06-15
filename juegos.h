//TABLERO

#include<stdio.h>//librerias necesarias para el juego
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
//DEFINICION DE TECLAS
#define RIGHT 77//M

void cuadro(int posX,int posY,int ancho,int alto, int color);
void tablero(int posX,int posY,int ancho, int alto,int rens, int cols, int infoTabla[4][4]);
void moverCuadro(int posX, int posY, int ancho, int alto, int ren, int col, int infoTabla[4][4], int objetivo[4][4],char username[20]);
void asignaCarta(int infoTabla[4][4]);
int validaObjetivo(int infoTabla[4][4],int objetivo[4][4]);//es int por que retorna que llego al objetivo con 1 o 0

void mainjuego()
{
	int ren=4, col=4, ancho=8, alto=8;
	int posX=5, posY=5;
	int infoTabla[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,0,15}};
	int objetivo[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};//ordenar todos
	char username[20]="";
	
	system("MODE 120,60");
	srand(time(0));
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	PixelArt35(pixelArt7,34,25,38,1);
	gotoxy(15,25);
	printf("Cual es tu nombre?\n");
	gotoxy(15,27);
	scanf("%s",username);
	system("CLS");
	
	mainPixelArt(pixelArt2,27,25,70,4);//se llama al pixelArt necesario para resolver al rompecabezas
	asignaCarta(infoTabla);//asignar un numero no repetido al arreglo que se mostrara en las cartas
	tablero(posX,posY,ancho,alto,ren,col,infoTabla);//crea el tablero y su formato
	moverCuadro(posX, posY, ancho, alto, ren, col, infoTabla,objetivo,username);//mover cuadro al presionar alguna tecla
	getch();
		
}

void cuadro(int posX,int posY,int ancho,int alto,int color)
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

void tablero(int posX,int posY,int ancho, int alto,int rens, int cols, int infoTabla[4][4])
{
	int x, y, i,j, color=15;
	for(y=posY,i=0;i<rens;i++,y=y+alto+SPACE)//renglones
		for(x=posX,j=0;j<cols;j++,x=x+ancho+SPACE)//columnas
		{
			selecPixelArt(infoTabla[i][j], rens, cols, x, y);
			cuadro(x,y,ancho,alto,15);
			gotoxy(x+(ancho/2),y+(alto/2)+1);
			//printf("%d", infoTabla[i][j]);
		}
}

void moverCuadro(int posX, int posY, int ancho, int alto, int ren, int col, int infoTabla[4][4],int objetivo[4][4],char username[20])//agregamos infotabla
{
	int x=posX, y=posY, i=0, j=0, temp=0,piezasOk=0,movs=0;
	char tecla=0;
	char nomArch[20]="puntos.txt";
	player users[6];
	gotoxy(80,32);
	printf("%s",username);
	cuadro(x,y,ancho,alto,2); //2 - color verde (cuadro de la esq sup izq)-sera el cuadro que seleccionamos
	
	do{
		tecla = getch();
		//Después de presionar la tecla se reajusta el color
		cuadro(x,y,ancho,alto,15); //2 - color blanco (se deselecciona el cuadro en el que estabamos)
		
		switch(tecla){
			case 72://Arriba
				if(i > 0){
					i--;
					y=y-alto-SPACE;
				}
				break;
			case 80: //Abajo - 80
				if(i < (ren-1)){
					i++;
					y=y+alto+SPACE;
				}
				else if(i==4){
					i=0;
				}
				break;
			case 77:
				if(j < (col-1)){//derecha
					j++;
					x=x+ancho+SPACE;
				}
				else if(j==4){
					j=0;
				}
				break;
			case 75:
				if(j > 0){//izquierda
					j--;
					x=x-ancho-SPACE;	
				}
				break;
			case ENTER://13-Seleccion de targetas
				cuadro(x,y,ancho,alto,14);//si se presiona enter el cuadro cambiara a amarillo
				//Sleep(100);
				if(j>0 && infoTabla[i][j-1]==0){//0 a la izquierda
					//intercambio
					temp=infoTabla[i][j-1];
					infoTabla[i][j-1]=infoTabla[i][j];
					infoTabla[i][j]=temp;
					//imprimir cambio
					selecPixelArt(infoTabla[i][j], ren, col, x, y);
					gotoxy(x+(ancho/2),y+(alto/2)+1);
					printf("%d ", infoTabla[i][j]);
					
					selecPixelArt(infoTabla[i][j-1], ren, col, (x-ancho-SPACE), y);
					cuadro((x-ancho-SPACE),y,ancho,alto,15);
					gotoxy((x-ancho-SPACE)+(ancho/2),y+(alto/2)+1);
					printf("%d ", infoTabla[i][j-1]);
					piezasOk=validaObjetivo(infoTabla,objetivo);
					movs++;
				}
				if(j<3 && infoTabla[i][j+1]==0){//0 a la derecha
					temp=infoTabla[i][j+1];//se guarda el 0 en temp
					infoTabla[i][j+1]=infoTabla[i][j];//se guarda el numero de nuestra primer posicion en el primer en la posicion en donde se encontraba el 0 
					infoTabla[i][j]=temp;//se guarda el 0 en nuestra primer posicion
					
					selecPixelArt(infoTabla[i][j], ren, col, x, y);
					gotoxy(x+(ancho/2),y+(alto/2)+1);//se hace la impresion correspondiente
					printf("%d ",infoTabla[i][j]);
					
					selecPixelArt(infoTabla[i][j+1], ren, col, (x+ancho+SPACE), y);
					cuadro((x+ancho+SPACE),y,ancho,alto,15);
					gotoxy((x+ancho+SPACE)+(ancho/2),y+(alto/2)+1);
					printf("%d ",infoTabla[i][j+1]);
					piezasOk=validaObjetivo(infoTabla,objetivo);
					movs++;
				}
				if(i<3 && infoTabla[i+1][j]==0){//0 Abajo
					temp=infoTabla[i+1][j];
					infoTabla[i+1][j]=infoTabla[i][j];
					infoTabla[i][j]=temp;
					
					selecPixelArt(infoTabla[i][j], ren, col, x, y);
					gotoxy(x+(ancho/2),y+(alto/2)+1);
					printf("%d ", infoTabla[i][j]);
					
					selecPixelArt(infoTabla[i+1][j], ren, col, x, (y+alto+SPACE));
					cuadro(x,(y+alto+SPACE),ancho,alto,15);
					gotoxy(x+(ancho/2),(y+alto+SPACE)+(alto/2)+1);
					printf("%d ", infoTabla[i+1][j]);
					piezasOk=validaObjetivo(infoTabla,objetivo);
					movs++;
				}
				if(i>0 && infoTabla[i-1][j]==0){//0 Arriba
					temp=infoTabla[i-1][j];
					infoTabla[i-1][j]=infoTabla[i][j];
					infoTabla[i][j]=temp;
					
					selecPixelArt(infoTabla[i][j], ren, col, x, y);
					gotoxy(x+(ancho/2),y+(alto/2)+1);
					printf("%d ", infoTabla[i][j]);
				
					selecPixelArt(infoTabla[i-1][j], ren, col, x, (y-alto-SPACE));
					cuadro(x,(y-alto-SPACE),ancho,alto,15);
					gotoxy(x+(ancho/2),(y-alto-SPACE)+(alto/2)+1);
					printf("%d ", infoTabla[i-1][j]);
					piezasOk=validaObjetivo(infoTabla,objetivo);
					movs++;
				}
				if(piezasOk>=10){
					gotoxy(1,1);
					printf("PiezasOk:%d",piezasOk);
				}else{
					gotoxy(1,1);
					printf("PiezasOk:0%d",piezasOk);
				}
				if(movs>=10){
					gotoxy(15,1);
					printf("Movs:%d",movs);
				}else{
					gotoxy(15,1);
					printf("Movs:0%d",movs);
				}
				break;
		}
		cuadro(x,y,ancho,alto,2); //2 - color verde (se selecciona el nuevo marco de acuerdo a los parametros)
	}while(tecla != ESC && piezasOk<16);//ASCII 27
	if(piezasOk==16){
		gotoxy(80,34);
		printf("Haz ganado");
		gotoxy(80,35);
		printf("Moviste las piezas un total de: %d",movs);
		readPlayers(nomArch, users);
		ordenaPlayers(username,movs,users);
		savePlayers(nomArch,users);
		getch();
	}
}

void asignaCarta(int infoTabla[4][4]){
	int i, j, num=0, check[16]={0};
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			do{
				num = rand()%16; //0-15 num
			}while(check[num]==1);
			check[num] = 1; //Se van asignando numeros conforme se cumple la condicion del while
			infoTabla[i][j] = num;
		}
	}
}

int validaObjetivo(int infoTabla[4][4],int objetivo[4][4]){
	int i,j;
	int piezas=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(infoTabla[i][j]==objetivo[i][j]){
				piezas++;
			}
		}
	}
	return piezas;
}
