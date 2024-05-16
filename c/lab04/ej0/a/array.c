#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 7

static void
print_array(int a[], size_t length) {
    assert(length > 0);
    printf("[ %d", a[0]); // imprime el primer elemento
    for (size_t i=1; i<length; i++) {
        printf(", %d", a[i]); // imprime los demás elementos con la , adelante
    }
    printf("]\n"); // imprime el cierre del arreglo
}

int main(void) {  // inicializa el array en 0's
    int array[ARRAY_SIZE]={7, 4, 1, 3, 9, 3, 5};
    int *p=NULL; // declara variable de tipo puntero
    printf("before: ");
    print_array(array, ARRAY_SIZE);
    /* --------------------- Modificar ---------------------- */
    for (unsigned int i=0u; i < ARRAY_SIZE; i++) {
        // p = &array[i];
        // *p = 0;
        p = array; // array es el puntero, es la dirección de array
        p[i] = 0; // uso indexación de punteros para ir asignando 0's
    }
    /* ------------------------------------------------------ */
    // Tienen la misma dirección de memoria obviamente!
    printf("\narray : %p\n", (void *) array);
    printf("    p : %p\n\n", (void *) p);

    printf("after : ");
    print_array(array, ARRAY_SIZE);

    return EXIT_SUCCESS;
}

