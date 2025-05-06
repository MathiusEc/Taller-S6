#include <stdio.h>
#include <string.h>
#define PRODUCTOS_MAXIMO 10
int FuncionValidarCantidad(int val, int amount)
{
    do
    {
        if (val != 1)
        {
            printf("Dato ingresado incorrecto, intente de nuevo.\n");
            printf("\n");
            fflush(stdin);
            val = scanf("%d", &amount);
        }
    } while (val != 1);
    do
    {
        if (amount <= 0 || amount > PRODUCTOS_MAXIMO)
        {
            printf("Por favor ingrese un valor valido dentro del rango (1 a 10).\n");
            fflush(stdin);
            scanf("%d", &amount);
        }
    } while (amount <= 0 || amount > PRODUCTOS_MAXIMO);
    return amount;
}

