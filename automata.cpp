// automata.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <Windows.h>

int columna(char caracter)
{
    switch(caracter)
    {
        //caracteres del alfabeto
        case 'a': return 0;
        case 'b': return 1;
        case '0': return 2;
        case '1': return 3;
    }
}

int esPalabra(char *cadena)
{
    int estado = 0;
    static int automata[8][4] = {
		{1,7,7,7},{2,7,7,7},{3,5,4,4},{2,7,7,7},
		{7,5,4,4},{7,6,7,7},{7,5,7,7},{7,7,7,7}
	};

    for(int i = 0; cadena[i] != '\0'; i++)
        estado = automata[estado][columna(cadena[i])];

    if(estado == 5)  //5 es estado final.
        return 1;

    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char cadena[100]; //  100 = tamaño máximo de cadena que ingresa

	FILE *fIn = fopen("input.txt", "r");
	FILE *fOut = fopen("output.txt", "w+");

	while( fscanf(fIn, "%s", cadena) != EOF )
	{
		if( esPalabra(cadena) )
			fprintf(fOut, "%s\r\n", cadena);
	}

	fclose(fIn);
	fclose(fOut);

	return 0;
}

