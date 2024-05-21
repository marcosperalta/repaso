#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */
#include <assert.h>   /* assert()          */

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    //array = array;
    struct max_min_result result = { 0, 0, 0, 0 };
    result.max_value = array[0];
    result.min_value = array[0];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (result.max_value < array[i]) {
            result.max_value = array[i];
            result.max_position = i;
        } else if (result.min_value > array[i]) {
            result.min_value = array[i];
            result.min_position = i;    
        }
    }
    return result;
}

int main(void)
{
    int array[ARRAY_SIZE] = { 4, -1, 5, 8, 9, 0, 3, 6, 0, 0 };
    int aux = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("\n Ingrese los valores del arreglo: ");
        scanf("%d", &aux);
        array[i] = aux;
        printf("\n El número %d se ha guardado en el arreglo.\n", aux);
    }
    
    printf("\narray = {");
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        if (i == ARRAY_SIZE-1) {
            printf("%d}\n", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("\nMáximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n\n", result.min_position);
    return 0;
}

