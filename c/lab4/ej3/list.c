#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    return (l->head->elem);
}

/* PRE: !is_empty() - elimina el primer elemento de la lista l */
list tail(list l) {
    if (is_empty(l)) {
        return l;
    }
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
    while (head != NULL) {
        cardinal +=1;
        head = head->next;
    }
    return cardinal;
}

/* concatena ambas listas en ese orden l1 ++ l2 */
list concat(list l1, list l2) {
    node_t * aux1 = l1->head;
    node_t * aux2 = l2->head;
    list l3 = empty();
    node_t * aux3 = l3->head;
    if (is_empty(l1) && is_empty(l2)) {
        return l3;
    } else if (is_empty(l1)) {
        l3 = copy_list(l2);
        return l3;
    } else if (is_empty(l2)) {
        l3 = copy_list(l1);
        return l3;
    }
    node_t * node1 = new_node();
    node1->elem = aux1->elem;
    l3->head = node1;
    aux3 = node1;
    while (aux1->next != NULL) {
        node_t * node = new_node();
        node->elem = aux1->next->elem;
        aux3->next = node;
        aux3 = aux3->next;
        aux1 = aux1->next;
    }
    node_t * node2 = new_node();
    node2->elem = aux2->elem;
    aux3->next = node2;
    aux3 = aux3->next;
    while (aux2->next != NULL) {
        node_t * node = new_node();
        node->elem = aux2->next->elem;
        aux3->next = node;
        aux3 = aux3->next;
        aux2 = aux2->next;
    }
    aux3->next = NULL;
return l3;
}

/* PRE: length(l) > 0 - retorna el n-ésimo elemento de la lista l */
list_elem index_list(list l, unsigned int n) {
    if (is_empty(l)) {
        return UINT_MAX;
    }
    if (n > length(l)) {
        return UINT_MAX;
    }
    unsigned int i = n;
    node_t * aux = l->head;
    while (aux != NULL && i > 0 ) {
        aux = aux->next;
        i--;
    }
    if (i!=0)
        printf("ERROR: L128-LIST.C");
    return aux->elem;
}

/* elimina los primeros n elementos de l */
list drop(list l, unsigned int n) {
    if (is_empty(l)) {
        return l;
    }
    if (n >= length(l)) {
        destroy(l);
        list l2 = empty();
        return l2;
    }
    unsigned int i = n-1;
    node_t * aux = l->head;
    while (aux != NULL && i > 0) {
        aux = aux->next;
        i--;
    }
    node_t * aux2 = aux->next;
    aux->next = NULL;
    aux = l->head;
    while (aux!= NULL) {
        aux = aux->next;
        free(l->head);
        l->head = aux;
    }
    l->head = aux2;
    return l;
}

/* deja los n primeros elementos, eliminando el resto */
list take(list l, unsigned int n) {
    if (is_empty(l)) {
        return l;
    }
    if (n >= length(l)) {
        return l;
    }
    unsigned int i = n-1;
    node_t * aux = l->head;
    while (aux != NULL && i > 0) {
        aux = aux->next;
        i--;
    }
    node_t * aux2 = aux->next;
    aux->next = NULL;
    aux = aux2;
    while (aux != NULL) {
        aux2 = aux2->next;
        free(aux);
        aux = aux2;
    }
    return l;
}

/* copia todos los elementos de l en una nueva lista l2 retornándola */
list copy_list(list l) {
    list l2 = empty();
    if (!is_empty(l)) {
        node_t * aux = l->head->next;
        node_t * node = new_node();
        node->elem = l->head->elem;
        l2->head = node;
        while (aux != NULL) {
            node_t * node2 = new_node();
            node2->elem = aux->elem;
            node->next = node2;
            node = node2;
            aux = aux->next;
        }
        node->next = NULL;
    }
    return l2;
}

/* libera la memoria en caso de ser necesario */
void destroy(list l) {
    if (!is_empty(l)) {
        node_t * aux;
        while (l->head != NULL) {
            aux = l->head;
            l->head = l->head->next;
            free(aux);
        }
    }
    free(l);
}

