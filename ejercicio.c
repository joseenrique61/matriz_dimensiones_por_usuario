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

void imprimirMatriz(int **matriz)
{
    for (int i = 0; i < m; i++)
    {
        if (m == 1)
        {
            printf("[ ");
        }
        else
        {
            if (i == 0)
            {
                printf("%c ", 218);
            }
            else if (i == m - 1)
            {
                printf("%c ", 192);
            }
            else
            {
                printf("| ");
            }
        }

        for (int j = 0; j < n; j++)
        {
            printf("%i ", matriz[i][j]);
        }

        if (m == 1)
        {
            printf("] ");
        }
        else
        {
            if (i == 0)
            {
                printf("%c\n", 191);
            }
            else if (i == m - 1)
            {
                printf("%c\n", 217);
            }
            else
            {
                printf("|\n");
            }
        }
    }
}