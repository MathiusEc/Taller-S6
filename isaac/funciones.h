#include <stdio.h>
#include <string.h>

void llenarProductosInfo(char productos[][30], float precios[], int amount)
{
    int len = 0, val = 0, repetido;
    do
    {
        repetido = 0;
        do
        {
            do
            {
                printf("Por favor, ingrese la cantidad de productos\n");
                fflush(stdin);
                val = scanf("%d", &amount);
                if (val != 1)
                {
                    printf("Dato ingresado incorrecto, intente de nuevo.\n");
                    printf("\n");
                    fflush(stdin);
                }
                else if (amount <= 0 || amount > 10)
                {
                    printf("Por favor ingrese un valor valido dentro del rango (1 a 10).\n");
                    fflush(stdin);
                }

            } while (val != 1 || (amount <= 0 || amount > 10));

        } while (val != 1 || (amount <= 0 && amount > 10));

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
    }while (len < 1 || repetido);
    for (int k = 0; k < 10; k++)
    {
        do
        {
            printf("Por favor ingrese el precio del producto %s", productos[k]);
            fflush(stdin);
            val = scanf("%f", &precios[k]);
            if (val != 1 || precios[k] <= 0)
            {
                printf("Por favor ingrese un valor valido mayor a 0.\n");
            }
        } while (val != 1 || (precios[k] <= 0));
    }
}