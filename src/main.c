/**
 * @file main.c
 * @brief Archivo: alumno.h
 * Este archivo es el programa principal de nuestro trabajo.
 */

/*==================[inclusions]=============================================*/
#include "alumno.h"
#include <stdio.h>
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
//! Implementacion del codigo.
int main(void) {

    static const struct alumno_s adan = {.apellido = "Lema", .nombre = "Adan", .dni = 41984217};
    char                         cadena[100];
    if (Serializar(&adan, cadena, sizeof(cadena)) >= 0) {
        printf("%s\n", cadena);
    } else {
        printf("Ocurrio un error al serializar.\n");
    }
    return 0;
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/