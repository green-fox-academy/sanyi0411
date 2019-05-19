#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_t {
    int data;
    struct linked_list_t *next;
} linked_list_t;

linked_list_t *create_linked_list();

void insert_end(linked_list_t *head, int data);

void insert_front(linked_list_t *head, int data);

void insert_at_index(linked_list_t *head, int data, int index);

int size_of_list(linked_list_t *head);

void print_list(linked_list_t *head);

int is_empty(linked_list_t *head);

void delete_at_index(linked_list_t *head, int index);

int delete_by_value(linked_list_t *head, int value);

int main()
{
    linked_list_t *head = create_linked_list();

    insert_end(head, 62);

    insert_front(head, 93);

    insert_at_index(head, 36, 2);

    insert_at_index(head, 18, 1);

    insert_end(head, 55);

    insert_at_index(head, 72, 3);

    printf("We deleted %d node(s)\n", delete_by_value(head, 55));
    print_list(head);

    if(!is_empty(head)) {
        printf("The size of the list is:%d", size_of_list(head));
    } else {
        printf("The list is empty");
    }

    return 0;
}

linked_list_t *create_linked_list()
{
    linked_list_t *head = (linked_list_t *) malloc(sizeof(linked_list_t));
    head->data = 0;
    head->next = NULL;
    return head;
}

void insert_end(linked_list_t *head, int data)
{
    linked_list_t *newNode = (linked_list_t *) malloc(sizeof(linked_list_t));
    newNode->data = data;
    newNode->next = NULL;

    linked_list_t *iterator = head;
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    iterator->next = newNode;
}

void insert_front(linked_list_t *head, int data)
{
    linked_list_t *newNode = (linked_list_t *) malloc(sizeof(linked_list_t));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
}

void insert_at_index(linked_list_t *head, int data, int index)
{
    linked_list_t *newNode = (linked_list_t *) malloc((sizeof(linked_list_t)));
    newNode->data = data;

    linked_list_t *iterator = head;
    for (int i = 0; i < index; ++i) {
        iterator = iterator->next;
    }
    newNode->next = iterator;

    iterator = head;
    for (int j = 0; j < index - 1; ++j) {
        iterator = iterator->next;
    }
    iterator->next = newNode;
}

void print_list(linked_list_t *head)
{
    printf("0:\thead\n");
    int index = 1;
    linked_list_t *iterator = head;
    while (iterator->next != NULL) {
        printf("%d:\t%d\n", index, iterator->next->data);
        iterator = iterator->next;
        index++;
    }
}

int size_of_list(linked_list_t *head)
{
    int size = 0;
    linked_list_t *iterator = head;
    while (iterator->next != NULL) {
        iterator = iterator->next;
        size++;
    }
    return size;
}

int is_empty(linked_list_t *head)
{
    if (head->next == NULL)
        return 1;
    else
        return 0;
}

void delete_at_index(linked_list_t *head, int index)
{
    linked_list_t *iterator = head;
    for (int i = 0; i < index - 1; ++i) {
        iterator = iterator->next;
    }

    linked_list_t *deleted_item = iterator->next;
    iterator->next = iterator->next->next;

    free(deleted_item);
}

int delete_by_value(linked_list_t *head, int value)
{
    int deleted_nodes = 0;
    linked_list_t *iterator = head;
    while (iterator->next != NULL) {
        if (iterator->next->data == value) {
            linked_list_t *deleted_item = iterator->next;
            iterator->next = iterator->next->next;

            free(deleted_item);
            deleted_nodes++;
        }
        if(iterator->next != NULL)
            iterator = iterator->next;
    }
    return deleted_nodes;
}