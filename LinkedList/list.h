#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct Node {
    double value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    uint64_t size; ///____
} LinkedList;

/* Initialisiert eine leere Liste. */
void ll_init(LinkedList *list);
bool ll_push_front(LinkedList *list, double value);
bool ll_push_back(LinkedList *list, double value);
bool ll_remove(LinkedList *list, double value);
bool ll_contains(const LinkedList *list, double value);
void ll_print(const LinkedList *list);
uint64_t ll_size(const LinkedList *list);
bool ll_is_empty(const LinkedList *list);

void ll_clear(LinkedList *list);

#endif /* LINKED_LIST_H */