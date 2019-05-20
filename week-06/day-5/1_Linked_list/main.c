#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    linked_list_t *head = create_linked_list();

    insert_end(head, 62);

    insert_front(head, 93);

    insert_at_index(head, 36, 2);

    insert_at_index(head, 18, 1);

    insert_end(head, 55);

    insert_at_index(head, 72, 3);

    printf("%d\n", search_by_value(head, 72)->next->data);

    print_list(head);

    if(!is_empty(head)) {
        printf("The size of the list is:%d", size_of_list(head));
    } else {
        printf("The list is empty");
    }

    return 0;
}
