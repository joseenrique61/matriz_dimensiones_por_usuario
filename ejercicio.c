#include <stdio.h>
#include <stdlib.h>

void obtenerDimensiones();
int **crearMatriz();
void imprimirMatriz(int **matriz);

int m = 0;
int n = 0;

int main() 
{
    int **matriz = crearMatriz();
    imprimirMatriz(matriz);
    free(matriz);
}

void obtenerDimensiones()
{
    printf("Ingrese la cantidad de filas: ");
    scanf("%i", &m);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%i", &n);
}

int **crearMatriz()
{
    obtenerDimensiones();

    int **matriz = calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matriz[i] = calloc(n, sizeof(int));
    }
    return matriz;
}