#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
#define PRODUCTOS_MAXIMO 10

int main (int argc, char *argv[]) {
    char productos[PRODUCTOS_MAXIMO][30];
    int amount;
    float precios[PRODUCTOS_MAXIMO];
    llenarProductos(productos, precios, amount);

    return 0;
}