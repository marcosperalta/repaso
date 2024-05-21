#ifndef _DATA_H_
#define _DATA_H_

#define NAME_SIZE 30

typedef char name_t [NAME_SIZE];

// Estructura 'struct _s_data cuyo alias es data_t
        typedef struct _s_data {
            name_t name;
            unsigned int age;
            unsigned int height;
        } data_t;
// 1 campo name, char[30] y 2 campos uint, age y height

#endif

