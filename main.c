#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10

int main(int argc, char *argv[])
{
    int opc, val, cant, len;
    char producto[MAX_PRODUCTOS][30];
    float precio[MAX_PRODUCTOS];
    char nombre[30];

    printf("Cuantos productos desea registrar? (maximo %d): ", MAX_PRODUCTOS);
    fflush(stdin);
    do
    {
        val = scanf("%d", &cant);
        if (val != 1)
        {
            printf("Error: Entrada no válida. Por favor, ingrese un número.\n");
            fflush(stdin);
        }
        else if (cant > MAX_PRODUCTOS || cant < 1)
        {
            printf("Error: El número de productos debe estar entre 1 y %d. Intente nuevamente: ", MAX_PRODUCTOS);
        }
        else
        {
        }
    } while (val != 1 || cant > MAX_PRODUCTOS || cant < 1);

    do
    {
        printf("\n=====================================\n");
        printf("      GESTIÓN DE INVENTARIO         \n");
        printf("=====================================\n");
        printf(" 1. Calcular precio total del inventario\n");
        printf(" 2. Encontrar producto más caro\n");
        printf(" 3. Encontrar producto más barato\n");
        printf(" 4. Calcular precio promedio\n");
        printf(" 5. Buscar producto por nombre\n");
        printf(" 6. Salir\n");
        printf("=====================================\n");
        printf(">> ");

        fflush(stdin);
        val = scanf("%d", &opc);
        if (val != 1)
        {
            printf("Error: Entrada no válida. Por favor, ingrese un número.\n");
        }

        switch (opc)
        {
        case 1:
            printf("Precio total del inventario: %.2f\n", calcularPrecioTotal(precio, cant));
            printf("\n");
            break;

        case 2:
            encontrarMasCaro(precio, cant, producto);
            printf("\n");
            break;

        case 3:
            encontrarMasBarato(precio, cant, producto);
            printf("\n");
            break;

        case 4:
            printf("Precio promedio: %.2f\n", calcularPrecioPromedio(precio, cant));
            printf("\n");
            break;

        case 5:
            printf("Ingrese el nombre del producto a buscar: ");
            fflush(stdin);
            fgets(nombre, 30, stdin);

            len = strlen(nombre) - 1;
            if (nombre[len] == '\n')
            {
                nombre[len] = '\0';
            }
            buscarProducto(precio, cant, producto, nombre);
            printf("\n");
            break;

        default:
            break;
        }
    } while (opc != 6 || val != 1);

    return 0;
}
