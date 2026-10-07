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

/* Liste initialisieren */
void list_init(List *list);

/* Element am Anfang hinzufügen */
void list_push(List *list, int value);

/* Element am Ende hinzufügen */
void list_append(List *list, int value);

/* Erstes Element entfernen und zurückgeben */
int list_pop(List *list, int *value);

/* Letztes Element entfernen und zurückgeben */
int list_pop_back(List *list, int *value);

/* Element an bestimmter Position einfügen */
int list_insert(List *list, size_t index, int value);

/* Element an bestimmter Position entfernen */
int list_remove(List *list, size_t index, int *value);

/* Element an bestimmter Position auslesen */
int list_get(const List *list, size_t index, int *value);

/* Anzahl der Elemente */
size_t list_size(const List *list);

/* Prüfen, ob die Liste leer ist */
int list_is_empty(const List *list);

/* Liste komplett leeren */
void list_clear(List *list);

/* Liste ausgeben */
void list_print(const List *list);

#endif