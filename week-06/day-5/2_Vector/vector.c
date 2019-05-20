//
// Created by sando on 2019. 05. 20..
//

#include "vector.h"

vector_t *create_vector(int value)
{
    vector_t *vector = (vector_t *) malloc(sizeof(vector_t));

    int *pointer = (int *) malloc(sizeof(int));

    vector->vector = pointer;

    vector->vector[0] = value;

    vector->size = 1;

    return vector;
}

void push_back(vector_t *input, int value)
{
    input->vector = (int *) realloc(input->vector, (input->size + 1) * sizeof(int));
    input->size += 1;
    input->vector[input->size - 1] = value;
}

void pop_back(vector_t *input)
{
    input->size -= 1;
    input->vector = (int *) realloc(input->vector, input->size * sizeof(int));
}

void insert_at_index(vector_t *input, int value, int index)
{
    input->vector = (int *) realloc(input->vector, (input->size + 1) * sizeof(int));
    input->size += 1;
    for (int i = input->size - 2; i >= index; --i) {
        input->vector[i + 1] = input->vector[i];
    }
    input->vector[index] = value;
}

void delete_by_index(vector_t *input, int index)
{
    for (int i = index + 1; i < input->size; ++i) {
        input->vector[i - 1] = input->vector[i];
    }
    input->size -= 1;
    input->vector = (int *) realloc(input->vector, input->size * sizeof(int));
}

int vector_size(vector_t *input)
{
    return input->size;
}

void print_vector(vector_t *input)
{
    for (int i = 0; i < input->size; ++i) {
        printf("%d\n", input->vector[i]);
    }
}

int search_vector(vector_t *input, int value)
{
    for (int i = 0; i < input->size; ++i) {
        if (input->vector[i] == value) {
            return i;
        }
    }
    return -1;
}