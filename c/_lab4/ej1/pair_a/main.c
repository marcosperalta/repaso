#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", p.fst, p.snd);
}

int main(void) {
    pair_t p, q, r;
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
    r.fst = 10;
    r.snd = 20;
    printf("r = ");
    show_pair(r);

    // Se destruyen p y q
    p = pair_destroy(p);
    q = pair_destroy(q);
    return EXIT_SUCCESS;
}

/**
 * Encapsulamiento: Sí: Interfaz pública bien definida y ocutación de implementación.
 *                  No: Acceso directo a los miembros de la estructura: ya que está 
 *                      definida como una estructura directa y no como puntero a una
 *                      estructura. Por ejemplo: r.fst = 10;
 *                                               r.snd = 20;
 *                                               printf("r = ");
 *                                               show_pair(r);
 * 
 *  Este acceso viola el principio de encapsulamiento ya que permite modificar el estado
 * de pair_t sin usar las funciones definidad en la Interfaz pública.
 * **/
