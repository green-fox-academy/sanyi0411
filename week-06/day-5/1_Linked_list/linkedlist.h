//
// Created by sando on 2019. 05. 20..
//

#ifndef INC_1_LINKED_LIST_LINKEDLIST_H
#define INC_1_LINKED_LIST_LINKEDLIST_H

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

linked_list_t *search_by_value(linked_list_t *head, int value);


#endif //INC_1_LINKED_LIST_LINKEDLIST_H
