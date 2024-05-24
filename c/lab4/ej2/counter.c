#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
    //bool b;
};

counter counter_init(void) {
    counter c = NULL;
    c = (counter)malloc(sizeof(struct _counter));
    assert(c != NULL);
    c->count = 0;
    //c->b = true;
    return c;
}

void counter_inc(counter c) {
    assert(c != NULL);
    c->count++;
}

bool counter_is_init(counter c) {
    if (c->count == 0) {
        return true;
    }
    return false;
}

void counter_dec(counter c) {
    assert(c != NULL);
    assert(!counter_is_init(c));
    c->count--;
}

counter counter_copy(counter c) {
    counter d = counter_init();
    assert(d != NULL);
    d->count = c->count;
    return d;
}

void counter_destroy(counter c) {
    assert(c != NULL);
    free(c);
    c = NULL;
}
