void gotoxy(int x,int y);
//
void gotoxy(int x,int y){//sirve para los PixelArt o para posicionar una impresion  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
