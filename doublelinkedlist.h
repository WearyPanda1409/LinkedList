//
// Created by elias on 13.10.2026.
//

#ifndef LINKEDLIST_DOUBLELINKEDLIST_H
#define LINKEDLIST_DOUBLELINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

void list_init(List *list);
void list_push(List *list, int value);
void list_append(List *list, int value);
int list_pop(List *list, int *value);
int list_pop_back(List *list, int *value);
void list_print(const List *list);
void list_clear(List);

#endif //LINKEDLIST_DOUBLELINKEDLIST_H
