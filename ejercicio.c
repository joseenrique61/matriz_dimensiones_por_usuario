//Se incluyen las librerías stdio.h para ingresar datos y mostrarlos al usuario, y stdlib.h para usar las funciones de memoria dinámica.
#include <stdio.h>
#include <stdlib.h>

//Se definen los prototipos
void obtenerDimensiones();
int **crearMatriz();
void imprimirMatriz(int **matriz);
void cambiarDiagonal(int **matriz);

//Se definen las variables, m para filas y n para columnas
int m = 0;
int n = 0;

int main()
{
    //Se define la matriz como un puntero a puntero para poder crear un array con dimensiones variables, y se le asigna el valor devuelto por crearMatriz.
    int **matriz = crearMatriz();

    printf("Matriz inicializada en 0:\n");
    imprimirMatriz(matriz);

    cambiarDiagonal(matriz);
    printf("\nMatriz con la diagonal cambiada: \n");
    imprimirMatriz(matriz);
    
    //Se libera la memoria usada por matriz.
    free(matriz);
}

//Función que obtiene las dimensiones de los usuarios.
void obtenerDimensiones()
{
    printf("Ingrese la cantidad de filas: ");
    scanf("%i", &m);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%i", &n);
}

//Se crea la matriz usando memoria dinámica, y se definen sus valores en ceros.
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

//Se cambia la diagonal principal de la matriz por unos.
void cambiarDiagonal(int **matriz)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 1;
            }
        }
    }
}

//Función que imprime la matriz actual.
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