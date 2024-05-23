#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
    bool b;
};

counter counter_init(void) {
    counter c = NULL;
    c = (counter)malloc(sizeof(struct _counter));
    assert(c != NULL);
    c->count = 0;
    c->b = true;
    return c;
}

void counter_inc(counter c) {
    assert(c != NULL);
    c->count++;
    return c;
}

bool counter_is_init(counter c) {
    return c->b;
}

void counter_dec(counter c) {
    assert(c != NULL);
    assert(!counter_is_init(c));
    c->count--;
    return c;
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
