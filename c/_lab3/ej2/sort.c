/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

typedef unsigned int uint;

void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

bool goes_before(player_t x, player_t y) {
    return strcmp(x.name, y.name) < 0;
}

bool array_is_sorted(player_t atp[], uint length) {
    uint i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], uint length) {
    quick_sort(a, length);
}

/* name country ranking age score tournaments_played */
//////////////////////////////////QUICK SORT/////////////////////////////////////////////

static unsigned int partition(player_t a[], uint izq, uint der) {
    uint i = izq+1;
    uint j = der;
    uint ppiv = izq;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i++;
        } else if (goes_before(a[ppiv], a[j])) {
            j--;
        } else if (goes_before(a[ppiv], a[i]) && goes_before(a[j], a[ppiv])) {
            swap(a, i, j); // este if prodria ser solamente else
        } // Nota: notar que en el if solo se cumple 1 y solo 1 de las 3 opciones
    }
    swap(a, ppiv, j);
    ppiv = j;
    return ppiv;
}

static void quick_sort_rec(player_t a[], uint izq, uint der) {
    uint ppiv = 0u;
    if (izq < der)
    {
        ppiv = partition(a, izq, der);
        if (ppiv > 0) {
            quick_sort_rec(a, izq, ppiv-1);
        }
        quick_sort_rec(a, ppiv+1, der);
    }
}

void quick_sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
