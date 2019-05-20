#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    vector_t *myVector = create_vector(7);

    push_back(myVector, 11);

    insert_at_index(myVector, 3, 0);

    insert_at_index(myVector, 5, 1);

    push_back(myVector, 13);

    delete_by_index(myVector, 2);

    print_vector(myVector);

    printf("%d\n", search_vector(myVector, 10));

    return 0;
}
