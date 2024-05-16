#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

#include "array_helpers.h"
#include <stdio.h>
#include <stdbool.h>

bool isFileNull(FILE *p) {
    return (p == NULL);
}

unsigned int array_from_file(int array[],
                    unsigned int max_size,
                    const char *filepath) {
    
    FILE *fp; // defino un puntero a la estructura FILE
    // fopen retorna un puntero del area de buffer. Abre un archivo de solo lectura
    if (isFileNull(fp = fopen(filepath, "r"))) {
        printf("\nNo se pudo abrir el archivo\n");
    } else {
        int i = 0;
        while (fscanf(fp, "%d", &array[i]) != EOF) {
            i++;
        }
    }
    fclose(fp);
    
    max_size = array[0]; // Guardo en la primera posición del array el size del mismo
    return max_size;
}

void array_dump(int a[], unsigned int length) {    
    printf("\n[ ");
    if (length > 0) {
        printf("%d", a[1]);
        for (unsigned int i = 1; i < length; i++) {
            printf(", %d", a[i+1]);
        }
        printf("]\n");
    }
}

bool array_is_sorted(int a[], unsigned int length) {
    leng
     
}

#endif
