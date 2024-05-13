/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array */
// static indica que no puede accederse desde otro archivo mediante 'extern'
// const que es inmutable
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

// declara funcion que retorna un 'char *'. Tiene como argumento 'argc' que indica la cantidad de argumentos guardados en el vector argv (vector de argumentos)
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL; // inicializa un puntero tipo 'char *'

    if (argc < 2) { // chequea que la cantidad de argumentos sea 2 o más
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1]; // asigna el argumento de esa posición a result para retornarla

    return result; // retorna el filepath que esta en argv[1], que se dió como argumento a la hora de iniciar la aplicación
}

int main(int argc, char *argv[]) {
  char *filepath = NULL;
  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);
  /* create an array of MAX_SIZE elements */
  int array[MAX_SIZE];
  /* parse the file to fill the array and obtain the actual length */
  unsigned int length = array_from_file(array, MAX_SIZE, filepath);
  /* create a copy of the array, to do some checks later */
  int copy[MAX_SIZE];
  array_copy(copy, array, length);

  array_dump(array, length);

  array_is_sorted_marcos(array, length);

  /* do the actual sorting */
  insertion_sort(array, length);

  /* show the ordered array in the screen */
  array_dump(array, length);

  /* check if it is sorted */
  array_is_sorted_marcos(array, length);

  //assert(array_is_sorted(array, length));

  /* check if it is a permutation of original */
  assert(array_is_permutation_of(copy, array, length));
  return EXIT_SUCCESS;
}

/* Nota: se definió una relación de orden no convencional en el goes_before. En mi caso lo hago sin el goes_before */
