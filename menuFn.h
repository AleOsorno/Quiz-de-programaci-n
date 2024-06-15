
void presenta_menu(int posX, int posY);
int scroll_menu(int posX, int posY, int cantOpc);

void presenta_menu(int posX, int posY)//funcion que presenta al menu
{
 	 system("cls");//limpiar pantalla
 	 SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);//forma de hacer que el texto se muestre con letras blancas, el cambio de numero es para cambio de color de texto
	 gotoxy(posX,posY);printf("1. APLICACION");//impresion del texto en los campos de x y de y
	 gotoxy(posX,++posY);printf("2. AYUDA");
	 gotoxy(posX,++posY);printf("3. SCORE");
	 gotoxy(posX,++posY);printf("4. SALIR");	 	 
}

int scroll_menu(int posX, int posY, int cantOpc)
{
 char tecla='\0';
 int op=1,y=posY;
 
 posX=posX-2;//el texto del menu se imprime en la posicion de x normal, si le restamos -2 lo siguiente que se imprima sera antes del texto
 SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);//las impresiones siguientes seran en color verde 	
 gotoxy(posX,posY);//forma de mandar la impresion antes del menu
 printf(">>");//impresion del "seleccionador"
 do{
 	tecla=getch();//esperar una tecla, ya sea arriba o abajo 	
 	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0);//impresion en color negro
 	gotoxy(posX,y);//en el mismo lugar del anterior seleccionador
	printf(">>");//para borrar el anterior seleccionador
 	if(tecla==80 && op<cantOpc)// 'P' 80 ABAJO
 	{ 	
		y++;//cambio de coordenadas para mover la posicion del seleccionador
		op++;
 	}
 	if(tecla==72 && op>1)//'H' ARRIBA
 	{ 	
		y--;
		op--;
 	}
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);//se vuelve a repetir el ciclo
	gotoxy(posX,y);
	printf(">>");
	
	if(op==1){
		PixelArt31(pixelArt6,37,29,20,1);
	}
	if(op==2){
		PixelArt32(pixelArt3,37,29,20,1);
	}
	if(op==3){
		PixelArt33(pixelArt4,37,29,20,1);
	}
	if(op==4){
		PixelArt34(pixelArt5,37,29,20,1);
	}
	
 }while(tecla!=27 && tecla!=13);//ESC 27   ENTER 13
 return (op);
}

