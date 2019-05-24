#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "convolucion.h"
int main(int argc, char *argv[])
{
	char h[1000], x[1000];
	int posH, posX;
	printf("Introduzca h[n] (una cadena de numeros separada por comas): \n");
	fgets(h, 1000, stdin);
	fflush(stdin);
	printf("Introduzca x[n] (una cadena de numeros separada por comas): \n");
	fgets(x, 1000, stdin);
	fflush(stdin);
	printf("Introduzca No para h(n): \n");
	scanf("%d", &posH);
	fflush(stdin);
	printf("Introduzca No para x(n): \n");
	scanf("%d", &posX);
	fflush(stdin);

	int datosauxH[500], datosauxX[500], *datosh, *datosx;
	int lenH[1], lenX[1], maxTam;
	arrayToInt(h, lenH, datosauxH);
	//imprimir(datosauxH,lenH[0]);
	arrayToInt(x, lenX, datosauxX);
	//imprimir(datosauxX,lenX[0]);
	maxTam = lenH[0] > lenX[0] ? lenH[0] * 2 : lenX[0] * 2;
	datosh = malloc(sizeof(int) * (maxTam + 1));
	datosx = malloc(sizeof(int) * (maxTam + 1));
	inicializar(datosh, datosx, maxTam + 1);
	copiar(datosauxH, datosh, (maxTam / 2) - posH, lenH[0]);
	copiar(datosauxX, datosx, (maxTam / 2) - posX, lenX[0]);

	int res[1];
	/* Empieza la convolucion  */

	invertir(datosh, maxTam);

	int *negative = malloc(sizeof(int) * (maxTam + 1));

	int *positive = malloc(sizeof(int) * (maxTam + 1));
	inicializar(positive, negative, maxTam + 1);
	copiar2(datosh, negative, maxTam + 1);
	copiar2(datosh, positive, maxTam + 1);

	multiplicar(datosh, datosx, res, maxTam + 1);
	printf("y(%d) = %d\n\n", 0, res[0]);

	for (int i = 1; i <= (lenH[0] * 2 - posH); i++)
	{
		recorrerIzquierda(positive, maxTam + 1);

		recorrerDerecha(negative, maxTam + 1);

		multiplicar(positive, datosx, res, maxTam + 1);
		printf("y(%d) = %d // ", i, res[0]);
		multiplicar(negative, datosx, res, maxTam + 1);
		printf("y(-%d) = %d\n\n", i, res[0]);
	}
	free(positive);
	free(negative);
	free(datosh);
	free(datosx);
	printf("Presiona cualquier tecla para salir\n");
	getchar();
	return 0;
}
