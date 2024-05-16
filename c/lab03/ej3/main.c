/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

  int x = 1;

  person_t m = {90, 'M'};
  int a[] = {0, 1, 2, 3};

  /* Completar aquí:
      Al finalizar la ejecución las variables deben tener los siguientes valores
      x = 9
      m = (100, F)
      a[1] = 42

      Las restricciones son:
      - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
      - Se pueden agregar líneas de código, pero no modificar las que ya existen.
      - Se pueden declarar hasta 2 punteros.
      AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
  */

  int *ptr = &x;
  *ptr = 9;
  // printf(" &x = %p\n", (void*) &x);
  // printf("ptr = %p\n", (void*)ptr);

  ptr = &m.age;
  *ptr = 100;

  char *ptr2 = &m.name_initial;
  *ptr2 = 'F';

  ptr = &a[1];
  *ptr = 42;

  // ptr = a;
  // *(ptr+1) = 42;

  printf("\n\nx = %d\n", x);
  printf("m = (%d, %c)\n", m.age, m.name_initial);
  printf("a[0] = %d\n", a[0]);
  printf("a[1] = %d\n", a[1]);
  printf("a[2] = %d\n", a[2]);
  printf("a[3] = %d\n", a[3]);
}
