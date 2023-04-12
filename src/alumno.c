/**
 * @file alumno.c
 * @brief Archivo: alumno.c
 * Este archivo se encargara de serializar los datos enviados y los devolvera en
 * la cadena de texto proporcionada.
 */

/*==================[inclusions]=============================================*/
#include "alumno.h"
#include <stdio.h>

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
static int SerializarCadena(const char *valor, const char *campo, char *cadena,
                            uint8_t disponible);

/**
 * @brief Serializar un numero.
 *  Esta funcion se encargara de serializar un numero entero.
 * **/
static int SerializarNumero(const int valor, const char *campo, char *cadena,
                            uint8_t disponible);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
//! Implementacion de la funcion SerializarCadena
static int SerializarCadena(const char *valor, const char *campo, char *cadena,
                            uint8_t disponible) {
  return snprintf(cadena, disponible, "\"%s\":\"%s\",", campo, valor);
}

//! Implementacion de la funcion SerializarNumero
static int SerializarNumero(const int valor, const char *campo, char *cadena,
                            uint8_t disponible) {
  return snprintf(cadena, disponible, "\"%s\":\"%d\",", campo, valor);
}

/*==================[external functions definition]==========================*/
int Serializar(const struct alumno_s *estructura, char cadena[],
               uint8_t tamaño) {
  int disponible = tamaño;
  int resultado;

  *cadena = '{';
  cadena++;
  disponible--;

  resultado =
      SerializarCadena(estructura->apellido, "apellido", cadena, disponible);
  if (resultado > 0) {
    disponible -= resultado;
    cadena += resultado;
    resultado =
        SerializarCadena(estructura->nombre, "nombre", cadena, disponible);
  }
  if (resultado > 0) {
    disponible -= resultado;
    cadena += resultado;
    resultado =
        SerializarNumero(estructura->dni, "documento", cadena, disponible);
  }
  if (resultado > 0) {
    disponible -= resultado;
    cadena += resultado;
    *(cadena - 1) = '}';
    resultado = tamaño - disponible;
  }
  return resultado;
}

/** doxygen end group definition */
/** doxygen end group definition */
/** doxygen end group definition */
/*==================[end of file]============================================*/