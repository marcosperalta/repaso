#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t par = {x,y};
    assert(par.fst == x && par.snd == y);
    return par;
}

int pair_first(pair_t p) {
    int fst = p.fst;
    assert(fst == p.fst);
    return fst;
}

int pair_second(pair_t p) {
    int snd = p.snd;
    assert(snd == p.snd);
    return snd;
}

pair_t pair_swapped(pair_t p) {
    int fst = p.fst, snd = p.snd;
    pair_t q = {snd, fst};
    assert(q.fst == p.snd && q.snd == p.fst);
    return q;
}

pair_t pair_destroy(pair_t p) {
    return p;
}

