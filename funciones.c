#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Ahora recibe también cantidades[]
void llenarProductosInfo(char productos[][30], float precios[], int cantidades[], int amount)
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

                if (len < 1)
                {
                    printf("El nombre no puede estar vacio. Intentelo de nuevo.\n");
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

            } while (len < 1 || repetido == 1);
        }
    } while (len < 1 || repetido == 1);
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

        do
        {
            printf("Por favor ingrese la cantidad en stock del producto %s\n", productos[k]);
            fflush(stdin);
            val = scanf("%d", &cantidades[k]);
            if (val != 1 || cantidades[k] < 0)
            {
                printf("Por favor ingrese una cantidad valida (0 o mayor).\n");
            }
        } while (val != 1 || cantidades[k] < 0);
    }
}

// Calcula el valor total del inventario sumando precio unitario * cantidad
float CalcularTotalInventario(float precios[], int cantidades[], int amount)
{
    float total_operacion = 0;
    for (int i = 0; i < amount; i++)
    {
        total_operacion += precios[i] * cantidades[i];
    }
    return total_operacion;
}

// Muestra también la cantidad
void HallarProductoBara(float precios[], char productos[][30], int cantidades[], int amount)
{
    int posicion_del_precio = 0;
    for (int i = 0; i < amount; i++)
    {
        if (precios[i] < precios[posicion_del_precio])
        {
            posicion_del_precio = i;
        }
    }
    printf("El producto mas barato en stock es: %s, con un precio de: %.2f y cantidad: %d\n",
           productos[posicion_del_precio], precios[posicion_del_precio], cantidades[posicion_del_precio]);
}

void HallarProductoCaro(float precios[], char productos[][30], int cantidades[], int amount)
{
    int posicion_del_precio = 0;
    for (int i = 0; i < amount; i++)
    {
        if (precios[i] > precios[posicion_del_precio])
        {
            posicion_del_precio = i;
        }
    }
    printf("El producto mas caro en stock es: %s, con un precio de: %.2f y cantidad: %d\n",
           productos[posicion_del_precio], precios[posicion_del_precio], cantidades[posicion_del_precio]);
}

// Calcula el promedio ponderado por cantidad
float CalcularPromedioPrecios(float precios[], int cantidades[], int amount)
{
    float suma = 0;
    int total_cantidades = 0;
    for (int i = 0; i < amount; i++)
    {
        suma += precios[i] * cantidades[i];
        total_cantidades += cantidades[i];
    }
    if (total_cantidades == 0)
        return 0;
    return suma / total_cantidades;
}

// Muestra también la cantidad
void BuscarInfoPorNombre(char productos[][30], float precios[], int cantidades[], int amount)
{
    int len, indiceEncontrado = -1;
    int f = 0;
    char nombre[30];

    printf("Por favor ingrese el nombre del producto que desea buscar en stock.\n");
    fflush(stdin);
    fgets(nombre, 30, stdin);

    // Remover el salto de línea si está presente
    len = strlen(nombre) - 1;
    if (nombre[len] == '\n')
    {
        nombre[len] = '\0';
    }
    if (strlen(nombre) == 0)
    {
        printf("No puede estar vacio\n");
    }
    else
    {
        // Buscar el producto en la lista
        for (int i = 0; i < amount; i++)
        {
            if (strcmp(productos[i], nombre) == 0)
            {
                indiceEncontrado = i; // Guardamos la posición del producto encontrado
                f = 1;

                printf("\nProducto encontrado: %s\n", productos[indiceEncontrado]);
                printf("Precio: %.2f\n", precios[indiceEncontrado]);
                printf("Cantidad en stock: %d\n", cantidades[indiceEncontrado]);
            }
        }

        if (f == 0)
        {
            printf("No existe ningun producto con ese nombre en el stock.\n");
        }
    }
}
