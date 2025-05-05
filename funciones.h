#include <stdio.h>
#include <string.h>

void registrarProductos(char producto[][30], float precio[], int cantidad)
{
    int len, val;
    for (int i = 0; i < cantidad; i++)
    {
        do
        {
            printf("Ingrese el nombre del producto %d: ", i);
            fflush(stdin);
            fgets(producto[i], 30, stdin);
            len = strlen(producto[i]) - 1;
            if (producto[i][len] == '\n')
            {
                producto[i][len] = '\0';
            }
            else if (strlen(producto[i]) == 0)
            {
                printf("Error: El nombre del producto no puede estar vacío. Intente nuevamente.\n");
            }

        } while (strlen(producto[i]) == 0);

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
}

float calcularPrecioTotal(float precios[], int cant)
{
    float total = 0;

    for (int i = 0; i < cant; i++)
    {
        total += precios[i];
    }
    return total;
}

void encontrarMasCaro(float precios[], int cant, char producto[][30])
{
    int indice = 0;
    for (int i = 1; i < cant; i++)
    {
        if (precios[i] > precios[indice])
        {
            indice = i;
        }
    }

    printf("Producto más caro: %s - $%.2f\n", producto[indice], precios[indice]);
}

void encontrarMasBarato(float precios[], int cant, char producto[][30])
{
    int indice = 0;
    for (int i = 1; i < cant; i++)
    {
        if (precios[i] < precios[indice])
        {
            indice = i;
        }
    }

    printf("Producto más barato: %s - $%.2f\n", producto[indice], precios[indice]);
}

float calcularPrecioPromedio(float precios[], int cant)
{
    float total = calcularPrecioTotal(precios, cant);
    float promedio = total / cant;

    return promedio;
}

int buscarProducto(float precios[], int cant, char producto[][30], char nombre[])
{
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(producto[i], nombre) == 0)
        {
            return i;
        }

    }
    return -1;
}
