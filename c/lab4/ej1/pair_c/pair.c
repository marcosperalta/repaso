#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y) {
    pair_t par = NULL;
    par = (pair_t)malloc(sizeof(struct s_pair_t));
    assert(par != NULL);
    par->fst = x;
    par->snd = y;
    return (par);
}

int pair_first(pair_t p) {
    assert(p != NULL);
    return p->fst;
}

int pair_second(pair_t p) {
    assert(p != NULL);
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t q = pair_new(p->snd, p->fst);
    assert(q != NULL);
    assert(q->fst == p->snd && q->snd == p->fst);
    return q;
}

pair_t pair_destroy(pair_t p) {
    assert(p != NULL);
    free(p);
    p = NULL;
    return p;
}
