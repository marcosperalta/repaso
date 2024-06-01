#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

// es correcta tambien esta implementación,
// solo que la otra agrega 1 nivel más de indirección
// typedef struct _node_t * list;
// typedef int list_elem;

typedef struct _list_t * list;
typedef int list_elem;

// CONSTRUCTORS
list empty(void);
/* crea una lista vacía */

list addl(list l, list_elem e);
/* agrega el elemento e al cominezo de la lista l */

// OPERATIONS
bool is_empty(list l);
/* retorna true si l es vacía */

list_elem head(list l);
/* PRE: !is_empty(l) - retorna el primer elemento de la lista l */

list tail(list l);
/* PRE: !is_empty() - elimina el primer elemento de la lista l */

list addr(list l, list_elem e);
/* agrega el elemento e al final de la lista l */

unsigned int length(list l);
/* rotorna la cantidad de elementos de la lista l */

list concat(list l1, list l2);
/* concatena ambas listas en ese orden l1 ++ l2 */

list_elem index_list(list l, unsigned int n);
/* PRE: length(l) > 0 - retorna el n-ésimo elemento de la lista l */

list take(list l, unsigned int n);
/* deja en l solo los n primeros elementos, eliminando el resto */

list drop(list l, unsigned int n);
/* elimina los primeros n elementos de l */

list copy_list(list l);
/* copia todos los elementos de l1 en una nueva lista l2 retornándola */

// DESTROY
list destroy(list l);
/* libera la memoria en caso de ser necesario */

#endif // LIST_H
