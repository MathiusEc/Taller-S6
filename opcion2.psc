Proceso SistemaGestionProductos
    // Declaración de variables y arreglos
    Definir productos Como Cadena
    Dimension productos[10]
    Definir precios Como Real
    Dimension precios[10]
    Definir cantidades Como Entero
    Dimension cantidades[10]
    Definir cantidad_productos, opcion, i Como Entero
    Definir continuar Como Logico
    
    // Inicialización
    continuar <- Verdadero
    
    // Solicitar cantidad de productos
    Escribir "======================================================"
    Escribir "        SISTEMA DE GESTION DE PRODUCTOS"
    Escribir "======================================================"
    
    cantidad_productos <- SolicitarCantidadProductos()
    
    // Registrar información de productos
    RegistrarProductos(productos, precios, cantidades, cantidad_productos)
    
    // Menú principal
    Mientras continuar Hacer
        MostrarMenu()
        Leer opcion
        
        Segun opcion Hacer
            Caso 1:
                MostrarInventarioTotal(precios, cantidades, cantidad_productos)
            Caso 2:
                MostrarProductosExtremos(productos, precios, cantidades, cantidad_productos)
            Caso 3:
                MostrarPromedioPrecios(precios, cantidades, cantidad_productos)
            Caso 4:
                BuscarProducto(productos, precios, cantidades, cantidad_productos)
            Caso 5:
                continuar <- Falso
                Escribir "GRACIAS POR USAR NUESTRO SERVICIO, HASTA LUEGO.."
            De Otro Modo:
                Escribir "Por favor ingrese una opción válida (1 a 5)."
        FinSegun
    FinMientras
FinProceso

// Subproceso para solicitar y validar la cantidad de productos
Funcion cantidad <- SolicitarCantidadProductos()
    Definir cantidad, validacion Como Entero
    Definir entrada_valida Como Logico
    
    entrada_valida <- Falso
    
    Mientras No entrada_valida Hacer
        Escribir "Por favor, ingrese la cantidad de productos, máximo 10"
        Leer cantidad
        
        Si cantidad > 0 Y cantidad <= 10 Entonces
            entrada_valida <- Verdadero
        Sino
            Escribir "Por favor ingrese un valor válido dentro del rango (1 a 10)."
        FinSi
    FinMientras
    
    Retornar cantidad
FinFuncion

// Subproceso para mostrar el menú principal
SubProceso MostrarMenu()
    Escribir "======================================================"
    Escribir "        SISTEMA DE CONTROL DE PRODUCTOS"
    Escribir "======================================================"
    Escribir "MENU:"
    Escribir "1. Calcular el precio total del inventario"
    Escribir "2. Encontrar el producto más caro y el más barato"
    Escribir "3. Calcular el promedio del precio de los productos"
    Escribir "4. Búsqueda de información de un producto específico"
    Escribir "5. Salir"
    Escribir "Ingrese una opción:"
FinSubProceso

// Subproceso para registrar productos
SubProceso RegistrarProductos(productos, precios, cantidades, cantidad_productos)
    Definir i, j Como Entero
    Definir nombre_valido, nombre_duplicado Como Logico
    Definir precio_valido, cantidad_valida Como Logico
    Definir nombre_temp Como Cadena
    
    Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
        // Solicitar y validar nombre del producto
        nombre_valido <- Falso
        
        Mientras No nombre_valido Hacer
            nombre_duplicado <- Falso
            Escribir "Por favor ingrese el nombre del producto ", i+1
            Leer nombre_temp
            
            Si Longitud(nombre_temp) > 0 Entonces
                // Verificar si el nombre ya existe
                Para j <- 0 Hasta i-1 Con Paso 1 Hacer
                    Si nombre_temp = productos[j] Entonces
                        nombre_duplicado <- Verdadero
                        Escribir "El nombre ya fue ingresado. Introduzca un nombre distinto."
                        j <- i // Salir del bucle
                    FinSi
                FinPara
                
                Si No nombre_duplicado Entonces
                    nombre_valido <- Verdadero
                    productos[i] <- nombre_temp
                FinSi
            Sino
                Escribir "El nombre no puede estar vacío. Inténtelo de nuevo."
            FinSi
        FinMientras
        
        // Solicitar y validar precio del producto
        precio_valido <- Falso
        
        Mientras No precio_valido Hacer
            Escribir "Por favor ingrese el precio del producto ", productos[i]
            Leer precios[i]
            
            Si precios[i] > 0 Entonces
                precio_valido <- Verdadero
            Sino
                Escribir "Por favor ingrese un valor válido mayor a 0."
            FinSi
        FinMientras
        
        // Solicitar y validar cantidad del producto
        cantidad_valida <- Falso
        
        Mientras No cantidad_valida Hacer
            Escribir "Por favor ingrese la cantidad en stock del producto ", productos[i]
            Leer cantidades[i]
            
            Si cantidades[i] >= 0 Entonces
                cantidad_valida <- Verdadero
            Sino
                Escribir "Por favor ingrese una cantidad válida (0 o mayor)."
            FinSi
        FinMientras
    FinPara
FinSubProceso

// Subproceso para calcular y mostrar el total del inventario
SubProceso MostrarInventarioTotal(precios, cantidades, cantidad_productos)
    Definir total Como Real
    Definir i Como Entero
    
    total <- 0
    
    Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
        total <- total + (precios[i] * cantidades[i])
    FinPara
    
    Escribir "El total del precio del inventario es de: ", total
FinSubProceso

// Subproceso para encontrar y mostrar el producto más caro y más barato
SubProceso MostrarProductosExtremos(productos, precios, cantidades, cantidad_productos)
    Definir indice_min, indice_max, i Como Entero
    
    Si cantidad_productos > 0 Entonces
        indice_min <- 0
        indice_max <- 0
        
        Para i <- 1 Hasta cantidad_productos-1 Con Paso 1 Hacer
            Si precios[i] < precios[indice_min] Entonces
                indice_min <- i
            FinSi
            
            Si precios[i] > precios[indice_max] Entonces
                indice_max <- i
            FinSi
        FinPara
        
        Escribir "El producto más barato es: ", productos[indice_min], " con un precio de: ", precios[indice_min], " y cantidad: ", cantidades[indice_min]
        Escribir "El producto más caro es: ", productos[indice_max], " con un precio de: ", precios[indice_max], " y cantidad: ", cantidades[indice_max]
    Sino
        Escribir "No hay productos registrados."
    FinSi
FinSubProceso

// Subproceso para calcular y mostrar el promedio de precios
SubProceso MostrarPromedioPrecios(precios, cantidades, cantidad_productos)
    Definir suma, promedio Como Real
    Definir total_cantidades, i Como Entero
    
    suma <- 0
    total_cantidades <- 0
    
    Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
        suma <- suma + (precios[i] * cantidades[i])
        total_cantidades <- total_cantidades + cantidades[i]
    FinPara
    
    Si total_cantidades > 0 Entonces
        promedio <- suma / total_cantidades
    Sino
        promedio <- 0
    FinSi
    
    Escribir "El promedio de precios del stock es de: ", promedio
FinSubProceso

// Subproceso para buscar y mostrar información de un producto específico
SubProceso BuscarProducto(productos, precios, cantidades, cantidad_productos)
    Definir nombre_buscar Como Cadena
    Definir encontrado Como Logico
    Definir i Como Entero
    
    encontrado <- Falso
    
    Escribir "Por favor ingrese el nombre del producto que desea buscar:"
    Leer nombre_buscar
    
    Si Longitud(nombre_buscar) > 0 Entonces
        Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
            // Implementación de búsqueda insensible a mayúsculas/minúsculas
            Si Minusculas(productos[i]) = Minusculas(nombre_buscar) Entonces
                Escribir "Producto encontrado: ", productos[i]
                Escribir "Precio: ", precios[i]
                Escribir "Cantidad en stock: ", cantidades[i]
                encontrado <- Verdadero
                i <- cantidad_productos // Salir del bucle
            FinSi
        FinPara
        
        Si No encontrado Entonces
            Escribir "No existe ningún producto con ese nombre en el stock."
        FinSi
    Sino
        Escribir "El nombre de búsqueda no puede estar vacío."
    FinSi
FinSubProceso
