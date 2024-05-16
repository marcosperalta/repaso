#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* chequear solo esta parte del invariante:
el segmento inicial a[1,i) del arreglo está ordenado */


static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while (j > 0 && a[j] < a[j-1]) {
        swap(a, j, j-1);
        j--;
    }
}

/* static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while (j > 0 && goes_before(a[j], a[j-1])) {

        swap(a, j-1, j);
        j--;
    }
} */

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
            insert(a, i);
    }
}
