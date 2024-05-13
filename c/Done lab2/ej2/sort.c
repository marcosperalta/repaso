#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


/* static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = 0u;
    if (izq < der)
    {
        ppiv = partition(a, izq, der);
        if (ppiv > 0)
        {
            quick_sort_rec(a, izq, ppiv-1);
        }
        quick_sort_rec(a, ppiv+1, der);
    }
    
} */

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int ppiv = partition(a, izq, der);
        if (ppiv < der) {
            quick_sort_rec(a, ppiv+1, der); // ordeno la parte (ppiv, der]
        }
        if (ppiv > izq) { // guarda garantiza que ppiv va ser más grande que izq por ende mayor de 0
            quick_sort_rec(a, izq, ppiv-1); // ordeno la parte [izq, ppiv)
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

