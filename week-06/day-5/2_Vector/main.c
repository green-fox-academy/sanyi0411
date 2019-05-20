#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vector;
    int size;
} vector_t;

vector_t *create_vector(int value);

void insert_end(vector_t *input, int value);

void insert_at_index(vector_t *input, int value, int index);

void print_vector(vector_t *input);

int main()
{
    vector_t *myVector = create_vector(7);

    insert_end(myVector, 11);

    insert_at_index(myVector, 3, 0);

    insert_at_index(myVector, 5, 1);

    print_vector(myVector);

    return 0;
}

vector_t *create_vector(int value)
{
    vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

    int *pointer = (int *)malloc(sizeof(int));

    vector->vector = pointer;

    vector->vector[0] = value;

    vector->size = 1;

    return vector;
}

void print_vector(vector_t *input)
{
    for (int i = 0; i < input->size; ++i) {
        printf("%d\n", input->vector[i]);
    }
}

void insert_end(vector_t *input, int value)
{
    input->vector = (int *)realloc(input->vector, input->size + 1);
    input->size += 1;
    input->vector[input->size - 1] = value;
}

void insert_at_index(vector_t *input, int value, int index)
{
    input->vector = (int *)realloc(input->vector, input->size + 1);
    input->size += 1;
    for (int i = input->size - 2; i >= index; --i) {
        input->vector[i + 1] = input->vector[i];
    }
    input->vector[index] = value;
}