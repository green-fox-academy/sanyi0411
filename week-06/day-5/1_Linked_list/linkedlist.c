//
// Created by sando on 2019. 05. 20..
//

#include "linkedlist.h"


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
    if (index <= 0) {
        printf("Index 0 is reserved for the head. You can insert at index 1 or higher!\n");
        return;
    }

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
    if (index <= 0) {
        printf("Index 0 is reserved for the head. You can delete at index 1 or higher!\n");
        return;
    }

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

linked_list_t *search_by_value(linked_list_t *head, int value)
{
    linked_list_t *result = NULL;
    linked_list_t *iterator = head;
    while (iterator->next != NULL) {
        if (iterator->data == value) {
            result = iterator;
        }

        if(iterator->next != NULL)
            iterator = iterator->next;
    }
    return result;
}