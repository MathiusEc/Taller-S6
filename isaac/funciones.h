#include <stdio.h>
#include <string.h>

void llenarProductos(char productos[][30], float precios[], int amount)
{
    int len = 0, val = 0;
    do
    {
        printf("Por favor, ingrese la cantidad de productos\n");
        scanf("%d", &amount);
        do
        {
            if (val != 1 || (amount <= 0 && amount > 10))
            {
                printf("Dato ingresado incorrecto, intente de nuevo.\n");
                printf("\n");
            }

        } while (val != 1 || (amount <= 0 && amount > 10));

    } while (val != 1 || (amount <= 0 && amount > 10));

    for (int i = 0; i < 10; i++)
    {
        /* code */
    }
}