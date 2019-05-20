#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    vector_t *myVector = create_vector(11);

    push_back(myVector, 11);

    insert_at_index(myVector, 11, 0);

    insert_at_index(myVector, 5, 1);

    push_back(myVector, 13);
    push_back(myVector, 11);
    push_back(myVector, 5);
    push_back(myVector, 7);

    unique(myVector);
    
    print_vector(myVector);

    return 0;
}
