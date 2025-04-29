#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10

int main(int argc, char *argv[])
{
    int opc, val, cant;
    char producto[MAX_PRODUCTOS][30];
    float precio[MAX_PRODUCTOS];

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
            
            break;
        
        default:
            break;
        }
    } while (opc != 6 || val != 1);

    return 0;
}