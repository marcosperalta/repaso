/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
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

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    int i = 0;
    FILE *pfile; // declaro variable de tipo FILE
    pfile = fopen(filepath, "r"); // abro el archivo de solo lectura
    if ((pfile) == NULL) {  // verifico que se haya podido abrir
        printf("\nNo se pudo abrir el archivo");
    } else {
        printf("\nArchivo abierto\n");
        fscanf(pfile, "%d", &max_size); // guardo el primer elemento del stream que es el tamaño del arreglo
        printf("\nEl tamaño del array es: %d\n", max_size); 
        while (i < max_size && fscanf(pfile, "%d", &array[i]) == 1) // guardo todos los elementos del stream en el array
        {
            //printf("\nEl valor es: %d\n", array[i]); 
            i++;
        }
    }
    fclose(pfile);
    return max_size;
}

void array_dump(int a[], unsigned int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }
}

unsigned int array_from_stdin(int array[]) {
    unsigned int length = 0;
    const char * newFilePath = "input/archivoNuevo.in";
    
    printf("\nIntroduzca el tamaño del arreglo: "); // hago q el usuario eliga un tamaño de arreglo nuevo
    scanf("%u", &length);
    printf("\nEl tamaño del arreglo es: %u\n", length);

    FILE *pfile = fopen(newFilePath, "w"); // crea un puntero de tipo FILE, crea el archivo de tipo escritura
    if (pfile == NULL) { printf("\nNo se pudo abrir el archivo"); return 0;}
    printf("\nArchivo nuevo creado!\n");
    fprintf(pfile, "%d\n", length); //imprime en el archivo el largo del arreglo

    // tomar de stdin o teclado los valores del arreglo para guardarlos en el archivo creado
    for (int i = 0; i < length; i++)
    {
        printf("\nIngrese el valor: ");
        scanf("%d", &array[i]);
        
        fprintf(pfile, "%d ", array[i]);
        printf("\nEl valor ingresado es: %d\n", array[i]);
    }
    fclose(pfile);

    length = array_from_file(array, length, newFilePath);

    return length;
}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*dumping the array*/
    array_dump(array, length);

    length = array_from_stdin(array);
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
