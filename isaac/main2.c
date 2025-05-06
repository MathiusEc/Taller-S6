#include <stdio.h>
#include <string.h>
#include "funciones2.h"

#define PRODUCTOS_MAXIMO 10

int main(int argc, char *argv[])
{
    char productos[PRODUCTOS_MAXIMO][30];
    int amount, opcin;
    float precios[PRODUCTOS_MAXIMO];
    int validar, val, len, repetido;
    printf("======================================================\n");
    printf("=============SISTEMA DE CONTROL DE PRODUCTOS==========\n");
    printf("======================================================\n");
    printf("\n");

    printf("Por favor, ingrese la cantidad de productos, maximo %d\n", PRODUCTOS_MAXIMO);
    fflush(stdin);
    val = scanf("%d", &amount);

    FuncionValidarCantidad(val, amount);

    // Llenado de productos:
    do
    {
        repetido = 0;
        for (int i = 0; i < amount; i++)
        {
            do
            {
                repetido = 0;

                printf("Por favor ingrese el nombre del producto %d\n", i + 1);
                fflush(stdin);
                fgets(productos[i], 30, stdin);

                // Remover el salto de línea si está presente
                len = strlen(productos[i]);
                if (productos[i][len - 1] == '\n')
                {
                    productos[i][len - 1] = '\0';
                    len--; // Ajustar longitud real
                }

                // Validar que el nombre no esté vacío y que no sea solo un "Enter"
                if (len < 1)
                {
                    printf("El nombre no puede estar vacio. Intentelo de nuevo.\n");
                    continue;
                }

                // Validar que el nombre no esté repetido
                for (int j = 0; j < i; j++)
                {
                    if (strcmp(productos[i], productos[j]) == 0)
                    {
                        repetido = 1;
                        printf("El nombre ya fue ingresado. Introduzca un nombre distinto.\n");
                        break;
                    }
                }

            } while (len < 1 || repetido);
        }
    } while (len < 1 || repetido);
    for (int k = 0; k < amount; k++)
    {
        do
        {
            printf("Por favor ingrese el precio del producto %s\n", productos[k]);
            fflush(stdin);
            val = scanf("%f", &precios[k]);
            if (val != 1 || precios[k] <= 0)
            {
                printf("Por favor ingrese un valor valido mayor a 0.\n");
            }
        } while (val != 1 || (precios[k] <= 0));
    }

    return 0;
}