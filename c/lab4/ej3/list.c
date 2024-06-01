#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// typedef struct _node_t {
//     list_elem elem;
//     struct _node_t * next;
// } node_t;

// esqueleto para instancia de:
typedef struct _node_t {
    list_elem elem;
    struct _node_t * next;
} node_t;

// esqueleto para instancia de:
struct _list_t {
    struct _node_t * head;    
};

/* crea una lista vacía */
list empty(void) {
    list l = malloc(sizeof(struct _list_t));
    l->head = NULL;
    return l;
}

static node_t * new_node(void) {
    node_t * node = (node_t *)malloc(sizeof(struct _node_t));
    return node;
}

/* agrega el elemento e al cominezo de la lista l */
list addl(list l, list_elem e) {
    node_t * node = new_node();
    node->elem = e;
    node->next = l->head;
    l->head = node;
    return l;
}

/* retorna true si l es vacía */
bool is_empty(list l) {
    return (l->head == NULL);
}

/* PRE: !is_empty(l) - retorna el primer elemento de la lista l */
list_elem head(list l) {
    assert(!is_empty(l));
    printf("\nELEM: %i", l->head->elem);
    return (l->head->elem);
}

/* PRE: !is_empty() - elimina el primer elemento de la lista l */
list tail(list l) {
    assert(!is_empty(l));
    node_t * aux = l->head;
    l->head = l->head->next;
    free(aux);
    return l;
}

/* agrega el elemento e al final de la lista l */
/* cambiar en caso de agregar tail al struct */
list addr(list l, list_elem e) {
    node_t * aux = l->head;
    node_t * node = new_node();
    node->elem = e;
    node->next = NULL;
    if (is_empty(l)) {
        l->head = node;
    } else {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    }
    return l;
}

/* rotorna la cantidad de elementos de la lista l */
unsigned int length(list l) {
    unsigned int cardinal = 0;
    node_t * head = l->head; 
    if (is_empty(l)) {
        return cardinal;
    }
    while (head->next != NULL) {
        cardinal +=1;
        head = head->next;
    }
    return cardinal +=1;
}

/* concatena ambas listas en ese orden l1 ++ l2 */
list concat(list l1, list l2) {
    node_t * aux = l1->head;
    if (is_empty(l1)) {
        return l2;
    } else if (is_empty(l2)) {
        return l1;
    } else {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = l2->head;
    }
    return l1;
}


list_elem index_list(list l, unsigned int n);
/* PRE: length(l) > 0 - retorna el n-ésimo elemento de la lista l */

list take(list l, unsigned int n);
/* deja en l solo los n primeros elementos, eliminando el resto */

list drop(list l, unsigned int n);
/* elimina los primeros n elementos de l */

/* copia todos los elementos de l en una nueva lista l2 retornándola */
list copy_list(list l) {
    list l2 = empty();
    if (!is_empty(l)) {

        node_t * aux = l->head->next;
        node_t * node = new_node();
        node->elem = l->head->elem;
        l2->head = node;

        while (aux != NULL) {
            // printf("ELEMENTO aux: %d\n", aux->elem);
            // printf("ELEMENTO node: %d\n", node->elem);
            node_t * node2 = new_node();
            node2->elem = aux->elem; // intercabiado
            node->next = node2;
            node = node2;
            aux = aux->next;
        }
        node->next = NULL;
    }
    return l2;
}

/* libera la memoria en caso de ser necesario */
list destroy(list l) {
    if (!is_empty(l)) {
        node_t * aux = l->head;
        while (l->head != NULL) {
            l->head = l->head->next;
            free(aux);
            aux = l->head;
        }

    }
    free(l);
    return l;
}

