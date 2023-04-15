/**
 * @file alumno.c
 * @brief Archivo: alumno.c
 * Este archivo se encargara de serializar los datos enviados y los devolvera en
 * la cadena de texto proporcionada.
 */

/*==================[inclusions]=============================================*/
#include "alumno.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*==================[macros and definitions]=================================*/
#ifndef DINAMIC
#define DINAMIC 1
#endif
/*==================[internal data declaration]==============================*/
struct alumno_s {
    char     nombre[SIZE_DATA];
    char     apellido[SIZE_DATA];
    uint32_t dni;
    bool     dinamico;
};
/*==================[internal functions declaration]=========================*/
static int SerializarCadena(const char * valor, const char * campo, char * cadena,
                            uint8_t disponible);
static int SerializarNumero(const int valor, const char * campo, char * cadena,
                            uint8_t disponible);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
//! Implementacion de la funcion SerializarCadena
static int SerializarCadena(const char * valor, const char * campo, char * cadena,
                            uint8_t disponible) {
    return snprintf(cadena, disponible, "\"%s\":\"%s\",", campo, valor);
}

//! Implementacion de la funcion SerializarNumero
static int SerializarNumero(const int valor, const char * campo, char * cadena,
                            uint8_t disponible) {
    return snprintf(cadena, disponible, "\"%s\":\"%d\",", campo, valor);
}

/*==================[external functions definition]==========================*/
const alumno_pt CrearAlumno(char * apellido, char * nombre, uint32_t documento) {
    if (!DINAMIC) {
        static struct alumno_s resultado = {0};
        const alumno_pt        alumnoE   = &resultado;
        strcpy(alumnoE->apellido, apellido);
        strcpy(alumnoE->nombre, nombre);
        alumnoE->dni      = documento;
        alumnoE->dinamico = false;
        return alumnoE;
    } else {
        const alumno_pt alumnoD = malloc(sizeof(struct alumno_s));
        strcpy(alumnoD->apellido, apellido);
        strcpy(alumnoD->nombre, nombre);
        alumnoD->dni      = documento;
        alumnoD->dinamico = true;
        return alumnoD;
    }
}

int SerializarAlumno(const struct alumno_s * estructura, char cadena[], uint8_t tamaño) {
    int disponible = tamaño;
    int resultado;

    *cadena = '{';
    cadena++;
    disponible--;

    resultado = SerializarCadena(estructura->apellido, "apellido", cadena, disponible);
    if (resultado > 0) {
        disponible -= resultado;
        cadena += resultado;
        resultado = SerializarCadena(estructura->nombre, "nombre", cadena, disponible);
    }
    if (resultado > 0) {
        disponible -= resultado;
        cadena += resultado;
        resultado = SerializarNumero(estructura->dni, "documento", cadena, disponible);
    }
    if (resultado > 0) {
        disponible -= resultado;
        cadena += resultado;
        *(cadena - 1) = '}';
        resultado     = tamaño - disponible;
    }
    return resultado;
}

bool TipoAlumno(const alumno_pt alumno) {
    return alumno->dinamico;
}
/** doxygen end group definition */
/** doxygen end group definition */
/** doxygen end group definition */
/*==================[end of file]============================================*/