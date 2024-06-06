#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", p->fst, p->snd);
}

int main(void) {
    pair_t p, q, r;
    //pair_t r = NULL;
    // Nuevo par p
    p = pair_new(3, 4);
    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);
    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);
    // Se muestra q
    printf("q = ");
    show_pair(q);

    // quiero crear un par sin usar pair_new
    r->fst = 40;
    r->snd = 50;
    printf("r = ");
    show_pair(r);

    // Se destruyen p y q
    p = pair_destroy(p);
    q = pair_destroy(q);
    //r = pair_destroy(r);
    return EXIT_SUCCESS;
}

/**
 * 1. Acceso Restringido: cumple ya que las implementaciones están en el archvio pair.c
 * 2. Interfaz Clara: el archivo .h proporciona la interfaz adecuada.
 * 3. Modularidad: Cualquier cambio en pair.c no debería afectar a otros módulos. Cumple.
 * Aún así se pueden modificar el estado del pair_t sin usar funciones provistas en la
 * interfaz pública. Por ende no es totalmente encapsulado.
 * **/
