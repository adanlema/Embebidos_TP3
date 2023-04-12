/**
 * @file alumno.h
 * @brief Archivo: alumno.h
 * Este archivo es la interfaz publica del archivo alumno.c.
 */

#ifndef ALUMNO_H
#define ALUMNO_H

/*==================[inclusions]=============================================*/
#include <stdint.h>
/*==================[macros]=================================================*/
#define SIZE_DATA 50 //!< Tamaño del dato.
/*==================[typedef]================================================*/
//! Puntero a la estructura que tendra los datos del alumno
typedef struct alumno_s {
    char     nombre[SIZE_DATA];
    char     apellido[SIZE_DATA];
    uint32_t dni;
} * alumno_pt;

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/** @brief Funcion Serializar
 *  Esta funcion se encargara de serializar los datos de la estructura alumno.
 *  Debemos pasarle un puntero a la estrucutra alumno, un cadena en la cual se
 *  guardara el resultado y por ultimo el tamaño de la cadena. Se pasa el tama
 *  ño de la cadena para que no se puede desbordar al serializar.
 * **/
int Serializar(const struct alumno_s * estructura, //!< Puntero a la estructura alumno
               char                    cadena[],   //!< Puntero a donde guardaremos los datos
               uint8_t                 tamaño      //!< Tamaño de la cadena
);
/** doxygen end group definition */
/** doxygen end group definition */
/** doxygen end group definition */
/*==================[end of file]============================================*/
#endif