//
// Created by 1 on 05.04.2023.
//
#include "vector.h"

vector createVector(size_t n) {
    vector v;
    v.capacity = MAX(1, n);
    v.size = 0;
    v.data = malloc(sizeof(int) * v.capacity);

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {
            v.data, v.size, v.capacity
    };
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        *v = (vector) {
                NULL, 0, 0
        };
        return;
    }

    int *newData = realloc(v->data, sizeof(int) * newCapacity);

    if (newData == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if (v->data != newData) {
        memcpy(newData, v->data, sizeof(int) * v->size);
        free(v->data);
        v->data = newData;
    }

    v->capacity = newCapacity;

    if (v->size > v->capacity)
        v->size = v->capacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
    v->data = realloc(v->data, sizeof(int) * v->capacity);
}

void deleteVector(vector *v) {
    v->capacity = 0;
    v->size = 0;
    free(v->data);
    v->data = NULL;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    v->size++;
    if (v->size > v->capacity) {
        reserve(v, v->capacity * 2);
    }

    v->data[v->size - 1] = x;
}

void test_pushBack_emptyVector() {
    vector v = createVector(1);
    pushBack(&v, 3);
    assert(getVectorValue(&v, 0) == 3);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_pushBack_fullVector(){
    vector v = createVector(1);
    pushBack(&v, 3);
    pushBack(&v, 4);
    assert(getVectorValue(&v, 1) == 4);
    assert(v.capacity == 2);
    assert(v.size == 2);
}

void popBack(vector *v){
    if(v->size == 0){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->size--;
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

