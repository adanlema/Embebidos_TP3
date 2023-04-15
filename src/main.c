/**
 * @file main.c
 * @brief Archivo: main.c
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

    const alumno_pt adan = CrearAlumno("Lema", "Adan", 41984217);
    char            cadena[100];
    if (SerializarAlumno(adan, cadena, sizeof(cadena)) >= 0) {
        printf("%s\n", cadena);
        if (!TipoAlumno(adan))
            printf("Se creo una estructura con memoria estatica.\n");
        else
            printf("Se creo una estructura con memoria dinamica.\n");
    } else {
        printf("Ocurrio un error al serializar.\n");
    }
    return 0;
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/