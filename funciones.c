#include <stdio.h>

void registrarProductos(char producto[][30], float precio[], int cantidad)
{
    int len, val;
    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el nombre del producto %d: ", i);
        fflush(stdin);
        fgets(producto[i], 30, stdin);
        len = strlen(producto[i]) - 1;
        if (producto[i][len] == '\n')
        {
            producto[i][len] = '\0';
        }

        printf("Ingrese el precio del producto %d: ", i);
        fflush(stdin);
        do
        {
            val = scanf("%f", &precio[i]);
            if (val != 1)
            {
                printf("Error: Entrada no válida. Por favor, ingrese un número.\n");
                fflush(stdin);
            }
            else if (precio[i] < 0)
            {
                printf("Error: El precio no puede ser negativo. Intente nuevamente: ");
            }
        } while (val != 1 || precio[i] < 0);
    }

    printf("Productos registrados correctamente.\n");
}