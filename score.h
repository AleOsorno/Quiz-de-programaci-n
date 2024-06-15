
void readPlayers(char nomArch[20], player users[6]);
void printPlayers(player users[6]);
void ordenaPlayers(char userName[20], int puntos, player users[6]);
void savePlayers(char nomArch[20],player users[6]);

void readPlayers(char nomArch[20],player users[6])
{
	FILE *arch=NULL;
	int i=0;
	arch=fopen(nomArch,"r");
	if(arch)
	{
		i=0;
		while(!feof(arch))
		{
			fscanf(arch,"%[^\t]",users[i].userName);
			fscanf(arch,"%d\n",&users[i].puntos);
			i++;			
		}
		fclose(arch);
	}
}
void printPlayers(player users[6])
{
	int i,j,k;
	PixelArt36(pixelArt8,31,21,60,1);
	PP2(20,10,30,15,11);
	gotoxy(27,12);
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	printf("Jugadores-Puntos");
	for(i=0,j=14,k=24;i<5;i++,j++,k++){
		gotoxy(27,j);
		printf("%s\t%d\n", users[i].userName,users[i].puntos);
	}
}
void ordenaPlayers(char userName[20], int puntos, player users[6])//burbuja
{
	int i, j,n=6;
	player aux;
	
	strcpy(users[5].userName,userName);
	users[5].puntos=puntos;
	
	for(i=0;i<n-1;i++){
		for(j=0; j < n-1; j++) {
        	if(users[j].puntos > users[j+1].puntos) 
			{
				aux = users[j];
	      		users[j] = users[j+1];
	      		users[j+1] = aux;	      			 	
			}//swap
		}//for j
	}//for i	
}
void savePlayers(char nomArch[20],player users[6])
{	
	FILE *arch=NULL;
	int i=0;
	arch=fopen(nomArch,"w");//reemplaza el earchivo o lo crea
	if(arch)
	{
		for(i=0;i<5;i++)
		{
			fprintf(arch,"%s\t",users[i].userName);
			fprintf(arch,"%d\n",users[i].puntos);
		}
		fclose(arch);
	}
}

