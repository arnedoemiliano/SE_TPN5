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

/** \brief Implementacion del modulo 'calculadora'
 **
 ** \addtogroup calculadora Calculadoras
 ** \brief Modulo para la creacion y asignacion de funciones de una calculadora
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "./calculadora.h"

#include "string.h"
#include "stdio.h"

/* === Macros definitions ====================================================================== */

#if !defined(OPERACIONES)
    #define OPERACIONES 16
#endif // OPERACIONES

/* === Private data type declarations ========================================================== */

typedef struct operacion_s * operacion_t;

/**
 * @brief estructura de un objeto 'operacion'
 *
 */
struct operacion_s {
    char operador;         /**< Operador de la operación */
    funciont_t funcion;    /**< Puntero a la funcion que ejecuta la operación */
    operacion_t siguiente; /**< Puntero a la siguiente operación */
};

/**
 * @brief estructura de un objeto 'calculadora'
 *
 */
struct calculadora_s {
    operacion_t operaciones; /**< puntero a la operación actual */
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

// Devuelve un puntero a donde haya un operacion_s con operador = param operador
operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {

    operacion_t resultado = NULL;

    // for (int i = 0; i < count; i++)
    // El for comienza desde la operacion a la que apunta actualmente la calculadora. Sigue en el
    // ciclo mientras el miembro siguiente de la estructura operacion_s a la que apunta operaciones
    // sea distinto de NULL.Y por cada iteracion operaciones de calculadora toma el valor de
    // siguiente de la estrucutra operacion_s a la que apunta. Si el miembro operador de operacion_s
    // apuntado por actual coincide con el param. operador, retorna un puntero a ese operacion_s en
    // el que hubo coincidencia.

    // indica que no hay operaciones guardadas por que operaciones solo puede apuntar a un
    // operacion_s ocupado
    if (calculadora->operaciones == NULL) {
        printf("***La calculadora no tiene ninguna operacion guardada***\n");
        return NULL;
    } else {

        for (operacion_t actual = calculadora->operaciones; actual->siguiente != NULL;
             actual = actual->siguiente) {

            if (actual->operador == operador) {

                resultado = actual;
                break;
            }
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
    /******************************/
    resultado->operaciones = NULL;
    return resultado;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion) {
    operacion_t operacion = malloc(sizeof(struct operacion_s));

    // Si operacion tiene una direccion valida y el parametro operador, no se
    // agregó antes:
    if ((operacion) && !BuscarOperacion(calculadora, operador)) {
        operacion->operador = operador;
        operacion->funcion = funcion;
        // siguiente apunta a la operacion que apuntaba operaciones (operacion vieja)
        operacion->siguiente = calculadora->operaciones;
        // operaciones apunta a la operacion mas reciente
        // duda: cuando se agrege un operacion por primera vez, entonces siguiente
        // tendrá un valor NULL
        calculadora->operaciones = operacion;
    }

    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena) {
    int a, b;
    char operador;
    int resultado = 0;

    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] < '0') {
            operador = cadena[i];
            a = atoi(cadena);
            b = atoi(cadena + i + 1);
            break;
        }
    }
    operacion_t operacion = BuscarOperacion(calculadora, operador);
    if (operacion) {
        resultado = operacion->funcion(a, b);
    } else {
        printf("***Fallo al encontrar la operacion solicitada***\n");
    }
    return resultado;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
