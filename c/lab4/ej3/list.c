#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct _node_t {
    list_elem elem;
    struct _node_t * next;
};

