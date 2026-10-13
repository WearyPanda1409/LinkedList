#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t size;
} List;
/*initialisiert liste*/
void list_init(List *list);

void list_push(List *list, int value);

void list_append(List *list, int value);

int list_pop(List *list, int *value);
int list_pop_back(List *list, int *value);
int list_insert(List *list, size_t index, int value);
int list_remove(List *list, size_t index, int *value);
int list_get(const List *list, size_t index, int *value);
size_t list_size(const List *list);
int list_is_empty(const List *list);
void list_clear(List *list);
void list_print(const List *list);

#endif