/**
 * @file alumno.h
 * @brief Archivo: alumno.h
 * Este archivo es la interfaz publica del archivo alumno.c.
 */

#ifndef ALUMNO_H
#define ALUMNO_H

/*==================[inclusions]=============================================*/
#include <stdint.h>
#include <stdbool.h>
/*==================[macros]=================================================*/
#define SIZE_DATA 50 //!< Tamaño del dato.
/**
 * @brief Eleccion de memoria estatica o dinamica
 * Podemos optar si queremos elegir guardar en memoria dinamica o estatica nuestra
 * estructura alumno. Si queremos que sea mediante memoria dinamica, se comenta la linea
 * "#define DINAMIC 0", si queremos que sea con memoria estatica no se corrige nada.
 */
#define DINAMIC 0
/*==================[typedef]================================================*/
//! Puntero a la estructura que tendra los datos del alumno
typedef struct alumno_s * alumno_pt;
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/** @brief Funcion Serializar
 *  Esta funcion se encargara de serializar los datos de la estructura alumno.
 *  Debemos pasarle un puntero a la estrucutra alumno, un cadena en la cual se
 *  guardara el resultado y por ultimo el tamaño de la cadena. Se pasa el tama
 *  ño de la cadena para que no se puede desbordar al serializar.
 * @param estructura Puntero a la estructura alumno
 * @param cadena Puntero a donde guardaremos los datos
 * @param tamaño Tamaño de la cadena
 * **/
int SerializarAlumno(const struct alumno_s * estructura, char cadena[], uint8_t tamaño);
/**
 * @brief Funcion CrearAlumno
 * Esta funcion devolvera un puntero constante a una estructura alumno, la funcion va a
 * crear un alumno con los datos proporcionados.
 * @param apellido
 * @param nombre
 * @param documento
 */
const alumno_pt CrearAlumno(char * apellido, char * nombre, uint32_t documento);
/**
 * @brief Funcion TipoAlumno:
 * Esta funcion nos indicara si la estructura fue creada con memoria estatica o dinamica.
 * @param alumno    Puntero a la estructura.
 * @return true  Memoria Dinamica
 * @return false Memoria Estatica
 */
bool TipoAlumno(const alumno_pt alumno);
/** doxygen end group definition */
/** doxygen end group definition */
/** doxygen end group definition */
/*==================[end of file]============================================*/
#endif