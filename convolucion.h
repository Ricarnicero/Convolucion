
#ifndef _H_CONVOLUCION
#define _H_CONVOLUCION
void arrayToInt(char *cadena, int *tam, int *datos);
void inicializar(int *h, int *x, int maxTam);
void inicializar2(int *h, int maxTam);
void imprimir(int *nums, int tam);
void copiar(int *, int *, int, int);
void copiar2(int *, int *, int);
void invertir(int *, int);
void recorrerDerecha(int *, int);
void recorrerIzquierda(int *, int);
void multiplicar(int *, int *, int *, int);

void imprimir(int *nums, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return;
}

void arrayToInt(char *cadena, int *tam, int *datos)
{
	int len = 0;
	const char s[2] = ",";
	char *token;
	token = strtok(cadena, s);
	while (token != NULL)
	{
		datos[len] = atoi(token);
		len += 1;
		token = strtok(NULL, s);
	}
	tam[0] = len;
	return;
}

void inicializar(int *h, int *x, int maxTam)
{
	for (int i = 0; i < maxTam; i++)
	{
		h[i] = 0;
		x[i] = 0;
	}
	return;
}
void inicializar2(int *h, int maxTam)
{
	for (int i = 0; i < maxTam; i++)
	{
		h[i] = 0;
	}
	return;
}

void copiar(int *datos, int *plantilla, int inicio, int len)
{
	int aux = 0;
	for (int i = inicio; i < inicio + len; i++, aux++)
	{
		plantilla[i] = datos[aux];
	}
}

void copiar2(int *datos, int *plantilla, int len)
{
	for (int i = 0; i < len; i++)
	{
		plantilla[i] = datos[i];
	}
}

void invertir(int *datos, int tam)
{
	int temp;
	for (int i = 0; i < tam / 2; i++)
	{
		temp = datos[i];
		datos[i] = datos[tam - i];
		datos[tam - i] = temp;
	}
	return;
}

void recorrerDerecha(int *datos, int tam)
{
	int *datosAux = (int *)malloc(sizeof(int) * (tam));
	inicializar2(datosAux, tam);

	for (int i = tam - 1; i >= 0; i--)
	{
		datosAux[i] = datos[i + 1];
	}
	for (int i = 0; i < tam; i++)
	{
		datos[i] = datosAux[i];
	}
	free(datosAux);
	return;
}

void recorrerIzquierda(int *datos, int tam)
{
	int *datosAux = (int *)malloc(sizeof(int) * (tam));
	inicializar2(datosAux, tam);

	for (int i = 1; i < tam; i++)
	{
		datosAux[i] = datos[i - 1];
	}
	for (int i = 0; i < tam; i++)
	{
		datos[i] = datosAux[i];
	}
	free(datosAux);
	return;
}

void multiplicar(int *h, int *x, int *res, int tam)
{
	int suma = 0;
	for (int i = 0; i < tam; i++)
	{
		suma += h[i] * x[i];
	}
	res[0] = suma;
}
#endif
