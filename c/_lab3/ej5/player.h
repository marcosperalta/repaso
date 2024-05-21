/*
  @file player.h
  @brief Player structure definition
*/
#ifndef _PLAYER_H
#define _PLAYER_H
#define MAX_NAME_LENGTH 100u
#define MAX_COUNTRY_LENGTH 3u 

/** @brief structure used to represent a tennis player position in ranking  */
typedef struct _player_t {
    char name[100];
    char country[4];
    unsigned int rank;
    unsigned int age;
    unsigned int points;
    unsigned int tournaments;
} * player_t; // NOTE! player_t is an alias of struct _player_t *

// cpu time con punteros 0.02 seconds y sin punteros 0.07 seconds, es decir 3,5x veces.
// ¿Funciona más rápido la versión con punteros? ¿Por qué son más eficientes los intercambios con esta versión?
// Si, claramente. Los swaps son más eficientes ya que solo intercambian direcciones de memoria y
// no copian el contenido de la estructura o la estructura en sí.

#endif //_PLAYER_H
