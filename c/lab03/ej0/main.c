#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL; // inicializa un puntero tipo 'char *'

    if (argc < 2) { // chequea que la cantidad de argumentos sea 2 o más
        //print_help(argv[0]);
        printf("mal llamado el archivo\n");
        exit(EXIT_FAILURE);
    }

    result = argv[1]; // asigna el argumento de esa posición a result para retornarla

    return result; // retorna el filepath que esta en argv[1], que se dió como argumento a la hora de iniciar la aplicación
}

unsigned int data_from_file(const char *path,
unsigned int indexes[], char letters[], unsigned int max_size) {
    unsigned int length = 0;
    FILE *pfile = fopen(path, "r");
    if (pfile == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }
    length = max_size;
    printf("Se pudo abrir el archivo!\n");
    unsigned int i = 0;
    while (!feof(pfile)) {
        fscanf(pfile, "%u %c", &indexes[i], &letters[i]);
        i++;
    }
    fclose(pfile);
    printf("\nlength: %u", length);
    length = i;
    return length;
}

int main(int argc, char *argv[]) {
    //FILE *file;
    
    char *path = parse_filepath(argc, argv);
    
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    //char sorted[MAX_SIZE];
    unsigned int length=0; 
   
    length = data_from_file(path, indexes, letters, MAX_SIZE);
    printf("\nlength: %u\n", length);
    //dump((char*)indexes, length);
    dump(letters, length);
    //dump(sorted, length);

    return EXIT_SUCCESS;
}

