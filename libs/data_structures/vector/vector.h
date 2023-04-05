#ifndef LAB14OP_VECTOR_H
#define LAB14OP_VECTOR_H

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "stdbool.h"
#include "assert.h"
#include "vector.h"

#define MAX(a, b) ((a > b)?(a):(b))
#define MIN(a, b) ((a < b)?(a):(b))

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);
void reserve(vector *v, size_t newCapacity);
void clear(vector *v);
void shrinkToFit(vector *v);
void deleteVector(vector *v);
bool isEmpty(vector *v);
bool isFull(vector *v);
int getVectorValue(vector *v, size_t i);
void pushBack(vector *v, int x);
void test_pushBack_emptyVector();
void test_pushBack_fullVector();
void popBack(vector *v);
void popBack(vector *v);
void test_popBack_notEmptyVector();
int* atVector(vector *v, size_t index);
int* back(vector *v);
int* front(vector *v);
void test_atVector_notEmptyVector();
void test_atVector_requestToLastElement();
void test_back_oneElementInVector();
void test_front_oneElementInVector();

#endif //LAB14OP_VECTOR_H