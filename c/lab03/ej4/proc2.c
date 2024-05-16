#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x <= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a = 0, res = -98;
    absolute(a, &res);
    printf("\nabosolute(a,res) = %d\n\n", res);
    return EXIT_SUCCESS;
}

