#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
#define PRODUCTOS_MAXIMO 10

int main (int argc, char *argv[]) {
    char productos[PRODUCTOS_MAXIMO][30];
    int amount;
    float precios[PRODUCTOS_MAXIMO];
    llenarProductosInfo(productos, precios, amount);
    printf("======================================================\n");
    printf("=============SISTEMA DE CONTROL DE PRODUCTOS==========\n");
    printf("======================================================\n");
    printf("\n");
    printf("MENU:\n");
    printf("1. Calcular el precio total del inventario\n");
    printf("2. Encontrar el producto mas caro y el mas barato\n");
    printf("3. Calcular el promedio del precio de los productos\n");
    printf("4. Busqueda de informacion de un producto especifico\n");
    return 0;
}