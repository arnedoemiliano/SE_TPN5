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

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include "stdbool.h"
#include "stdlib.h"

/* === Macros definitions ====================================================================== */

#if !defined(OPERACIONES)
    #define OPERACIONES 16
#endif // OPERACIONES

/* === Private data type declarations ==========================================================
 */

typedef struct operacion_s * operacion_t;

struct operacion_s {
    char operador;
    funciont_t funcion;
    // operacion_t siguiente;
};

struct calculadora_s {
    // Arreglo de estructuras del tipo operacion_s
    struct operacion_s operaciones[OPERACIONES];
    // operacion_t operaciones;
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

operacion_t BuscarOperacion(calculadora_t calculadora, char coincidencia);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {

    operacion_t resultado = NULL;

    for (int i = 0; i < sizeof(struct calculadora_s); i++) {
        if (calculadora->operaciones[i].operador == operador) {
            resultado = &calculadora->operaciones[i];
            break;
        }
    }

    return resultado;
}

/* === Public function implementation ========================================================== */

calculadora_t CrearCalculadora() {
    calculadora_t resultado = malloc(sizeof(struct calculadora_s));
    if (resultado) {
        memset(resultado, 0, sizeof(struct calculadora_s));
    }

    return resultado;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion) {

    operacion_t operacion = BuscarOperacion(calculadora, 0);

    // Busco que operacion tenga un valor de direccion valido y que la nueva funcion de la calcu-
    // ladora no se encuentre ya entre sus funciones.
    if ((operacion) && !BuscarOperacion(calculadora, operador)) {

        operacion->operador = operador;
        operacion->funcion = funcion;
    }

    return (operacion != NULL);
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
