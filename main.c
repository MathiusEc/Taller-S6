#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define PRODUCTOS_MAXIMO 10

int main(int argc, char *argv[])
{
    char productos[PRODUCTOS_MAXIMO][30];
    int amount, opcin;
    float precios[PRODUCTOS_MAXIMO];
    int validar, val;
    printf("======================================================\n");
    printf("\t\tSISTEMA DE GESTION DE PRODUCTOS\t\t\n");
    printf("======================================================\n");
    printf("\n");
    do
    {
        printf("Por favor, ingrese la cantidad de productos, maximo %d\n", PRODUCTOS_MAXIMO);
        fflush(stdin);
        val = scanf("%d", &amount);
        if (val != 1)
        {
            printf("Dato ingresado incorrecto, intente de nuevo.\n");
            printf("\n");
            fflush(stdin);
        }
        else if (amount <= 0 || amount > PRODUCTOS_MAXIMO)
        {
            printf("Por favor ingrese un valor valido dentro del rango (1 a 10).\n");
            fflush(stdin);
        }

    } while (val != 1 || (amount < 1 || amount > PRODUCTOS_MAXIMO));

    llenarProductosInfo(productos, precios, amount);

    do
    {
        printf("======================================================\n");
        printf("\t\tSISTEMA DE CONTROL DE PRODUCTOS\t\t\n");
        printf("======================================================\n");
        printf("\n");
        printf("MENU:\n");
        printf("1. Calcular el precio total del inventario\n");
        printf("2. Encontrar el producto mas caro y el mas barato\n");
        printf("3. Calcular el promedio del precio de los productos\n");
        printf("4. Busqueda de informacion de un producto especifico\n");
        printf("5. Salir\n");
        do
        {
            printf("Ingrese una opcion\n");
            printf(">>");
            fflush(stdin);
            validar = scanf("%d", &opcin);
            if (validar != 1 || (opcin < 1 || opcin > 5))
            {
                printf("Por favor ingrese un valor dentro del rango disponible (1 a 5)\n");
                printf("\n");
            }
        } while (validar != 1 || (opcin < 1 || opcin > 5));
        switch (opcin)
        {
        case 1:

            printf("El total del precio del inventario es de: %.2f\n", CalcularTotalInventario(precios, amount));
            printf("\n");

            break;
        case 2:// Hallar el producto más caro y mas bajo
            
            HallarProductoBara(precios, productos, amount);
            HallarProductoCaro(precios, productos, amount);
            //Hacemos un llamado a las funciones para poder usarlas.
            break;
        case 3:// Calcular el precio promedio de los productos
            
            printf("El promedio de precios del stock es de: %.2f\n", CalcularPromedioPrecios(precios, amount));

            break;
        case 4:// Buscar producto por nombre y mostrar precio
            
            BuscarInfoPorNombre(productos, precios, amount);

            break;
        default:
            break;
        }
    } while (opcin != 5);
    printf("GRACIAS POR USAR NUESTRO SERVICIO, HASTA LUEGO..\n");

    return 0;
}