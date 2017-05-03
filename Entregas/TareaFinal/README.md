#MemManager v0.1

##Overview
MenManager es una microlibrería experimental de administración de memoria que tiene como objetivo administrar el heap 
para llevar una lista de la memoria reservada por el programa y si es liberada.

El programa tiene como principal uso evitar eliminar objetos dos o más veces (double delete) además de asegurarse de liberar
toda la memoria del heap al final de un programa o a comando del programador.

##Guía de uso

El archivo main.cpp proveé una implementación básica de la librería. Solo es necesario importar el encabezado:
`#include "MemManager.h"`

Y finalmente agregar una llamada a la función que limpia el heap por completo al final del programa. (También puede utilizarse para forzar liberar toda la memoria en otras secciones del programa)
` clearMem();`