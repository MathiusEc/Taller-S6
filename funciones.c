#include <stdio.h>
#include <string.h>
#include "funciones.h"

void llenarProductosInfo(char productos[][30], float precios[], int amount)
{
    int len = 0, val = 0, repetido;
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
    }while (len < 1 || repetido);
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
}

float CalcularTotalInventario(float precios[], int amount)
{
    float total_operacion = 0;
    for (int i = 0; i < amount; i++)
    {
        total_operacion += precios[i];
    }

    return total_operacion;
}
//funciones para hallar el producto más caro y más barato 👍
void HallarProductoBara(float precios[], char productos[][30], int amount)
{
    int posicion_del_precio = 0;
    for (int i = 0; i < amount; i++)
    {
        if (precios[i] < precios[posicion_del_precio])
        {
            posicion_del_precio = i;
        }
    }
    printf("El producto mas barato en stock es: %s, con un precio de: %.2f\n", productos[posicion_del_precio], precios[posicion_del_precio]);
}

void HallarProductoCaro(float precios[], char productos[][30], int amount)
{
    int posicion_del_precio = 0;
    for (int i = 0; i < amount; i++)
    {
        if (precios[i] > precios[posicion_del_precio])
        {
            posicion_del_precio = i;
        }
    }
    printf("El producto mas caro en stock es: %s, con un precio de: %.2f\n", productos[posicion_del_precio], precios[posicion_del_precio]);
}

float CalcularPromedioPrecios(float precios[], int amount)
{
    float promedio = 0;
    for (int i = 0; i < amount; i++)
    {
        promedio += precios[i];
    }
    promedio /= amount;
    return promedio;
}

//Función para el caso 4: buscar la info de un producto en stock por nombre:

void BuscarInfoPorNombre(char productos[][30], float precios[], int amount)
{
    int len, indiceEncontrado = -1; // -1 indica que no se ha encontrado el producto
    char nombre[30];

    printf("Por favor ingrese el nombre del producto que desea buscar en stock.\n");
    fflush(stdin);
    fgets(nombre, 30, stdin);

    // Remover el salto de línea si está presente
    len = strlen(nombre) - 1;
    if (nombre[len] == '\n') {
        nombre[len] = '\0';
    }

    // Buscar el producto en la lista
    for (int i = 0; i < amount; i++)
    {
        if (strcmp(productos[i], nombre) == 0)
        {
            indiceEncontrado = i; // Guardamos la posición del producto encontrado
            break;
        }
    }

    if (indiceEncontrado != -1)
    {
        printf("Producto encontrado: %s\n", productos[indiceEncontrado]);
        printf("Precio: %.2f\n", precios[indiceEncontrado]);
    }
    else
    {
        printf("No existe ningun producto con ese nombre en el stock.\n");
    }
}