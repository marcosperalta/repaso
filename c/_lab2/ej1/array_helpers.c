#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool array_is_sorted_marcos(int a[], unsigned int length) {
    if (length == 0) {
        printf("\nEl arreglo está vacío\n\n");
        return true;
    }
    for (unsigned int i = 0; i < length-1; i++) {
        if (a[i] > a[i+1]) {
            printf("\nEl arreglo no está ordenado\n");
            return false;
        }
    }
    printf("\nEl arreglo está ordenado\n\n");
    return true;
}

// procedimiento que genera una copia del arreglo
void array_copy(int copy[], int array[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        copy[i] = array[i];
    }
}

// dado un valor, cuenta cuantas veces aparece en un arreglo
unsigned int array_value_count(int a[], unsigned int length, int value) {
    unsigned int count = 0u;
    for (unsigned int i = 0u; i < length; ++i) {
        if (a[i] == value) {
            ++count;
        }
    }
    return count;
}

void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "\n%u\n", length); // imprime en pantalla el tamaño del arreglo utilizando stdout
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%i", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
    fprintf(stdout, "\n");
}

// chequea si dados 2 arreglos tienen los mismos elementos, contando que tengan la misma cantidad de elementos
bool array_is_permutation_of(int a[], int b[], unsigned int length) {
    unsigned int i = 0u;
    bool result = true;
    while (i < length && result) { // ciclo que tiene como guarda el largo de los arreglos, y result que si en algún punto es falso corta el ciclo
        unsigned int a_count = array_value_count(a, length, a[i]);
        unsigned int b_count = array_value_count(b, length, a[i]);
        result = (a_count == b_count);
        i++;
    }
    return result;
}

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    FILE *file = NULL; // crea el puntero file
    file = fopen(filepath, "r"); // abre archivo en modo lectura con formato
    if (file == NULL) { // chequea que el archivo exista sino lo maneja como error
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u; // inicializa un iterador
    unsigned int size = 0u; // inicializa el tamaño del arreglo
    int res = 0; // inicializa variable para controlar el resultado los elementos leidos del archivo
    res = fscanf(file, " %u ", &size); // guarda en size el tamaño del archivo, y en res el nº de elementos leídos
    if (res != 1) { // chequea si el nº de elementos leídos es != 1, y actua en consecuencia
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    if (size > max_size) { // chequea que el size quepa en el tamaño predefinido max_size
        fprintf(stderr, "Allowed size is %d.\n", max_size);
        exit(EXIT_FAILURE);
    }
    while (i < size) { // ciclo while que corta en el largo del arreglo
        res = fscanf(file," %d ", &(array[i])); // comienza a guardar los elementos restantes del archivo, es decir, los elementos del arreglo
        if (res != 1) { // chequea que el elemento leido en cada iteración sea lo espeficicado en el fscanf, o sea, 1
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
       ++i; // next cicle
    }
    fclose(file); // cierra el file
    return size; // retorna el tamaño del arreglo 
}
