/************************************************************************************************
Copyright (c) <2023>, Emiliano Arnedo <emiarnedo@gmail.com>
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef CALCULADORA_H
#define CALCULADORA_H

/** \brief Declaraciones publicas del modulo 'calculadora'
 **
 ** \addtogroup calculadora Calculadoras
 ** \brief Modulo para la creacion y asignacion de funciones de una calculadora
 ** @{ */

/* === Headers files inclusions ================================================================ */

#include "stdbool.h"
#include "stdlib.h"

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/**
 * @typedef calculadora_t
 * @brief Alias para un puntero a una estructura calculadora_s
 *
 * calculadora_t es un tipo de dato que representa un puntero a una estructura del tipo
 * calculadora_s.
 */
typedef struct calculadora_s * calculadora_t;

/**
 * @typedef funciont_t
 * @brief Alias para un puntero a una funcion
 *
 * funciont_t es un tipo de dato puntero a una funcion que toma dos enteros como parametro y
 * devuelve tambien un entero.
 */
typedef int (*funciont_t)(int, int);

/* === Public variable declarations ============================================================*/

/* === Public function declarations ============================================================*/

/**
 * @brief funcion para crear una instancia de una estructura calculadora_s que retorna un puntero a
 * la misma.
 *
 * @return calculadora_t puntero a la nueva estructura creada
 */
calculadora_t CrearCalculadora(void);

/**
 * @brief función para agregar una operacion a la calculadora
 *
 * @param calculadora puntero a la estructura donde se agregará la operación
 * @param operador simbolo del operador
 * @param funcion puntero a la funcion de la operación que se agregará
 * @return true si se agregó satisfactoriamente la operacion
 * @return false si falló al adición de la operación
 */
bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion);

/**
 * @brief función para calcular en base a las operaciones guardadas en calculadora
 *
 * Ademas del puntero a la estructura calculadora_s, la función recibe un cadena de caracteres en la
 * que detecta el operador para realizar la operacion.
 *
 * @param calculadora puntero a una estructura del tipo calculadora_s
 * @param cadena operacion a realizar. ej: "2+2"
 * @return int resultado de la operacion.
 */
int Calcular(calculadora_t calculadora, char * cadena);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* CALCULADORA_H */
