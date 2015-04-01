#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
/*declaracion de funciones*/
void menu();
/*fin de la declaracion*/

char* ruta;



int main()
{
	puts("bienvenido al evaluador de tiempos, por Marcos Mayen");
	puts("por favor, seleccione un archivo(este debe estar en su escritorio)");
	char* texto="/home/marcosmayen/Desktop/";
	char* cat;
	scanf("%s",cat);
	strncat(texto,cat);
	int ver=tam(texto);
	int opcion=0;
	int salida;
	do{
		if(ver==-1)
		{
			puts("el archivo no existe, por favor coloque uno valido");
			texto="/home/marcosmayen/Desktop/";
			scanf("%s",cat);
			scanf("%s",texto);
			ver=tam(texto);
		}else{
			menu();
			scanf("%d",&salida);
			switch (salida)
			{
				case 0:
					ruta ="/home/marcosmayen/Desktop/";
					scanf("coloca el nombre del archivo: \n");				
					tam(ruta);
					break;
				case 1:
					break; 
				case 2:
					break;
				case 3:
					puts("gracias por usar el programa");
					break;
				default :
					puts("Esta funcion no esta disponible");

			}
		}
	}while(salida != 3 );	
	return 0;
}


void menu()
{
	puts("por favor seleccione una de las siguientes opciones:\n");
	puts("0.-cargar el archivo");		
	puts("1.-Cargar un nuevo archivo(este debe estar en el escritorio)\n");
	puts("2.-mostrar archivo cargado:\n");
	puts("3.-mostrar tiempo de ejecucion\n");
	puts("por favor seleccione una de las siguientes opciones:\n");
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
			n++;printf("\n");
		}
		else
			putchar(c);
	}
	printf("total de lineas =%d \n\n",n);
	fclose(pf);
	return n;
}




