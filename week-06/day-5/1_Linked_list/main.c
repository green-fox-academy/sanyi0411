#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} node_t;

void insert_end(node_t *head, int data);

int main()
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    head->data = 0;
    head->next = NULL;

    insert_end(head, 3);
    printf("%d\n", head->next->data);

    return 0;
}

void insert_end(node_t *head, int data)
{
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;

    node_t *iterator = head;
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    iterator->next = newNode;
}
