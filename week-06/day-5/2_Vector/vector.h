//
// Created by sando on 2019. 05. 20..
//

#ifndef INC_2_VECTOR_VECTOR_H
#define INC_2_VECTOR_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vector;
    int size;
} vector_t;

vector_t *create_vector(int value);

void push_back(vector_t *input, int value);

void pop_back(vector_t *input);

void insert_at_index(vector_t *input, int value, int index);

void delete_by_index(vector_t *input, int index);

int search_vector(vector_t *input, int value);

int vector_size(vector_t *input);

void bubble_sort(vector_t *input);

void unique(vector_t *input);

void print_vector(vector_t *input);

#endif //INC_2_VECTOR_VECTOR_H
