#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
/*declaracion de funciones*/
void menu();
int tam(char *salida);
/*fin de la declaracion*/

#define MAX_TAM 24

char* ruta;
int tVec=-1;

int main(){
	puts("bienvenido al evaluador de tiempos, por Marcos Mayen");
	int salida;
	do{
		menu();
		scanf("%d",&salida);
		switch (salida)
		{
			case 1:
				puts("caso 1 accedido, carga de datos");	
				char guia[50]="/home/marcosmayen/Desktop/";
				puts("por favor ingrese el nombre del archivo(este se debe encontrar en el escritorio)");
				char arch[MAX_TAM];
				scanf("%s",arch);
				strcat(guia,arch);
				ruta=guia;
				tVec=tam(guia);
				
				break;
			case 2:
				if(tVec==-1)
				{
					puts("_____________________________________");
					puts("|ahun no has cargado nada al archivo,|\n|esta funcion no puede ser accedida|");
					puts("_____________________________________");
				}
				else{
					puts("caso 2 accedido, de uso");
					printf("%d",tVec);

				}
				break;
			case 3:
				puts("gracias por usar el programa\n");
				break;
			default :
				puts("Esta funcion no esta disponible\n\n");
		}
	}while(salida!=3);
	return 0;
}


void menu()
{	puts("---------------------------------------------------------------");
	puts("|por favor seleccione una de las siguientes opciones:         |");	
	puts("|1.-Cargar un nuevo archivo(este debe estar en el escritorio) |");
	puts("|2.-mostrar tiempo de ejecucion                               |");
	puts("|3.-salir_____________________________________________________|\n");
}



/*determina el tam. de la cadena y si existe*/
int tam(char *salida)
{
	int c,n=0;
	FILE* pf;
	if((pf = fopen(salida,"rt"))==NULL)
	{
		puts("Error, el archivo que busca no parece existir");
		return -1;
	}
	while((c=getc(pf))!=EOF)
	{
		if(c == '\n')
		{
			printf("\n");
		}
		else{
			putchar(c);
		}
		n++;
	}	
	char arreglo[n+1];
	n=0;
	while((c=getc(pf)!=EOF))
	{
		arreglo[n]=c;
		n++;
	}
	fclose(pf);
	printf("%c",arreglo[5]);
	return n;
}



