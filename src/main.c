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

/** \brief Trabajo practico numero 5
 *
 ** \addtogroup tp5 TPN5
 ** \brief
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include "stdio.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */
int sumar(int a, int b);
int multiplicar(int a, int b);
int restar(int a, int b);
/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

int sumar(int a, int b) {
    return a + b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int restar(int a, int b) {
    return a - b;
}

/* === Public function implementation ========================================================== */

int main(void) {

    bool flag = false;

    calculadora_t calculadora = CrearCalculadora();

    if (calculadora) {
        printf("***Se creo exitosamente la calculadora***\n");

    } else {
        printf("No se pudo crear calculadora");
    }

    flag = AgregarOperacion(calculadora, '+', sumar);

    if (flag) {
        printf("***Se agregó exitosamente la nueva operacion***\n");

    } else {
        printf("***No se pudo agregar la operacion***");
    }

    flag = AgregarOperacion(calculadora, '*', multiplicar);

    if (flag) {
        printf("***Se agregó exitosamente la nueva operacion***\n");

    } else {
        printf("***No se pudo agregar la operacion***");
    }

    flag = AgregarOperacion(calculadora, '-', restar);

    if (flag) {
        printf("***Se agregó exitosamente la nueva operacion***\n");

    } else {
        printf("***No se pudo agregar la operacion***");
    }

    int result = Calcular(calculadora, "9+5");
    printf("%i\n", result);

    result = Calcular(calculadora, "9*5");
    printf("%i\n", result);

    result = Calcular(calculadora, "9-5");
    printf("%i\n", result);
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
