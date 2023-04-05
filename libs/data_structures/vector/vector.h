#ifndef LAB14OP_VECTOR_H
#define LAB14OP_VECTOR_H

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "stdbool.h"
#include "assert.h"

#define MAX(a, b) ((a > b)?(a):(b))
#define MIN(a, b) ((a < b)?(a):(b))

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;


#endif //LAB14OP_VECTOR_H