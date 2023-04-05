//
// Created by 1 on 05.04.2023.
//
#include "vector.h"

vector createVector(size_t n) {
    vector v;
    v.capacity = MAX(10, n);
    v.size = n;
    v.data = malloc(sizeof(int) * v.capacity);

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserve(vector *v, size_t newCapacity) {
    if(newCapacity == 0){
        free(v->data);
        *v = (vector){
            NULL, 0, 0
        };
        return;
    }

    int newData = realloc( v->data,sizeof(int) * newCapacity);

    if(newData == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if(v->data != newData) {
        memcpy(newData, v->data, sizeof(int) * v->size);
        free(v->data);
        v->data = newData;
    }

    v->capacity = newCapacity;

    if(v->size > v->capacity)
        v->size = v->capacity;
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    v->capacity = v->size;
    v->data = realloc(v->data, sizeof(int) * v->capacity);
}

void deleteVector(vector *v){
    v->capacity = 0;
    v->size = 0;
    free(v->data);
    v->data = NULL;
}